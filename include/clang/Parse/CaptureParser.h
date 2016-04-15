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

#include "clang/Parse/CaptureNode.h"
#include "clang/Parse/Parser.h"

#include <map>
#include <string>

namespace clang {

class Sema;
class CaptureSema;

class CaptureParser : public Parser {
private:
  CaptureSema *CapSema;

public:
  CaptureParser(Preprocessor &PP, Sema &Actions, bool SkipFunctionBodies);

  StmtResult
  ParseStatementOrDeclaration(StmtVector &Stmts, AllowedContsructsKind Allowed,
                              SourceLocation *TrailingElseLoc = nullptr) override;


  ExprResult
  ParseExpression(TypeCastState isTypeCast = NotTypeCast) override;

  bool ParseTopLevelDecl(DeclGroupPtrTy &Result) override;

private:
  bool TryParseCapture(StringRef &name, Node::NodeType &ndType);

  StringRef ParseCaptureIdentifier();

  TypeResult ParseExprType();

  void ParseCaptureFormalArgument(FormalNode &Result);
  void ParseCaptureFormalArgs(FormalNodesTy &Formals);

  void ParseCaptureActualArgs(std::vector<Node> &result, const StringRef &name);

  bool TryParseCapture();

  Node::BaseNode *ExpandCaptured(StringRef &name, SourceLocation Loc);
};
}// end namespace clang

#endif
