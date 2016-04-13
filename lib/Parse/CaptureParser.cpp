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
#include "clang/Sema/CaptureSema.h"
#include <RAIIObjectsForParser.h>

#include "../lib/Sema/TreeTransform.h"

using namespace clang;


CaptureParser::CaptureParser(Preprocessor &pp, Sema &actions, bool skipFunctionBodies)
  : Parser(pp, actions, skipFunctionBodies) {}

bool
CaptureParser::TryParseCaptureHeader(StringRef &name, CapType expected) {
  assert(Tok.is(tok::l_square));

  Token Next = NextToken();
  if(Next.isNot(tok::identifier)) {
    Diag(Next.getLocation(), diag::err_expected_identifier);
    return false;
  }

  const StringRef &captureTypeName = Next.getIdentifierInfo()->getName();
  if (!captureTypeName.equals(CaptureTypeString(expected)))
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
CaptureParser::ParseCaptureFormalArgument(FormalArgument &Result) {
  SourceLocation Loc = Tok.getLocation();
  StringRef typeName = ParseCaptureIdentifier();
  if (!isCaptureType(typeName)) {
    Diag(Loc, diag::err_expected_node_type) << typeName;
    // TODO: What?
  }

  Result.Type = CaptureType(typeName);
  switch(Result.Type) {
    case CAPTY_STMT:
      break;
    case CAPTY_EXPR:
      Result.TR = ParseExprType();
      break;
    case CAPTY_DECL:
      assert(0 && "'decl' not implemented yet");
      break;
    default:
      llvm_unreachable("Invalid capture type.");
      break;
  }

  Result.Name = ParseCaptureIdentifier();
}

void
CaptureParser::ParseCaptureFormalArgs(std::vector<FormalArgument> &Formals) {
  if (Tok.is(tok::l_paren)) { // We have a parameter list.
    BalancedDelimiterTracker BDT(*this, tok::l_paren);
    BDT.consumeOpen(); // eat the '('

    while (!Tok.is(tok::r_paren)) {
      FormalArgument f;
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
CaptureParser::ParseCaptureActualArgs(std::vector<void*> &result,
                                      const StringRef &N) {
  CaptureSema *CapSema = (CaptureSema*)(&Actions);
  std::vector<CapType> formalTypes;
  CapSema->getFormalArgTypes(formalTypes, N, Tok.getLocation());

  unsigned index = 0;
  if (Tok.is(tok::l_paren)) { // We have a parameter list.
    BalancedDelimiterTracker BDT(*this, tok::l_paren);
    BDT.consumeOpen(); // eat the '('

    while (!Tok.is(tok::r_paren)) {
      if (formalTypes.size() <= index)
        break;

      switch (formalTypes[index]) {
        case CAPTY_STMT: {
          StmtVector Stmts;
          StmtResult Stmt = ParseStatementOrDeclaration(Stmts, ACK_Any);
          result.push_back(Stmt.get());
          break;
        }
        case CAPTY_EXPR: {
          ExprResult expr = ParseExpression(MaybeTypeCast);
          result.push_back(expr.get());
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

  if (index != formalTypes.size()) {
    Diag(Tok.getLocation(), diag::err_number_of_actuals) << N
      << (unsigned)formalTypes.size()
      << index;
  }
}


template<typename T>
ActionResult<T*>
CaptureParser::ParseExpandingCapture(CaptureParser::CapType NodeType,
                                     SourceLocation Loc) {
  CaptureSema *CapSema = (CaptureSema*)(&Actions);
  std::vector<void*> ActualArgs;

  StringRef name = ParseCaptureIdentifier();
  ParseCaptureActualArgs(ActualArgs, name);
  T *Res = (T*)CapSema->ActOnCaptured(name, NodeType, ActualArgs, Loc);
  return ActionResult<T*>(Res);
}

/*
StmtResult
CaptureParser::ParseExpandingStmtCapture(std::function<Stmt*()> StmtParser,
                                         std::function<Expr*()> ExprParser) {
  StringRef id = ParseCaptureIdentifier();

  const std::vector<std::pair<StringRef, StringRef>> &formals =
    Actions.getStmtFormalArgs(id);

  std::vector<Stmt*> ActualArgs; // rely on the fact that every 'Expr' is also a 'Stmt'

  if (Tok.is(tok::l_paren)) { // We have a parameter list.
    BalancedDelimiterTracker BDT(*this, tok::l_paren);
    BDT.consumeOpen(); // eat the '('

    unsigned index = 0;
    while (!Tok.is(tok::r_paren)) {
      if (formals[index].first.equals("stmt")) {
        Stmt *s = StmtParser();
        ActualArgs.push_back(s);
      } else if (formals[index].first.equals("expr")) {
        Expr *e = ExprParser();
        ActualArgs.push_back(e);
      } else {
        assert(0 && "unexpected node type");
      }
      ++index;

      if (Tok.is(tok::cash)) // use '$' to separate actual arguments
        ConsumeToken(); // eat the '$'
    }
    assert(Tok.is(tok::r_paren));
    BDT.consumeClose(); // eat the ')'
  } else {
     assert(!formals.size() && "parameter list missing");
  }

  return Actions.ActOnCaptured(id, ActualArgs);
}
*/

StmtResult
CaptureParser::ParseStatementOrDeclaration(StmtVector &Stmts,
                                           AllowedContsructsKind Allowed,
                                           SourceLocation *TrailingElseLoc) {
  TryParseCapture();

  CaptureSema *CapSema = (CaptureSema*)(&Actions);
  if (Tok.is(tok::cash)) {
    // Expand into a captured subtree.
    ConsumeToken(); // eat the '$'
    return ParseExpandingCapture<Stmt>(CAPTY_STMT, Tok.getLocation());
  } else if (Tok.is(tok::cashcashcash)) {
    // Parse a placeholder statement.
    SourceLocation SLoc = ConsumeToken(); // eat the '$$$'
    StringRef id = ParseCaptureIdentifier();
    return (Expr*)CapSema->ActOnPlaceholder(id, SLoc, CAPTY_STMT);
  } else {
    return Parser::ParseStatementOrDeclaration(Stmts, Allowed, TrailingElseLoc);
  }
}
  /*
  std::function<Stmt*()> StmtParser = [this, Allowed, TrailingElseLoc] {
  StmtVector Stmts;
  StmtResult S =
    ParseStatementOrDeclaration(Stmts, Allowed, TrailingElseLoc);
  return S.get();
  };
  std::function<Expr*()> ExprParser = [this] {
    ExprResult E = ParseExpression();
    return E.get();
  };

  if (Tok.is(tok::cash)) {
    // Expand into a captured subtree.
    ConsumeToken(); // eat the '$'

    return ParseExpandingStmtCapture(StmtParser, ExprParser);
  } else if (Tok.is(tok::cashcashcash)) {
    // Parse a placeholder statement.
    SourceLocation SLoc = ConsumeToken();

    StringRef id = ParseCaptureIdentifier();

    return Actions.ActOnStmtPlaceholder(id, SLoc, SLoc);
  } else if (Tok.is(tok::cashcash)) {
    // Try to capture a statement.
    ConsumeToken(); // eat the '$$'

    CaptureHeader Header;
    Header.RK = RK_None; // Default to no replacement for statements.
    if (!TryParseCaptureHeader(Header, "stmt", StmtParser)) {
      Token CashCash;
      CashCash.setKind(tok::cashcash);
      UnconsumeToken(CashCash);
    } else {
      std::vector<std::pair<StringRef, StringRef>> formalArgs;
      std::vector<Stmt*> defaultArgs;
      ParseCaptureFormalArgs(formalArgs, defaultArgs,
                             PairParser, StmtParser, (Stmt*)nullptr);

      StmtResult Stmt = ParseStatementOrDeclaration(Stmts,
                                                    Allowed,
                                                    TrailingElseLoc);
      Actions.Capture(Header.Name, Stmt.get(), formalArgs);

      if (Header.RK == RK_None)
        return Actions.ActOnNullStmt(Stmt.get()->getLocEnd());
      else if (Header.RK == RK_Self)
        return Actions.ActOnCaptured(Header.Name, defaultArgs);
      else if (Header.RK == RK_Node)
        return Header.Repl;
      else
        llvm_unreachable("Invalid replacement kind.");
    }
  }

  return Parser::ParseStatementOrDeclaration(Stmts,
                                             Allowed,
                                             TrailingElseLoc);
}
*/

bool
CaptureParser::TryParseCapture() {
  std::function<void *()> ParseStmt = [this] {
    StmtVector stmts;
    StmtResult stmt = ParseStatementOrDeclaration(stmts, ACK_Any);
    return (void*)stmt.get();
  };
  std::function<void *()> ParseExpr = [this] {
    ExprResult expr = ParseExpression(MaybeTypeCast);
    return (void*)expr.get();
  };

  if (Tok.is(tok::cashcash)) {
    // Try to capture an expression.
    SourceLocation SLoc = ConsumeToken(); // eat the '$$'

    StringRef Name;
    CapType capType;
    std::function<void *()> parser;
    if (TryParseCaptureHeader(Name, CAPTY_EXPR)) {
      capType = CAPTY_EXPR;
      parser = ParseExpr;
    } else if (TryParseCaptureHeader(Name, CAPTY_STMT)) {
      capType = CAPTY_STMT;
      parser = ParseStmt;
    } else {
      Token CashCash;
      CashCash.setKind(tok::cashcash);
      UnconsumeToken(CashCash);
      return false;
    }

    std::vector<FormalArgument> formalArgs;
    ParseCaptureFormalArgs(formalArgs);

    CaptureSema *CapSema = (CaptureSema*)(&Actions);
    CapSema->PushCapEnv(formalArgs);
    void *node = parser();
    CapSema->PopCapEnv();

    CapSema->Capture(Name, SLoc, capType, node, formalArgs);
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
  CaptureSema *CapSema = (CaptureSema*)(&Actions);

  if (Tok.is(tok::cash)) {
    // Expand into a captured subtree.
    ConsumeToken(); // eat the '$'
    return ParseExpandingCapture<Expr>(CAPTY_EXPR, Tok.getLocation());
  } else if (Tok.is(tok::cashcashcash)) {
    // Parse a placeholder expression.
    SourceLocation SLoc = ConsumeToken(); // eat the '$$$'
    StringRef id = ParseCaptureIdentifier();
    return (Expr*)CapSema->ActOnPlaceholder(id, SLoc, CAPTY_EXPR);
  } else {
    return Parser::ParseExpression(isTypeCast);
  }
}

StringRef
CaptureParser::CaptureTypeString(CapType ct) {
  switch(ct) {
    case CAPTY_STMT: return StringRef("stmt");
    case CAPTY_EXPR: return StringRef("expr");
    case CAPTY_DECL: return StringRef("decl");
    default:
      llvm_unreachable("Invalid capture type.");
  }
  return StringRef();
}

CaptureParser::CapType
CaptureParser::CaptureType(const StringRef &s) {
   if (s.equals("stmt"))
     return CAPTY_STMT;
   else if (s.equals("expr"))
     return CAPTY_EXPR;
   else if (s.equals("decl"))
     return CAPTY_DECL;
   else
    llvm_unreachable("String does not name a capture type.");
}

bool
CaptureParser::isCaptureType(const StringRef &s) {
   if (s.equals("stmt"))
     return true;
   else if (s.equals("expr"))
     return true;
   else if (s.equals("decl"))
     return true;
   else
     return false;
}
