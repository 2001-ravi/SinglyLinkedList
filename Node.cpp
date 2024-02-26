#include "Node.h"

template <typename T>
Node<T>::~Node()
{
    std::cout<<"in node ~\n";
    delete _next;
}

template <typename T>
Node<T>::Node(T ele)
    : _ele(ele)
{
}

