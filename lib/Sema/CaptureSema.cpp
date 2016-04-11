//===--- CaptureSema.cpp - AST Builder and Semantic Analysis Implementation ------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the actions class which performs semantic analysis and
// builds an AST out of a parse stream.
//
//===----------------------------------------------------------------------===//

#include "clang/Sema/CaptureSema.h"
using namespace clang;
using namespace sema;

template<typename T>
ActionResult<T*>
CaptureSema::ActOnCapturedTree(std::pair<T*, std::vector<StringRef>> tree,
                               std::vector<T*> &ActualArgs) {
  assert(tree.first &&
         tree.second.size() == ActualArgs.size());

  std::map<StringRef, T*> ArgsMap;
  for (unsigned i = 0; i < ActualArgs.size(); i++)
    ArgsMap[tree.second[i]] = ActualArgs[i];

  ActionResult<T*> Res = TI.Instantiate(tree.first, ArgsMap);
  return Res;
}

StmtResult
CaptureSema::ActOnCaptured(const StringRef &N, std::vector<Stmt*> &ActualArgs) {
  CapturedStmtPairTy tree = CapturedStmts[N];

  Stmt *s = tree.first;
  std::vector<StringRef> formalNames;
  for (auto fi: tree.second)
    formalNames.push_back(fi.second);
  std::pair<Stmt*,std::vector<StringRef>> smallTree(s, formalNames);

  return ActOnCapturedTree(smallTree, ActualArgs);
}

ExprResult
CaptureSema::ActOnCaptured(const StringRef &N, std::vector<Expr*> &ActualArgs) {
  CapturedExprPairTy tree = CapturedExprs[N];
  return ActOnCapturedTree(tree, ActualArgs).get();
}
