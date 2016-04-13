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

#include "clang/Parse/CaptureNode.h"
#include "clang/Sema/CaptureSema.h"

using namespace clang;
using namespace sema;

void
CaptureSema::PushCapEnv(FormalNodesTy &formals) {
  CapFrameTy frame;
  for (auto f: formals) {
    if (frame.count(f.Name)) {
      Diag(f.Loc, diag::err_multiple_formal) << f.Name;
      // ignore any multiple definitions:
      continue;
    }
    frame[f.Name] = f;
  }
  CapEnvironment.push_front(frame);
}

void
CaptureSema::PopCapEnv() {
   CapEnvironment.pop_front();
}

bool
CaptureSema::getFormalNode(FormalNode &res, const StringRef &name) {
  for (auto env: CapEnvironment) {
    if (env.count(name)) {
      res = env[name];
      return true;
    }
  }
  return false;
}

void *
CaptureSema::ActOnCaptured(const StringRef &name, Node::NodeType expected,
                           std::vector<Node> &actualArgs, SourceLocation loc) {
  if (!Captures.count(name)) {
    Diag(loc, diag::err_capture_undefined) << name;
    return nullptr;
  }

  Node N = Captures[name].N;
  FormalNodesTy &formals = Captures[name].FormalArgs;

  if (N.getNodeType() != expected) {
    Diag(loc, diag::err_wrong_node_type) << name
      << N.getNodeTypeAsString()
      << Node::getAsString(expected);
    // plough on regardless of the AST node type mismatch
    // TODO: Is is sensible to plough on?
  }

  std::map<StringRef, void*> argsMap;
  auto actualsIt = actualArgs.begin();
  for (auto f: formals)
    argsMap[f.Name] = (actualsIt++)->getASTNode();

  switch (expected) {
    case Node::ND_STMT:
      return (void*)TI.Instantiate((Stmt*)N.getASTNode(), argsMap);
    case Node::ND_EXPR:
      return (void*)TI.Instantiate((Expr*)N.getASTNode(), argsMap);
    case Node::ND_DECL:
      assert(0 && "not yet implemented");
    default:
      llvm_unreachable("Invalid capture type.");
  }
  return nullptr;
}

void *
CaptureSema::ActOnPlaceholder(const StringRef &name,
                              SourceLocation loc,
                              Node::NodeType ndType) {

  FormalNode formal;
  bool exists = getFormalNode(formal, name);

  if (!exists) {
    Diag(loc, diag::err_capture_undefined) << name;
    // plough on and create a "default" node (below)
  }
  if (formal.NdType != ndType) {
    Diag(loc, diag::err_wrong_node_type) << name
      << Node::getAsString(formal.NdType)
      << Node::getAsString(ndType);
    // plough on regardless of the AST node type mismatch
    // TODO: Is is sensible to plough on?
  }

  switch(ndType) {
    case Node::ND_STMT:
      return CreateStmtPlaceholder(name, loc, loc).get();
    case Node::ND_EXPR: {
      QualType QT = GetTypeFromParser(formal.TR.get());
      return CreateExprPlaceholder(name, QT, loc, loc).get();
    }
    default:
      assert(0 && "not yet implemented");
  }
}

void
CaptureSema::getFormalArgTypes(std::vector<Node::NodeType> &result,
                               const StringRef &name, SourceLocation loc) {
  if (!Captures.count(name)) {
    Diag(loc, diag::err_capture_undefined) << name;
    return;
  }

  for (auto f: Captures[name].FormalArgs)
    result.push_back(f.NdType);
}

