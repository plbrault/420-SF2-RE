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

    const List &operator=(const List &list);

};

#endif
