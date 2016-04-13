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
  : Parser(pp, actions, skipFunctionBodies), CapSema((CaptureSema*)&actions) {}

bool
CaptureParser::TryParseCapture(StringRef &name, Node::NodeType expected) {
  assert(Tok.is(tok::l_square));

  Token Next = NextToken();
  if(Next.isNot(tok::identifier)) {
    Diag(Next.getLocation(), diag::err_expected_identifier);
    return false;
  }

  const StringRef &ndTypeName = Next.getIdentifierInfo()->getName();
  if (!ndTypeName.equals(Node::getAsString(expected)))
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
    // TODO: What?
  }

  Result.Loc = Loc;
  Result.NdType = Node::getAsNodeType(ndTypeName);
  switch(Result.NdType) {
    case Node::ND_STMT:
      break;
    case Node::ND_EXPR:
      Result.TR = ParseExprType();
      break;
    case Node::ND_DECL:
      assert(0 && "'decl' not implemented yet");
      break;
    default:
      llvm_unreachable("Invalid capture type.");
      break;
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
        ConsumeToken(); // eat the $,'
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
  CapSema->getFormalArgTypes(formalNdTypes, name, Tok.getLocation());

  unsigned index = 0;
  if (Tok.is(tok::l_paren)) { // We have a parameter list.
    BalancedDelimiterTracker BDT(*this, tok::l_paren);
    BDT.consumeOpen(); // eat the '('

    while (!Tok.is(tok::r_paren)) {
      if (formalNdTypes.size() <= index)
        break;

      switch (formalNdTypes[index]) {
        case Node::ND_STMT: {
          StmtVector Stmts;
          Stmt *stmt = ParseStatementOrDeclaration(Stmts, ACK_Any).get();
          Node N(stmt, stmt->getLocStart(), Node::ND_STMT);
          result.push_back(N);
          break;
        }
        case Node::ND_EXPR: {
          Expr *expr = ParseExpression(MaybeTypeCast).get();
          Node N(expr, expr->getExprLoc(), Node::ND_EXPR, expr->getType());
          result.push_back(N);
          break;
        }
        default:
          assert(0 && "not yet implemented");
          break;
      }
      ++index;

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


template<typename T>
ActionResult<T*>
CaptureParser::ExpandCaptured(Node::NodeType ndType,
                              SourceLocation loc) {
  std::vector<Node> actualArgs;

  StringRef name = ParseCaptureIdentifier();
  ParseCaptureActualArgs(actualArgs, name);
  T *Res = (T*)CapSema->ActOnCaptured(name, ndType, actualArgs, loc);
  return ActionResult<T*>(Res);
}


StmtResult
CaptureParser::ParseStatementOrDeclaration(StmtVector &Stmts,
                                           AllowedContsructsKind Allowed,
                                           SourceLocation *TrailingElseLoc) {
  TryParseCapture();

  if (Tok.is(tok::cash)) {
    // Expand into a captured subtree.
    ConsumeToken(); // eat the '$'
    return ExpandCaptured<Stmt>(Node::ND_STMT, Tok.getLocation());
  } else if (Tok.is(tok::cashcashcash)) {
    // Parse a placeholder statement.
    SourceLocation SLoc = ConsumeToken(); // eat the '$$$'
    StringRef name = ParseCaptureIdentifier();
    return (Expr*)CapSema->ActOnPlaceholder(name, SLoc, Node::ND_STMT);
  } else {
    return Parser::ParseStatementOrDeclaration(Stmts, Allowed, TrailingElseLoc);
  }
}

bool
CaptureParser::TryParseCapture() {
  std::function<void *(QualType &)> ParseStmt = [this] (QualType &QT) {
    StmtVector stmts;
    StmtResult stmt = ParseStatementOrDeclaration(stmts, ACK_Any);
    return (void*)stmt.get();
  };
  std::function<void *(QualType &)> ParseExpr = [this] (QualType &QT) {
    ExprResult expr = ParseExpression(MaybeTypeCast);
    QT = expr.get()->getType();
    return (void*)expr.get();
  };

  if (Tok.is(tok::cashcash)) {
    // Try to capture an expression.
    SourceLocation SLoc = ConsumeToken(); // eat the '$$'

    StringRef name;
    Node::NodeType ndType;
    std::function<void *(QualType &)> parser;
    if (TryParseCapture(name, Node::ND_EXPR)) {
      ndType = Node::ND_EXPR;
      parser = ParseExpr;
    } else if (TryParseCapture(name, Node::ND_STMT)) {
      ndType = Node::ND_STMT;
      parser = ParseStmt;
    } else {
      Token CashCash;
      CashCash.setKind(tok::cashcash);
      UnconsumeToken(CashCash);
      return false;
    }

    FormalNodesTy formalArgs;
    ParseCaptureFormalArgs(formalArgs);

    CapSema->PushCapEnv(formalArgs);
    QualType QT;
    Node N(parser(QT), SLoc, ndType, QT);
    CapSema->PopCapEnv();

    CapSema->Capture(name, N, formalArgs);
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
    ConsumeToken(); // eat the '$'
    return ExpandCaptured<Expr>(Node::ND_EXPR, Tok.getLocation());
  } else if (Tok.is(tok::cashcashcash)) {
    // Parse a placeholder expression.
    SourceLocation SLoc = ConsumeToken(); // eat the '$$$'
    StringRef name = ParseCaptureIdentifier();
    return (Expr*)CapSema->ActOnPlaceholder(name, SLoc, Node::ND_EXPR);
  } else {
    return Parser::ParseExpression(isTypeCast);
  }
}

