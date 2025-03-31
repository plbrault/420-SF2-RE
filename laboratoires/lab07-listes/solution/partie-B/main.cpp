#include <iostream>

#include "node.h"

int main () {
    std::cout << "Welcome" << std::endl;

    Node *forthNode = new Node(nullptr, 3.7);
    Node *thirdNode = new Node(forthNode, 3.4);
    Node *secondNode = new Node(thirdNode, 2.8);
    Node *firstNode = new Node(secondNode, 2.4);

    Node *current = firstNode;
    do {
        std::cout << "The value is " << current->getValue() << std::endl;
    } while((current = current->getNext()) != nullptr);

    delete firstNode;

    return 0;
}