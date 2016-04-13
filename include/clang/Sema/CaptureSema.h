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

  typedef std::map<StringRef, FormalNode> CapFrameTy;
  typedef std::list<CapFrameTy> CapEnvTy;

  bool getFormalNode(FormalNode &res, const StringRef &name);

  void PushCapEnv(FormalNodesTy &formals);
  void PopCapEnv();

private:
  CapEnvTy CapEnvironment;

private:
  struct CapturedNode {
    Node N;
    FormalNodesTy FormalArgs;
  };

  typedef std::map<StringRef, CapturedNode> CapturesTy;

public:
  void getFormalArgTypes(std::vector<Node::NodeType> &result,
                         const StringRef &name, SourceLocation loc);

private:
  CapturesTy Captures;

  template<typename T>
  ActionResult<T*>
  ActOnCapturedTree(std::pair<T*, std::vector<StringRef>> tree,
                    std::vector<T*> &ActualArgs);

public:
  void *
  ActOnCaptured(const StringRef &N, Node::NodeType expected,
                std::vector<Node> &actualArgs, SourceLocation loc);

  void Capture(StringRef name, Node astNode,
               FormalNodesTy &formals) {
    CapturedNode cn = { astNode, formals };
    Captures[name] = cn;
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

  void *ActOnPlaceholder(const StringRef &name,
                         SourceLocation loc,
                         Node::NodeType ndType);
};

} // end namespace clang

#endif
