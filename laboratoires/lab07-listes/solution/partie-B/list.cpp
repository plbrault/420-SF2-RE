#include "list.h"

List::List() : _head(nullptr), _current(nullptr), _size(0) { }

List::List(const List &other) : _head(nullptr), _current(nullptr), _size(0)  {
    Node *temp = other._head;
    Node *last = nullptr;

    while (temp) {
        Node *newNode = new Node(*temp);

        if (!_head) {
            _head = newNode;
        } else {
            last->setNext(newNode);
        }

        if (temp == other._current) {
            _current = newNode;
        }
        temp = temp->getNext();
        ++_size;
    }
}

List::~List() {
    delete this->_head;
    this->_head = nullptr;
    this->_current = nullptr;
}

List &List::operator=(const List &other) {
    if (this == &other) {
        return *this;
    }

    delete _head;
    _head = nullptr;
    _current = nullptr;
    _size = 0;

    Node* temp = other._head;
    Node* last = nullptr;

    while (temp) {
        Node* newNode = new Node(*temp); // deep copy
        if (!_head) _head = newNode;
        else last->setNext(newNode);
        last = newNode;
        if (temp == other._current) _current = newNode;
        temp = temp->getNext();
        ++_size;
    }

    return *this;
}

void List::push(double value) {
    Node *newNode = new Node();
    newNode->setValue(value);

    if (!this->_head) {
        _head = newNode;
    } else {
        Node *temp = _head;
        while (temp->getNext()) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
    ++this->_size;
}

void List::pop() {
    if (!this->_head) {
        return;
    }

    if (!this->_head->getNext()) {
        delete this->_head;
        this->_head = nullptr;
    } else {
        Node *temp = this->_head;
        while (temp->getNext()->getNext()) {
            temp = temp->getNext();
        }
        delete temp->getNext();
        temp->setNext(nullptr);
    }
    --this->_size;
}
Node *List::getCurrent() {
    return this->_current;
}

void List::moveAt(size_t pos) {
    if (pos >= _size) {
        return;
    }

    _current = _head;
    size_t count = 0;
    while (count < pos && _current->getNext() != nullptr) {
        _current = _current->getNext();
        count++;
    }
}
void List::insert(double value) {
    if (!_current) return;

    if (_current == _head) {
        Node* newNode = new Node();
        newNode->setValue(value);
        newNode->setNext(_head);
        _head = newNode;
        _current = newNode;
    } else {
        Node* temp = _head;
        while (temp && temp->getNext() != _current) {
            temp = temp->getNext();
        }
        if (temp) {
            Node* newNode = new Node();
            newNode->setValue(value);
            newNode->setNext(_current);
            temp->setNext(newNode);
            _current = newNode;
        }
    }
    ++_size;
}

void List::remove() {
    if (!_current) return;

    if (_current == _head) {
        Node* temp = _head;
        _head = _head->getNext();
        delete temp;
        _current = _head;
    } else {
        Node* prev = _head;
        while (prev && prev->getNext() != _current) {
            prev = prev->getNext();
        }
        if (prev) {
            Node* temp = _current;
            prev->setNext(_current->getNext());
            _current = _current->getNext();
            temp->setNext(nullptr);
            delete temp;
        }
    }
    --_size;
}