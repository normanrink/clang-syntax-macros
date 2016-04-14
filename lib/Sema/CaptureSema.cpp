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


void *
CaptureSema::ActOnCaptured(const StringRef &name, Node::NodeType expected,
                           std::vector<Node> &actualArgs, SourceLocation loc) {
  Node N;
  FormalNodesTy formals;

  bool exists = getCurScope()->getASTCapturedNode(N, name);
  if (!exists) {
    Diag(loc, diag::err_capture_undefined) << name;
    return nullptr;
  }

  exists = getCurScope()->getASTCapturedFormalArgs(formals, name);
  assert(exists && "scope is broken");

  if (N.getNodeType() != expected) {
    Diag(loc, diag::err_wrong_node_type) << name
      << N.getNodeTypeAsString()
      << Node::getAsString(expected);
    // plough on regardless of the AST node type mismatch
    // TODO: Is is sensible to plough on?
  }

  std::map<StringRef, void*> argsMap;
  auto actualsIt = actualArgs.begin();
  for (auto f: formals) {
    // This has already been checked by the parser, namely when the parser selected
    // whether the capture is to be parsed as a 'stmt' or 'expr':
    assert(f.NdType == actualsIt->getNodeType());
    if (f.NdType == Node::ND_EXPR) {
      QualType formalCanType = f.getCanonicalType();
      QualType actualCanType = actualsIt->getCanonicalExprType();
      if (formalCanType.getTypePtr() != actualCanType.getTypePtr()) {
        // TODO: Emit a proper error message.
         assert(0 && "type mismatch between formal and actual argument");
      }
    }
    argsMap[f.Name] = (actualsIt++)->getASTNode();
  }

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
  bool exists = getCurScope()->getASTCapturedFormal(formal, name);

  if (!exists) {
    Diag(loc, diag::err_placeholder_undefined) << name;
    return nullptr;
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
    case Node::ND_EXPR:
      return CreateExprPlaceholder(name, formal.QT, loc, loc).get();
    default:
      assert(0 && "not yet implemented");
  }
}

