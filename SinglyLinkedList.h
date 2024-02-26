#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include"Node.h"
#include"Employee.h"

template<typename T>
class SinglyLinkedList
{
private:
    Node<T> *_root {nullptr};
    Node<T> *_end {nullptr};
    int _size {0};

public:
    //iterator class for singly linked list
    class Iterator
    {
    private:
        Node<T> *_ptr {nullptr};
        Node<T> *_itrRoot {nullptr};

    public:
        Iterator() = delete;
        Iterator(const Iterator&) = default;
        Iterator(Iterator&&) = delete;
        Iterator& operator=(const Iterator&) = delete;
        Iterator&& operator=(Iterator&&) = delete;
        ~Iterator() = default; // no need to write ~ definition as the _ptr holds the 
                                //address which is in usage 

        explicit Iterator(Node<T> *ptr);
        Iterator(Node<T> *ptr,Node<T> *itrRoot);

        typename SinglyLinkedList<T>::Iterator operator++(int);
        typename SinglyLinkedList<T>::Iterator operator--(int);
        typename SinglyLinkedList<T>::Iterator& operator++();
        typename SinglyLinkedList<T>::Iterator& operator--();
        typename SinglyLinkedList<T>::Iterator operator+(const int&);
        typename SinglyLinkedList<T>::Iterator operator-(const int&);
        bool operator!=(const SinglyLinkedList<T>::Iterator& itr);
        bool operator==(const SinglyLinkedList<T>::Iterator& itr);
        T operator*();

    private:
        //getter and setter
        Node<T> *ptr() const { return _ptr; }
        void setPtr(Node<T> *ptr) { _ptr = ptr; }

    };

    SinglyLinkedList<T>() = default;
    SinglyLinkedList<T>(const SinglyLinkedList<T>&) = delete;
    SinglyLinkedList<T>(SinglyLinkedList<T>&&) = delete;
    SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>&) = delete;
    SinglyLinkedList<T>&& operator=(SinglyLinkedList<T>&&) = delete;
    ~SinglyLinkedList<T>();

    void push_back(const T& ele);
    T pop_back();
    int size();
    typename SinglyLinkedList<T>::Iterator begin();
    typename SinglyLinkedList<T>::Iterator end();

    

};

#include"SinglyLinkedList.cpp"

#endif // SINGLYLINKEDLIST_H


