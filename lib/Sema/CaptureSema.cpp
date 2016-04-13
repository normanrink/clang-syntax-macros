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
#include "clang/Parse/CaptureParser.h"
using namespace clang;
using namespace sema;

void
CaptureSema::PushCapEnv(std::vector<CaptureParser::FormalArgument> &formals) {
  CapSingleEnvTy env;
  for (auto f: formals) {
    if (env.count(f.Name)) {
      Diag(f.Loc, diag::err_multiple_formal) << f.Name;
      // ignore any multiple definitions:
      continue;
    }
    FormalCaptureNode fcn = { f.Loc, f.Type, GetTypeFromParser(f.TR.get()) };
    env[f.Name] = fcn;
  }
  CapEnvironment.push_front(env);
}

void
CaptureSema::PopCapEnv() {
   CapEnvironment.pop_front();
}

bool
CaptureSema::getCaptureNode(FormalCaptureNode &fcn, const StringRef &name) {
  for (auto env: CapEnvironment) {
    if (env.count(name)) {
      fcn = env[name];
      return true;
    }
  }
  return false;
}

bool
CaptureSema::getCaptureQualType(QualType &Type, const StringRef &name) {
  FormalCaptureNode fcn;
  bool result = getCaptureNode(fcn, name);
  if (result)
    Type = fcn.QT;

  return result;
}

bool
CaptureSema::getCaptureNodeType(CaptureParser::CapType &NodeType, const StringRef &name) {
  FormalCaptureNode fcn;
  bool result = getCaptureNode(fcn, name);
  if (result)
    NodeType = fcn.NodeType;

  return result;
}

void *
CaptureSema::ActOnCaptured(const StringRef &N, CaptureParser::CapType expected,
                           std::vector<void*> &ActualArgs, SourceLocation Loc) {
  if (!Captures.count(N)) {
    Diag(Loc, diag::err_capture_undefined) << N;
    return nullptr;
  }

  CapturedNode &cn = Captures[N];
  if (cn.Type != expected) {
    Diag(Loc, diag::err_wrong_node_type) << N
      << CaptureParser::CaptureTypeString(cn.Type)
      << CaptureParser::CaptureTypeString(expected);
    // plough on regardless of the AST node type mismatch
    // TODO: Is is sensible to plough on?
  }

  void *CapturedNode = cn.Node;

  std::map<StringRef, void*> ArgsMap;
  auto ActualsIt = ActualArgs.begin();
  for (auto f: cn.Formals)
    ArgsMap[f.Name] = *(ActualsIt++);

  switch (expected) {
    case CaptureParser::CAPTY_STMT:
      return (void*)TI.Instantiate((Stmt*)CapturedNode, ArgsMap);
    case CaptureParser::CAPTY_EXPR:
      return (void*)TI.Instantiate((Expr*)CapturedNode, ArgsMap);
    case CaptureParser::CAPTY_DECL:
      assert(0 && "not yet implemented");
    default:
      llvm_unreachable("Invalid capture type.");
  }
  return nullptr;
}

void *
CaptureSema::ActOnPlaceholder(const StringRef &N,
                              SourceLocation Loc,
                              CaptureParser::CapType NodeType) {

  CaptureParser::CapType storedType;
  bool exists = getCaptureNodeType(storedType, N);

  if (!exists) {
    Diag(Loc, diag::err_capture_undefined) << N;
    // plough on and create a "default" node (below)
  }
  if (storedType != NodeType) {
    Diag(Loc, diag::err_wrong_node_type) << N
      << CaptureParser::CaptureTypeString(storedType)
      << CaptureParser::CaptureTypeString(NodeType);
    // plough on regardless of the AST node type mismatch
    // TODO: Is is sensible to plough on?
  }

  switch(NodeType) {
    case CaptureParser::CAPTY_STMT:
      return CreateStmtPlaceholder(N, Loc, Loc).get();
    case CaptureParser::CAPTY_EXPR: {
      QualType QT;
      getCaptureQualType(QT, N);
      return CreateExprPlaceholder(N, QT, Loc, Loc).get();
    }
    default:
      assert(0 && "not yet implemented");
  }
}

void
CaptureSema::getFormalArgTypes(std::vector<CaptureParser::CapType> &NodeTypes,
                               const StringRef &N, SourceLocation Loc) {
  if (!Captures.count(N)) {
    Diag(Loc, diag::err_capture_undefined) << N;
    return;
  }

  for (auto f: Captures[N].Formals)
    NodeTypes.push_back(f.Type);
}

