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


Node::BaseNode *
CaptureSema::ActOnCaptured(const StringRef &name,
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

  std::map<StringRef, Node::BaseNode*> argsMap;
  auto actualsIt = actualArgs.begin();
  for (auto f: formals) {
    Node actual = *actualsIt;
    Node::BaseNode *actualASTNode = actual.getASTNode();
    assert(actualASTNode && "AST node broken");

    if (isa<StmtPlaceholder>(actualASTNode)
        || isa<ExprPlaceholder>(actualASTNode)) {
      // If the formal argument is a placeholder, we cannot use the 'actual.isa()' call
      // in the comparision of AST ndoe types. Instead, we must get the node type with
      // which the placeholder was defined in the header of an AST capture.
      StringRef name;
      if (StmtPlaceholder *sph = dyn_cast<StmtPlaceholder>(actualASTNode))
        name = sph->getName();
      else if (ExprPlaceholder *eph = dyn_cast<ExprPlaceholder>(actualASTNode))
        name = eph->getName();
      else
        assert(0 && "should not be here");

      FormalNode FormalForActual;

      bool exists = getCurScope()->getASTCapturedFormal(FormalForActual, name);
      if (!exists) {
        Diag(loc, diag::err_capture_undefined) << name;
        return nullptr;
      }

      if (FormalForActual.NdType != f.NdType) {
        Diag(actual.getLocation(), diag::err_wrong_node_type)
          << name
          << Node::getAsString(FormalForActual.NdType)
          << Node::getAsString(f.NdType);
        return nullptr;

      }
    } else if (!actual.isa(f.NdType)) {
      Diag(actual.getLocation(), diag::err_wrong_node_type) << f.Name
        << actual.getNodeTypeAsString()
        << Node::getAsString(f.NdType);
      return nullptr;
    }

    if (Node::isExpr(f.NdType)) {
      QualType formalCanType = f.getCanonicalType();
      QualType actualCanType = actual.getCanonicalExprType();
      if (formalCanType.getTypePtr() != actualCanType.getTypePtr()) {
        // TODO: Emit a proper error message.
        assert(0 && "type mismatch between formal and actual argument");
      }
    }

    argsMap[f.Name] = (actualsIt++)->getASTNode();
  }

  return TI.Instantiate(N.getASTNode(), argsMap);
}

Node::BaseNode *
CaptureSema::ActOnPlaceholder(const StringRef &name, SourceLocation loc) {
  FormalNode formal;
  bool exists = getCurScope()->getASTCapturedFormal(formal, name);

  if (!exists) {
    Diag(loc, diag::err_placeholder_undefined) << name;
    return nullptr;
  }

  assert((Node::isStmt(formal.NdType) || Node::isExpr(formal.NdType))
         && "unexpected AST node type");

  if (Node::isExpr(formal.NdType)) {
    return CreateExprPlaceholder(name, formal.QT, loc, loc).get();
  } else if (Node::isStmt(formal.NdType)) {
    return CreateStmtPlaceholder(name, loc, loc).get();
  } else {
    llvm_unreachable("we should not get here");
  }
}

