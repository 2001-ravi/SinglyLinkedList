#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
private:
    //data members
    T _ele;
    Node *_next {nullptr};
    
public:
    //special member functions
    Node() = delete;
    Node(const Node&) = delete;
    Node(Node&&) = delete;
    Node& operator=(const Node&) = delete;
    Node&& operator=(Node&&) = delete;
    ~Node() = default;

    //parameterized constructor to initialize an T type element
    Node(T ele);

    //getter and setter to access the datamembers
    T ele() const  { return _ele; }
    void setNext(Node *next) { _next = next; }
    Node *next() const { return _next; }

};

#include"Node.cpp"

#endif // NODE_H

