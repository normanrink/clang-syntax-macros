//===--- NodeCaptureParser.cpp - C Language Family Parser ----------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//  This file implements the Parser interfaces.
//
//===----------------------------------------------------------------------===//

#include "clang/AST/Expr.h"
#include "clang/AST/ExprCXX.h"
#include "clang/AST/ExprObjC.h"
#include "clang/AST/ExprOpenMP.h"
#include "clang/AST/Stmt.h"
#include "clang/AST/StmtCXX.h"
#include "clang/AST/StmtObjC.h"
#include "clang/AST/StmtOpenMP.h"
#include "clang/Parse/CaptureNode.h"

#include "llvm/Support/Casting.h"

using namespace clang;

const std::map<const std::string, const Node::NodeType> Node::StringsToTypes = {
    {"Stmt", ND_Stmt},
    {"Expr", ND_Expr},
#define ABSTRACT_STMT(STMT)
#define STMT(Node, Parent) \
    {#Node, ND_##Node},
#include "clang/AST/StmtNodes.inc"
  };

const std::map<const Node::NodeType, const std::string> Node::TypesToStrings = {
    {ND_Stmt, "Stmt"},
    {ND_Expr, "Expr"},
#define ABSTRACT_STMT(STMT)
#define STMT(Node, Parent) \
    {ND_##Node, #Node},
#include "clang/AST/StmtNodes.inc"
  };

Node::NodeType Node::getNodeType() const {
  return NdType;
}

StringRef Node::getNodeTypeAsString() const {
  return StringRef(TypesToStrings.at(NdType));
}

bool Node::isNodeType(const StringRef &s) {
  return (StringsToTypes.count(s.str()) > 0);
}

Node::NodeType Node::getAsNodeType(const StringRef &s) {
  if (!StringsToTypes.count(s.str()))
    return ND_NoNode;

  return StringsToTypes.at(s.str());
}

StringRef Node::getAsString(Node::NodeType ndType) {
  if (!TypesToStrings.count(ndType))
      return StringRef();

  return StringRef(TypesToStrings.at(ndType));
}

bool Node::isa(Node::NodeType ndType) {
  switch (ndType) {
#define STMT(Node, Parent) \
  case ND_##Node: return llvm::template isa<Node>(ASTNode);
#define ABSTRACT_STMT(STMT)
  STMT(Stmt, Null)
  STMT(Expr, Stmt)
#include "clang/AST/StmtNodes.inc"
  default:
    llvm_unreachable("invalid node type");
  }
}

bool Node::isStmt() {
  return Node::isExpr(this->NdType);
}

bool Node::isExpr() {
  return Node::isExpr(this->NdType);
}

bool Node::isStmt(NodeType ndType) {
  return ((ndType == ND_Stmt) ||
          (ndType >= ND_firstStmtConstant &&
           ndType <= ND_lastStmtConstant));
}
bool Node::isExpr(NodeType ndType) {
  return ((ndType == ND_Expr) ||
          (ndType >= ND_firstExprConstant &&
           ndType <= ND_lastExprConstant));
}

Node::NodeType Node::getNodeType(BaseNode *astNode) {
  NodeType result = ND_NoNode;

#define STMT(Node, Parent) \
  if (llvm::template isa<Node>(astNode)) \
    result = ND_##Node;
#define ABSTRACT_STMT(STMT)
  STMT(Stmt, Null)
  STMT(Expr, Stmt)
#include "clang/AST/StmtNodes.inc"

  return result;
}


