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
#include <RAIIObjectsForParser.h>

#include "../lib/Sema/TreeTransform.h"

using namespace clang;


CaptureParser::CaptureParser(Preprocessor &pp, Sema &actions, bool skipFunctionBodies)
  : Parser(pp, actions, skipFunctionBodies) {}

template<typename parser>
bool
CaptureParser::TryParseCaptureHeader(CaptureHeader &Header, const StringRef &NodeKind,
                                     parser ReplacementParser) {
  assert(Tok.is(tok::l_square));

  Token Next = NextToken();
  if(Next.isNot(tok::identifier))
    assert(0 && "Expected identifier.");

  const StringRef &captureNode = Next.getIdentifierInfo()->getName();
  if (!captureNode.equals(NodeKind))
    return false; // Exit without consuming any tokens.

  BalancedDelimiterTracker BDT(*this, tok::l_square);
  BDT.consumeOpen(); // eat the '['
  ConsumeToken(); // eat the identifier

  Header.RK = RK_None;
  if (TryConsumeToken(tok::comma)) {
    if (Tok.is(tok::identifier)
        && Tok.getIdentifierInfo()->getName().equals("self")) {
      Header.RK = RK_Self;
      ConsumeToken(); // eat the identifier "self"
    } else {
      Header.RK = RK_Node;
      Header.Repl = ReplacementParser();
    }
  }

  BDT.consumeClose(); // eat the '['

  if(Next.isNot(tok::identifier))
    assert(0 && "Expected identifier.");
  Header.Name = ParseCaptureIdentifier();

  return true;
}

StringRef
CaptureParser::ParseCaptureIdentifier() {
  assert(Tok.is(tok::identifier));
  const StringRef &id = Tok.getIdentifierInfo()->getName();
  ConsumeToken(); // eat the identifier
  return id;
}

TypeResult
CaptureParser::ParseNodeType() {
  BalancedDelimiterTracker BDT(*this, tok::l_square);
  BDT.consumeOpen(); // eat the '['
  TypeResult TR = ParseTypeName();
  BDT.consumeClose(); // eat the ']'
  return TR;
}
template<typename S, typename T>
void
CaptureParser::ParseCaptureFormalArgs(std::vector<S> &formals, std::vector<T> &defaults,
                                      std::function<S()> SParser,
                                      std::function<T()> TParser,
                                      T Dummy) {
  if (Tok.is(tok::l_paren)) { // We have a parameter list.
    BalancedDelimiterTracker BDT(*this, tok::l_paren);
    BDT.consumeOpen(); // eat the '('

    while (!Tok.is(tok::r_paren)) {
      S s = SParser();
      formals.push_back(s);

      if (TryConsumeToken(tok::equal)) {
        T t = TParser();
        defaults.push_back(t);
      } else {
         defaults.push_back(Dummy);
      }

      if (Tok.is(tok::comma))
        ConsumeToken(); // eat the ','
    }
    assert(Tok.is(tok::r_paren));
    BDT.consumeClose(); // eat the ')'
  }
}

template<typename T>
void
CaptureParser::ParseCaptureActualArgs(std::vector<T> &result,
                                      std::function<T()> TParser) {
  if (Tok.is(tok::l_paren)) { // We have a parameter list.
    BalancedDelimiterTracker BDT(*this, tok::l_paren);
    BDT.consumeOpen(); // eat the '('

    while (!Tok.is(tok::r_paren)) {
      T t = TParser();
      result.push_back(t);

      if (Tok.is(tok::cash)) // use '$' to separate actual arguments
        ConsumeToken(); // eat the '$'
    }
    assert(Tok.is(tok::r_paren));
    BDT.consumeClose(); // eat the ')'
  }
}

template<typename T>
ActionResult<T*>
CaptureParser::ParseExpandingCapture(std::function<T*()> tParser) {
  StringRef id = ParseCaptureIdentifier();

  std::vector<T*> ActualArgs;
  ParseCaptureActualArgs(ActualArgs, tParser);

  return Actions.ActOnCaptured(id, ActualArgs);
}

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

StmtResult
CaptureParser::ParseStatementOrDeclaration(StmtVector &Stmts,
                                           AllowedContsructsKind Allowed,
                                           SourceLocation *TrailingElseLoc) {
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

ExprResult
CaptureParser::ParseExpression(TypeCastState isTypeCast) {
  std::function<Expr*()> ExprParser = [this] {
    ExprResult E = ParseExpression();
    return E.get();
  };

  if (Tok.is(tok::cash)) {
    // Expand into a captured subtree.
    ConsumeToken(); // eat the '$'

    return ParseExpandingCapture(ExprParser);
  } else if (Tok.is(tok::cashcashcash)) {
    // Parse a placeholder expression.
    SourceLocation SLoc = ConsumeToken(); // eat the '$$$'

    TypeResult TR = ParseNodeType();
    StringRef id = ParseCaptureIdentifier();

    return Actions.ActOnExprPlaceholder(id, TR.get(), SLoc, SLoc);
  } else if (Tok.is(tok::cashcash)) {
    // Try to capture an expression.
    ConsumeToken(); // eat the '$$'

    CaptureHeader Header;
    Header.RK = RK_Self; // Default to self replacement for expressions.
    if (!TryParseCaptureHeader(Header, "expr", ExprParser)) {
      Token CashCash;
      CashCash.setKind(tok::cashcash);
      UnconsumeToken(CashCash);
    } else {
      std::vector<StringRef> formalArgs;
      std::vector<Expr*> defaultArgs;
      ParseCaptureFormalArgs(formalArgs, defaultArgs,
                             StringParser, ExprParser, (Expr*)nullptr);

      ExprResult Expr = ParseExpression(isTypeCast);
      Actions.Capture(Header.Name, Expr.get(), formalArgs);

      assert(Header.RK != RK_None && "Cannot replace Expr with nothing.");
      if (Header.RK == RK_Self)
        return Actions.ActOnCaptured(Header.Name, defaultArgs);
      else if (Header.RK == RK_Node)
        return reinterpret_cast<clang::Expr*>(Header.Repl);
      else
        llvm_unreachable("Invalid replacement kind.");
    }
  }

  return Parser::ParseExpression(isTypeCast);
}


