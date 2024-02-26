#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
private:
    T _ele;
    Node *_next {nullptr};
    
public:
    Node() = delete;
    Node(const Node&) = delete;
    Node(Node&&) = delete;
    Node& operator=(const Node&) = delete;
    Node&& operator=(Node&&) = delete;
    ~Node();

    Node(T ele);

    T ele() const { return _ele; }
    void setNext(Node *next) { _next = next; }
    Node *next() const { return _next; }

};

#include"Node.cpp"

#endif // NODE_H

