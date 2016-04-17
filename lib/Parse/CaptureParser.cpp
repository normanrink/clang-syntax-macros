//===--- CaptureParser.cpp - C Language Family Parser ----------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//  This file implements the Parser interfaces.
//
//===----------------------------------------------------------------------===//

#include "clang/Parse/CaptureParser.h"
#include "clang/Parse/CaptureNode.h"
#include "clang/Sema/CaptureSema.h"
#include <RAIIObjectsForParser.h>

#include "../lib/Sema/TreeTransform.h"

using namespace clang;

CaptureParser::CaptureParser(Preprocessor &pp, Sema &actions,
                                     bool skipFunctionBodies)
  // YIKES: The casting from 'Sema*' to 'CaptureSema*' is hacky, but this way
  // one does not need to change a whole lot of interfaces of classes,
  // constructors, and functions all over 'clang'.
  : Parser(pp, actions, skipFunctionBodies), CapSema((CaptureSema*)&actions) {}

bool
CaptureParser::TryParseCapture(StringRef &name, Node::NodeType &ndType) {
  assert(Tok.is(tok::l_square));

  Token Next = NextToken();
  if(Next.isNot(tok::identifier)) {
    Diag(Next.getLocation(), diag::err_expected_identifier);
    return false;
  }

  const StringRef &ndTypeName = Next.getIdentifierInfo()->getName();
  ndType = Node::getAsNodeType(ndTypeName);
  if (ndType == Node::ND_NoNode)
    return false; // Exit without consuming any tokens.

  BalancedDelimiterTracker BDT(*this, tok::l_square);
  BDT.consumeOpen(); // eat the '['
  ConsumeToken(); // eat the identifier
  BDT.consumeClose(); // eat the '['

  name = ParseCaptureIdentifier();
  if (name.empty())
    return false;

  return true;
}

StringRef
CaptureParser::ParseCaptureIdentifier() {
  if(Tok.isNot(tok::identifier)) {
    Diag(Tok.getLocation(), diag::err_expected_identifier);
    return StringRef();
  }
  const StringRef &id = Tok.getIdentifierInfo()->getName();
  ConsumeToken(); // eat the identifier
  return id;
}

TypeResult
CaptureParser::ParseExprType() {
  BalancedDelimiterTracker BDT(*this, tok::l_square);
  BDT.consumeOpen(); // eat the '['
  TypeResult TR = ParseTypeName();
  BDT.consumeClose(); // eat the ']'
  return TR;
}

void
CaptureParser::ParseCaptureFormalArgument(FormalNode &Result) {
  SourceLocation Loc = Tok.getLocation();

  StringRef ndTypeName = ParseCaptureIdentifier();
  if (!Node::isNodeType(ndTypeName)) {
    Diag(Loc, diag::err_expected_node_type) << ndTypeName;
    // Assume the formal argument is a 'Stmt':
    Result.NdType = Node::ND_Stmt;
  } else {
    Result.NdType = Node::getAsNodeType(ndTypeName);
  }

  Result.Loc = Loc;
  Result.NdType = Node::getAsNodeType(ndTypeName);
  assert((Node::isStmt(Result.NdType) || Node::isExpr(Result.NdType))
         && "unexpected AST node type");

  if (Node::isExpr(Result.NdType)) {
      Result.QT = CapSema->GetTypeFromParser(ParseExprType().get());
  }

  Result.Name = ParseCaptureIdentifier();
}

void
CaptureParser::ParseCaptureFormalArgs(FormalNodesTy &Formals) {
  if (Tok.is(tok::l_paren)) { // We have a parameter list.
    BalancedDelimiterTracker BDT(*this, tok::l_paren);
    BDT.consumeOpen(); // eat the '('

    while (!Tok.is(tok::r_paren)) {
      FormalNode f;
      ParseCaptureFormalArgument(f);
      Formals.push_back(f);

      // Formal arguments are separated by '$':
      if (Tok.is(tok::cash))
        ConsumeToken(); // eat the '$'
    }

    BDT.consumeClose(); // eat the ')'
  }
}

void
CaptureParser::ParseCaptureActualArgs(std::vector<Node> &result,
                                      const StringRef &name) {
  std::vector<Node::NodeType> formalNdTypes;
  // NOTE: Here we need context-sensitive information. We must ask the
  // semantic analysis for the AST node types of the formal arguments:
  getCurScope()->getASTCapturedFormalArgTypes(formalNdTypes, name);

  unsigned index = 0;
  if (Tok.is(tok::l_paren)) { // We have a parameter list.
    BalancedDelimiterTracker BDT(*this, tok::l_paren);
    BDT.consumeOpen(); // eat the '('

    while (!Tok.is(tok::r_paren)) {
      if (formalNdTypes.size() <= index)
        break;

      Node::NodeType ndType = formalNdTypes[index];
      assert((Node::isStmt(ndType) || Node::isExpr(ndType))
             && "unexpected AST node type");

      // NOTE: The order of the 'if' and 'else if' conditions is important since
      // every 'Expr' is also a 'Stmt'.
      if (Node::isExpr(ndType)) {
        Expr *expr = ParseExpression(MaybeTypeCast).get();
        // NOTE: This is not the prettiest solution:
        if (expr == nullptr)
          goto next_actual;

        Node N(expr, expr->getExprLoc(), Node::getNodeType(expr), expr->getType());
        result.push_back(N);
      } else if (Node::isStmt(ndType)) {
        StmtVector Stmts;
        Stmt *stmt = ParseStatementOrDeclaration(Stmts, ACK_Any).get();
        // NOTE: This is not the prettiest solution:
        if (stmt == nullptr)
          goto next_actual;

        Node N(stmt, stmt->getLocStart(), Node::getNodeType(stmt));
        result.push_back(N);
      } else {
        llvm_unreachable("we should not get here");
      }
      ++index;

next_actual:
      if (Tok.is(tok::cash)) // use '$' to separate actual arguments
        ConsumeToken(); // eat the '$'
    }
    BDT.consumeClose(); // eat the ')'
  }

  if (index != formalNdTypes.size()) {
    Diag(Tok.getLocation(), diag::err_number_of_actuals) << name
      << (unsigned)formalNdTypes.size()
      << index;
  }
}


