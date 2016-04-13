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
#include "clang/Parse/Parser.h"

#include <map>
#include <string>

namespace clang {

class Node {
public:
  enum NodeType {
    ND_STMT = 0,
    ND_EXPR,
    ND_DECL,
    ND_INVALID,
    ND_COUNT
  };

  static const std::map<const std::string, const NodeType> StringsToTypes;
  static const std::map<const NodeType, const std::string> TypesToStrings;

private:
  // Pointer to the root node of the (sub-)AST:
  void *ASTNode;

  NodeType NdType;

  // We need the type of the expression if 'NdType==ND_EXPR':
  QualType ExprType;

  SourceLocation Loc;

public:
  Node(void *node, SourceLocation loc, NodeType ndType = ND_INVALID,
       QualType exprType = QualType())
    : ASTNode(node), NdType(ndType), ExprType(exprType), Loc(loc) {}

  Node() {}

  void *getASTNode() const { return ASTNode; }

  NodeType getNodeType() const;
  StringRef getNodeTypeAsString() const;

  QualType getExprType() const { return ExprType; }
  void setExprType(QualType &QT) { ExprType = QT; }

  static bool isNodeType(const StringRef &s);
  static NodeType getAsNodeType(const StringRef &s);
  static StringRef getAsString(NodeType ndType);

  SourceLocation getLocation() const { return Loc; }
};

struct FormalNode {
  SourceLocation Loc;

  StringRef Name;

  Node::NodeType NdType;
  // For expressions, type as is it is parsed:
  TypeResult TR;

  FormalNode(const StringRef &name, SourceLocation loc,
             Node::NodeType ndType = Node::ND_INVALID)
    : Loc(loc), Name(name), NdType(ndType) {}

  FormalNode() {}
};

typedef std::vector<FormalNode> FormalNodesTy;

}// end namespace clang

#endif
