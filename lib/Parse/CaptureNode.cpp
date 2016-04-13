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

#include "clang/Parse/CaptureNode.h"

using namespace clang;

const std::map<const std::string, const Node::NodeType> Node::StringsToTypes = {
    {"stmt", ND_STMT},
    {"expr", ND_EXPR},
    {"decl", ND_DECL}
};

const std::map<const Node::NodeType, const std::string> Node::TypesToStrings = {
    {ND_STMT, "stmt"},
    {ND_EXPR, "expr"},
    {ND_DECL, "decl"}
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
    return ND_INVALID;

  return StringsToTypes.at(s.str());
}

StringRef Node::getAsString(Node::NodeType ndType) {
  if (!TypesToStrings.count(ndType))
      return StringRef();

  return StringRef(TypesToStrings.at(ndType));
}


