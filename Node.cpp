//
// Created by d on 12/26/18.
//

#include "Node.h"

Node::Node( const string &_name,Node *_parent) : parent(_parent), name(_name) {}

Node *Node::getParent() const {
    return parent;
}

void Node::setParent(Node *_parent) {
    Node::parent = _parent;
}

Node::Node() = default;

const string &Node::getName() const {
    return name;
}

void Node::setName(const string &_name) {
    Node::name = _name;
}
