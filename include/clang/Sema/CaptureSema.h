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

#include "clang/Sema/Sema.h"
#include "clang/Parse/CaptureParser.h"
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
  struct FormalCaptureNode {
    SourceLocation Loc;
    // The AST node type:
    CaptureParser::CapType NodeType;
    // For 'expr' nodes, the type of the expression:
    QualType QT;
  };

  typedef std::map<StringRef, FormalCaptureNode> CapSingleEnvTy;
  typedef std::list<CapSingleEnvTy> CapEnvTy;

  bool getCaptureQualType(QualType &Type, const StringRef &name);
  bool getCaptureNodeType(CaptureParser::CapType &NodeType, const StringRef &name);
  bool getCaptureNode(FormalCaptureNode &fcn, const StringRef &name);

  void PushCapEnv(std::vector<CaptureParser::FormalArgument> &formals);
  void PopCapEnv();

private:
  CapEnvTy CapEnvironment;

private:
  struct CapturedNode {
    SourceLocation Loc;
    CaptureParser::CapType Type;
    // YIKES: would be better without a 'void' pointer:
    void *Node;
    // formal arguments:
    std::vector<CaptureParser::FormalArgument> Formals;
  };

  typedef std::map<StringRef, CapturedNode> CapturesTy;

public:
  void
  getFormalArgTypes(std::vector<CaptureParser::CapType> &NodeTypes,
                    const StringRef &N, SourceLocation Loc);

private:
  CapturesTy Captures;

  template<typename T>
  ActionResult<T*>
  ActOnCapturedTree(std::pair<T*, std::vector<StringRef>> tree,
                    std::vector<T*> &ActualArgs);

public:
  void *
  ActOnCaptured(const StringRef &N, CaptureParser::CapType expected,
                std::vector<void*> &ActualArgs, SourceLocation Loc);

  void Capture(StringRef N, SourceLocation Loc,
               CaptureParser::CapType Type, void* ToCapture,
               std::vector<CaptureParser::FormalArgument> FormalArgs) {
    CapturedNode cap { Loc, Type, ToCapture, FormalArgs };
    Captures[N] = cap;
  }

  StmtResult CreateStmtPlaceholder(const StringRef &Name,
                                   SourceLocation startLoc,
                                   SourceLocation endLoc)  override {
    return new (Context) StmtPlaceholder(Name, startLoc, endLoc);
  }
  ExprResult CreateExprPlaceholder(const StringRef &Name,
                               QualType QT,
                               SourceLocation startLoc,
                               SourceLocation endLoc)  override {
    return new (Context) ExprPlaceholder(Name, QT, startLoc, endLoc);
  }

  void *ActOnPlaceholder(const StringRef &N,
                         SourceLocation Loc,
                         CaptureParser::CapType NodeType);
};

} // end namespace clang

#endif
