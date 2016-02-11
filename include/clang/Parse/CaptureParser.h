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
  enum ReplacementKind {
    RK_None,
    RK_Self,
    RK_Node
  };

 struct CaptureHeader {
    ReplacementKind RK;
    Stmt *Repl;
    StringRef Name;
  };

public:
  CaptureParser(Preprocessor &PP, Sema &Actions, bool SkipFunctionBodies);

  StmtResult
  ParseStatementOrDeclaration(StmtVector &Stmts, AllowedContsructsKind Allowed,
                              SourceLocation *TrailingElseLoc = nullptr) override;

  ExprResult
  ParseExpression(TypeCastState isTypeCast = NotTypeCast) override;

private:
  template <typename parser>
  bool
  TryParseCaptureHeader(CaptureHeader &CH, const StringRef &kind,
                        parser ReplacementParser);

  const StringRef& ParseCaptureIdentifier();

  TypeResult ParseNodeType();

  template<typename S, typename T>
  void ParseCaptureFormalArgs(std::vector<S> &formals, std::vector<T> &defaults,
                              std::function<S()> SParser,
                              std::function<T()> TParser,
                              T Dummy);
  template<typename T>
  void ParseCaptureActualArgs(std::vector<T> &result, std::function<T()> TParser);

  template<typename T>
    ActionResult<T*> ParseExpandingCapture(std::function<T*()> tParser);

  const std::function<StringRef()> StringParser = [this] {
    return ParseCaptureIdentifier();
  };
};
}// end namespace clang

#endif
