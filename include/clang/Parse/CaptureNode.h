//===--- CaptureParser.h - C Language Parser ---------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//  This file defines the Parser interface.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_PARSE_CAPTURE_NODE_H
#define LLVM_CLANG_PARSE_CAPTURE_NODE_H

#include "clang/AST/Type.h"

#include <map>
#include <string>

namespace clang {

class Node {
public:
  enum NodeType {
    ND_NoNode = 0,
    ND_Stmt,
#define STMT(Node, Parent) \
    ND_##Node,
#define STMT_RANGE(Base, First, Last) \
    ND_first##Base##Constant=ND_##First, ND_last##Base##Constant=ND_##Last,
#define LAST_STMT_RANGE(Base, First, Last) \
    ND_first##Base##Constant=ND_##First, ND_last##Base##Constant=ND_##Last
#include "clang/AST/StmtNodes.inc"
  };

  static const std::map<const std::string, const NodeType> StringsToTypes;
  static const std::map<const NodeType, const std::string> TypesToStrings;

  // For now we support statements and expressions. Since the common base
  // class is 'Stmt', we use this is the type of all captured AST nodes.
  // In the future, we should also support 'Decl', in which case it will be
  // more complicated to find a common base class.
  typedef Stmt BaseNode;
private:
  // Pointer to the root node of the (sub-)AST:
  BaseNode *ASTNode;

  NodeType NdType;

  // We need the type of the expression if 'NdType==ND_EXPR':
  QualType ExprType;

  SourceLocation Loc;

public:
  Node(BaseNode *node, SourceLocation loc, NodeType ndType = ND_NoNode,
       QualType exprType = QualType())
    : ASTNode(node), NdType(ndType), ExprType(exprType), Loc(loc) {}

  Node() {}

  BaseNode *getASTNode() const { return ASTNode; }

  NodeType getNodeType() const;
  StringRef getNodeTypeAsString() const;

  QualType getExprType() const { return ExprType; }
  QualType getCanonicalExprType() const { return ExprType.getCanonicalType(); }
  void setExprType(QualType &QT) { ExprType = QT; }

  static bool isNodeType(const StringRef &s);
  static NodeType getAsNodeType(const StringRef &s);
  static StringRef getAsString(NodeType ndType);

  bool isa(NodeType ndType);
  bool isStmt();
  bool isExpr();

  static bool isDerived(NodeType candidate, NodeType base);
  static bool isStmt(NodeType ndType);
  static bool isExpr(NodeType ndType);
  static NodeType getNodeType(BaseNode *astNode);

  SourceLocation getLocation() const { return Loc; }
};

struct FormalNode {
  SourceLocation Loc;

  StringRef Name;

  Node::NodeType NdType;
  // For expressions only:
  QualType QT;

  FormalNode(const StringRef &name, SourceLocation loc,
             Node::NodeType ndType = Node::ND_NoNode)
    : Loc(loc), Name(name), NdType(ndType) {}

  FormalNode() {}

  QualType getCanonicalType() const { return QT.getCanonicalType(); }
};

typedef std::vector<FormalNode> FormalNodesTy;

}// end namespace clang

#endif
