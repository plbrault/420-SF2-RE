#ifndef __NODE_H
#define __NODE_H

class Node {
private:
    Node *_next;
    double _value;
public:
    Node();
    Node(Node *next, double value);
    Node(const Node &node);
    ~Node();

    const Node &operator=(const Node &node);

    Node *getNext() const;
    void setNext(Node *next);
    double getValue() const;
};

#endif