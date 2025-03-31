#ifndef __LIST_H
#define __LIST_H

#include <cstddef>

#include "node.h"

class List {
private:
    Node *_head;
    Node *_current;

    size_t _size;
public:
    List();
    List(const List &list);
    ~List();

    List &operator=(const List &other);
    void push(double value);
    void pop();
    void moveAt(size_t pos);
    void insert(double value);
    void remove();
    Node *getCurrent();
};

#endif
