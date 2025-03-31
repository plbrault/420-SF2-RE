#include "node.h"

Node::Node() : Node(nullptr, 0.0) { }

Node::Node(Node *next, double value) {
    this->_next = next;
    this->_value = value;
}

Node::Node(const Node &node) {
    this->_next = nullptr;

    if (node._next != nullptr) {
        this->_next = new Node(*node._next);
    }
    this->_value = node._value;
}

Node::~Node() {
    delete this->_next;
    this->_next = nullptr;
}

const Node &Node::operator=(const Node &node) {
    delete this->_next;

    this->_next = nullptr;
    if (node._next != nullptr) {
        this->_next = new Node(*node._next);
    }
    this->_value = node._value;
    return *this;
}

Node *Node::getNext() const {
    return this->_next;
}

void Node::setNext(Node *next) {
    if (this->_next == nullptr) {
        this->_next = next;
    }
}

double Node::getValue() const {
    return this->_value;
}