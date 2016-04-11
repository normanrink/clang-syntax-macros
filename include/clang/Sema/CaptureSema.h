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
#include "../lib/Sema/TreeInstantiator.h"

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

  typedef std::pair<Stmt*, std::vector<std::pair<StringRef, StringRef>>> CapturedStmtPairTy;
  typedef std::map<const std::string, CapturedStmtPairTy> CapturedStmtTy;
  typedef std::pair<Expr*, std::vector<StringRef>> CapturedExprPairTy;
  typedef std::map<const std::string, CapturedExprPairTy> CapturedExprTy;

private:
  CapturedStmtTy CapturedStmts;
  CapturedExprTy CapturedExprs;

  template<typename T>
  ActionResult<T*>
  ActOnCapturedTree(std::pair<T*, std::vector<StringRef>> tree,
                    std::vector<T*> &ActualArgs);

public:
  StmtResult ActOnCaptured(const StringRef &N,
                           std::vector<Stmt*> &ActualArgs) override;
  ExprResult ActOnCaptured(const StringRef &N,
                           std::vector<Expr*> &ActualArgs) override;

  void Capture(StringRef N, Stmt* ToCapture,
               std::vector<std::pair<StringRef, StringRef>> FormalArgs) override {
    CapturedStmts[N.str()] = CapturedStmtPairTy(ToCapture, FormalArgs);
  }
  void Capture(StringRef N, Expr* ToCapture,
               std::vector<StringRef> FormalArgs) override {
    CapturedExprs[N.str()] = CapturedExprPairTy(ToCapture, FormalArgs);
  }

  const std::vector<std::pair<StringRef, StringRef>>
  getStmtFormalArgs(StringRef N) override {
    return CapturedStmts[N.str()].second;
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

  StmtResult ActOnStmtPlaceholder(const StringRef &N,
                                  SourceLocation startLoc,
                                  SourceLocation endLoc) override {
    return CreateStmtPlaceholder(N, startLoc, endLoc);
  }
  ExprResult ActOnExprPlaceholder(const StringRef &N,
                                  ParsedType PTy,
                                  SourceLocation startLoc,
                                  SourceLocation endLoc) override {
    return CreateExprPlaceholder(N, GetTypeFromParser(PTy), startLoc, endLoc);
  }
};

} // end namespace clang

#endif