Node::BaseNode*
CaptureParser::ExpandCaptured(StringRef &name, SourceLocation loc) {
  std::vector<Node> actualArgs;

  name = ParseCaptureIdentifier();
  ParseCaptureActualArgs(actualArgs, name);
  return CapSema->ActOnCaptured(name, actualArgs, loc);
}


StmtResult
CaptureParser::ParseStatementOrDeclaration(StmtVector &Stmts,
                                           AllowedContsructsKind Allowed,
                                           SourceLocation *TrailingElseLoc) {
  TryParseCapture();

  if (Tok.is(tok::cash)) {
    // Expand into a captured subtree.
    SourceLocation SLoc = ConsumeToken(); // eat the '$'
    StringRef name;
    Stmt *Res = dyn_cast_or_null<Stmt>(ExpandCaptured(name, SLoc));
    return StmtResult(Res);
  } else if (Tok.is(tok::cashcashcash)) {
    // Parse a placeholder statement.
    SourceLocation SLoc = ConsumeToken(); // eat the '$$$'
    StringRef name = ParseCaptureIdentifier();
    Stmt *Res = dyn_cast_or_null<Stmt>(CapSema->ActOnPlaceholder(name, SLoc));
    return StmtResult(Res);
  } else {
    return Parser::ParseStatementOrDeclaration(Stmts, Allowed, TrailingElseLoc);
  }
}

bool
CaptureParser::TryParseCapture() {
  std::function<Node::BaseNode *(QualType &)> ParseStmt = [this] (QualType &QT) {
    StmtVector stmts;
    StmtResult stmt = ParseStatementOrDeclaration(stmts, ACK_Any);
    return stmt.get();
  };
  std::function<Node::BaseNode *(QualType &)> ParseExpr = [this] (QualType &QT) {
    TryParseCapture();
    ExprResult expr = ParseExpression(MaybeTypeCast);
    QT = expr.get()->getType();
    return expr.get();
  };

  if (Tok.is(tok::cashcash)) {
    // Try to capture an AST subtree.
    SourceLocation SLoc = ConsumeToken(); // eat the '$$'

    StringRef name;
    Node::NodeType ndType;
    if (!TryParseCapture(name, ndType)) {
      Token CashCash;
      CashCash.setKind(tok::cashcash);
      UnconsumeToken(CashCash);
      return false;
    }

    assert((Node::isStmt(ndType) || Node::isExpr(ndType))
           && "unexpected AST node type");

    std::function<Node::BaseNode *(QualType &)> parser;
    if (Node::isExpr(ndType)) {
      parser = ParseExpr;
    } else if (Node::isStmt(ndType)) {
      parser = ParseStmt;
    } else {
       llvm_unreachable("should not be here");
    }

    FormalNodesTy formalArgs;
    ParseCaptureFormalArgs(formalArgs);

    {
      QualType QT;

      EnterScope(Scope::ASTCaptureScope);
      getCurScope()->addASTCaptureFormals(formalArgs);

      Node N(parser(QT), SLoc, ndType, QT);

      ExitScope();

      // NOTE: The call to 'Capture' must happen after we have exited
      // the scope used for parsing the AST capture. This ensures that
      // the parsed capture is visible in the current scope.
      CapSema->Capture(name, N, formalArgs);
    }

    return true;
  }

  return false;
}

bool
CaptureParser::ParseTopLevelDecl(DeclGroupPtrTy &Result) {
  TryParseCapture();
  return Parser::ParseTopLevelDecl(Result);
}

ExprResult
CaptureParser::ParseExpression(TypeCastState isTypeCast) {
  if (Tok.is(tok::cash)) {
    // Expand into a captured subtree.
    SourceLocation SLoc = ConsumeToken(); // eat the '$'
    StringRef name;
    Expr *Res = dyn_cast_or_null<Expr>(ExpandCaptured(name, SLoc));
    return ExprResult(Res);
  } else if (Tok.is(tok::cashcashcash)) {
    // Parse a placeholder expression.
    SourceLocation SLoc = ConsumeToken(); // eat the '$$$'
    StringRef name = ParseCaptureIdentifier();
    Expr *Res = dyn_cast_or_null<Expr>(CapSema->ActOnPlaceholder(name, SLoc));
    return ExprResult(Res);
  } else {
    return Parser::ParseExpression(isTypeCast);
  }
}

