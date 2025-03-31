#include "list.h"

List::List() {
    this->_head = nullptr;
    this->_current = nullptr;
    this->_size = 0;
}

List::List(const List &list) {
    // assurer la copie de la liste complète (récursif)
}

List::~List() {
    delete this->_head;
    this->_head = nullptr;
    this->_current = nullptr;
}