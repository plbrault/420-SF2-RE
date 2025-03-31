#include "node.h"

Node::Node() : _value(0.0), _next(nullptr) { }

Node::Node(Node *next, double value) {
    this->setNext(next);
    this->setValue(value);
}

Node::Node(const Node &node) : _value(node._value), _next(nullptr) {
    if (node._next) {
        _next = new Node(*node._next);
    }
}

Node::~Node() {
    delete this->_next;
    this->_next = nullptr;
}

const Node &Node::operator=(const Node &node) {
    if (this == &node) {
        return *this;
    }

    delete _next;
    _next = nullptr;

    _value = node._value;

    if (node._next) {
        _next = new Node(*node._next);
    }

    return *this;
}

Node *Node::getNext() {
    return this->_next;
}

void Node::setNext(Node *next) {
    this->_next = next;
}

double Node::getValue() const {
    return this->_value;
}

void Node::setValue(double value) {
    this->_value = value;
}