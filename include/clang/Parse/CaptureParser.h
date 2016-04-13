//===--- CaptureParser.h - C Language Parser ---------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//  This file defines the Parser interface.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_PARSE_CAPTURE_PARSER_H
#define LLVM_CLANG_PARSE_CAPTURE_PARSER_H

#include "clang/Parse/Parser.h"

#include <functional>

namespace clang {

class CaptureParser : public Parser {
public:
  /* 'ReplacementKind' has been removed. The semantics now are that no replacement
   * is done for catured trees/nodes. If the programmer wants the tree/node in his
   * program, (s)he will have to instantiate it.
   */

  enum CapType {
    CAPTY_STMT,
    CAPTY_EXPR,
    CAPTY_DECL,
    CAPTY_COUNT
  };

  static StringRef CaptureTypeString(CapType);
  static CapType CaptureType(const StringRef &);
  bool isCaptureType(const StringRef &);

  struct FormalArgument {
    SourceLocation Loc;
    // The name of this formal:
    StringRef Name;
    // The AST node type:
    CapType Type;
    // For 'expr' nodes, the type of the expression:
    TypeResult TR;
  };

 struct CaptureHeader {
    StringRef Name;
  };

public:
  CaptureParser(Preprocessor &PP, Sema &Actions, bool SkipFunctionBodies);

  StmtResult
  ParseStatementOrDeclaration(StmtVector &Stmts, AllowedContsructsKind Allowed,
                              SourceLocation *TrailingElseLoc = nullptr) override;


  ExprResult
  ParseExpression(TypeCastState isTypeCast = NotTypeCast) override;

  bool ParseTopLevelDecl(DeclGroupPtrTy &Result) override;

private:
  bool
  TryParseCaptureHeader(StringRef &name, CapType expected);

  StringRef ParseCaptureIdentifier();

  TypeResult ParseExprType();

  void ParseCaptureFormalArgument(FormalArgument &Result);
  void ParseCaptureFormalArgs(std::vector<FormalArgument> &Formals);

  void ParseCaptureActualArgs(std::vector<void*> &result, const StringRef &N);

  bool TryParseCapture();

  template<typename T>
  ActionResult<T*> ParseExpandingCapture(CaptureParser::CapType NodeType,
                                         SourceLocation Loc);

  /*
  StmtResult
  ParseExpandingStmtCapture(std::function<Stmt*()> StmtParser,
                            std::function<Expr*()> ExprParser);
                            */
};
}// end namespace clang

#endif
