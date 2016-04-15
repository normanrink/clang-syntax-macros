//===--- CaptureSema.h - Semantic Analysis & AST Building --------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the Sema class, which performs semantic analysis and
// builds ASTs.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_SEMA_CAPTURE_SEMA_H
#define LLVM_CLANG_SEMA_CAPTURE_SEMA_H

#include "clang/Parse/CaptureNode.h"
#include "clang/Sema/Sema.h"
#include "../lib/Sema/TreeInstantiator.h"

#include <list>
#include <map>
#include <vector>

namespace clang {

class CaptureSema : public Sema {
private:
  TreeInstantiator TI;

public:
  CaptureSema(Preprocessor &pp, ASTContext &ctxt, ASTConsumer &consumer,
              TranslationUnitKind TUKind = TU_Complete,
              CodeCompleteConsumer *CompletionConsumer = nullptr)
    : Sema (pp, ctxt, consumer, TUKind, CompletionConsumer),
      TI(*this) {}

  ~CaptureSema() {}

public:
  Node::BaseNode *
  ActOnCaptured(const StringRef &N, std::vector<Node> &actualArgs, SourceLocation loc);

  void Capture(const StringRef &name, const Node &astNode,
               const FormalNodesTy &formals) {
    getCurScope()->addASTCapturedTemplate(name, astNode, formals);
  }

  StmtResult CreateStmtPlaceholder(const StringRef &name,
                                   SourceLocation startLoc,
                                   SourceLocation endLoc) override {
    return new (Context) StmtPlaceholder(name, startLoc, endLoc);
  }
  ExprResult CreateExprPlaceholder(const StringRef &name,
                                   QualType QT,
                                   SourceLocation startLoc,
                                   SourceLocation endLoc)  override  {
    return new (Context) ExprPlaceholder(name, QT, startLoc, endLoc);
  }

  Node::BaseNode *ActOnPlaceholder(const StringRef &name, SourceLocation loc);

  QualType GetTypeFromParser(ParsedType Ty) {
    return Sema::GetTypeFromParser(Ty);
  }
};

} // end namespace clang

#endif
