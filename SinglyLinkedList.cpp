#include "SinglyLinkedList.h"
#include<stdexcept>
#include<iostream>

/********** Singly Linked list member functions definitions **************/

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    // delete _root; //no need to delete for _root as we are deleting the last element in 
                    //pop_back function
    delete _end;
}

template <typename T>
void SinglyLinkedList<T>::push_back(const T& ele)
{
    if(_root == nullptr)
    {
        _root = new Node(ele);
        _end = _root;
        _size++;
        return; 
    }

    _end->setNext(new Node(ele));
    _end = _end->next();
    _size++;

}

//removes and returns the last element in the list
template<typename T>
T SinglyLinkedList<T>::pop_back()
{
    if(_size==0)
        throw std::runtime_error(" no element in list ");
    Node<T> *curr = _root;
    Node<T> *prev = _root;
    while(curr->next() != nullptr)
    {
        prev = curr;
        curr = curr->next();  
    }
    T ele = _end->ele();
    prev->setNext(nullptr);
    delete curr;
    _end = prev;
    _size--;
    return ele;
}

//return the size if the list
template<typename T>
int SinglyLinkedList<T>::size()
{
    return _size;
}

//returns the beginning iterator of the list
template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::begin()
{
    return typename SinglyLinkedList<T>::Iterator(_root,_root);
}

//returns the ending+1 iterator of the list
template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::end()
{
    return typename SinglyLinkedList<T>::Iterator(_end->next(),_root);
}


/********** Singly Linked list::iterator member functions definitions **************/

// parameterized constructor for initializing cuurent iterator node
template <typename T>
inline SinglyLinkedList<T>::Iterator::Iterator(Node<T> *ptr)
    :_ptr(ptr)
{
}

//parameterized constructor for initializing root and cuurent iterator node
template <typename T>
SinglyLinkedList<T>::Iterator::Iterator(Node<T> *ptr, Node<T> *itrRoot)
    :_ptr(ptr),_itrRoot(itrRoot)
{
}

//post-increment of list iterator
template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::Iterator::operator++(int)
{
    SinglyLinkedList<T>::Iterator itr = *this;   
    this->_ptr = this->_ptr->next();
    return itr;
}

//post-decrement of list iterator
template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::Iterator::operator--(int)
{
    SinglyLinkedList<T>::Iterator itr = *this;   

    Node<T>* curr = _itrRoot; //used _root in outer class

    while(curr->next() != this->_ptr){
        curr = curr->next();
    }
    this->_ptr = curr;
    return itr;
}

// pre-increment of list iterator
template <typename T>
typename SinglyLinkedList<T>::Iterator&  SinglyLinkedList<T>::Iterator::operator++()
{
    this->_ptr = this->_ptr->next();
    return *this;
}

//pre-decrement of list iterator
template <typename T>
typename SinglyLinkedList<T>::Iterator&  SinglyLinkedList<T>::Iterator::operator--()
{
    Node<T>* curr = _itrRoot;
    while(curr->next() != this->_ptr){
        curr = curr->next();
    }
    this->_ptr = curr;
    return *this;
}

//plus operator overload to increment iterator by n times
template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::Iterator::operator+(const int& n)
{
    SinglyLinkedList<T>::Iterator itr = *this;
    for(int i=0;i<n;i++){
        itr._ptr = itr._ptr->next();
    }
    return itr;
}

//minus operator overload to decrement iterator by n times
template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::Iterator::operator-(const int& n)
{

    Node<T>* curr = _itrRoot;
    SinglyLinkedList<T>::Iterator itr = *this;
    int count = 0;
    while(curr!=itr._ptr){
        count++;
        curr = curr->next();
    }

    curr = _itrRoot;
    count = count-n;

    if(count == 0){
        itr._ptr = _itrRoot;
        return itr;
    }

    for(int i=0;i<count;i++){
        itr._ptr = curr->next();
        curr = curr->next();
    }
    
    return itr;
}

//not equal to operator overload
template <typename T>
bool SinglyLinkedList<T>::Iterator::operator!=(const SinglyLinkedList<T>::Iterator &itr)
{
    return this->_ptr != itr._ptr;
}

//relational equal operator overload 
template <typename T>
bool SinglyLinkedList<T>::Iterator::operator==(const SinglyLinkedList<T>::Iterator &itr)
{
    return this->_ptr == itr._ptr;
}

//de-reference operator overload
template <typename T>
T  SinglyLinkedList<T>::Iterator::operator*()
{
    return this->_ptr->ele();
}


