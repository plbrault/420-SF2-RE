#include <iostream>

#include "list.h"

int main () {
    std::cout << "Welcome" << std::endl;

    List list;
    list.push(3);
    list.push(4);
    list.push(5);
    list.push(6);

    list.moveAt(2);
    list.insert(12);

    list.moveAt(0);
    
    Node *temp = list.getCurrent();
    size_t count = 0;
    while (temp) {
        std::cout << "Value: " << temp->getValue() << std::endl;
        temp = temp->getNext();
        count++;
    }

    return 0;
}