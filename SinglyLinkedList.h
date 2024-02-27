#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include"Node.h"
#include"Employee.h"

template<typename T>
class SinglyLinkedList
{
private:
    //data members

    //_root to point to the head of the SinglyinkedList
    Node<T> *_root {nullptr};
    //_end to point to the tail of the SinglyinkedList
    Node<T> *_end {nullptr};
    //_size to monitor the number of elements in the SinglyinkedList
    int _size {0};

public:
    //iterator class for SinglyinkedList
    class Iterator
    {
    private:
        //Iterator data members 

        //_ptr to keep the address of the cuurent node wrapped by the Iterator 
        Node<T> *_ptr {nullptr};
        //_itrRoot to hold the root address of the SinglyinkedList
        Node<T> *_itrRoot {nullptr};

    public:
        //special member functions of Iterator class
        Iterator() = delete;
        Iterator(const Iterator&) = default;
        Iterator(Iterator&&) = delete;
        Iterator& operator=(const Iterator&) = delete;
        Iterator&& operator=(Iterator&&) = delete;
        ~Iterator() = default; // no need to write ~ definition as the _ptr holds the 
                                //address which is in usage 

        //parameterized constructors to initialize the datamembers
        explicit Iterator(Node<T> *ptr);
        Iterator(Node<T> *ptr,Node<T> *itrRoot);

        //operator overloading to perform arithmetic operations on Iterator objects
        typename SinglyLinkedList<T>::Iterator operator++(int);
        typename SinglyLinkedList<T>::Iterator operator--(int);
        typename SinglyLinkedList<T>::Iterator& operator++();
        typename SinglyLinkedList<T>::Iterator& operator--();
        typename SinglyLinkedList<T>::Iterator operator+(const int&);
        typename SinglyLinkedList<T>::Iterator operator-(const int&);

        //operator overloading to perform relatioal operations on Iterator objects
        bool operator!=(const SinglyLinkedList<T>::Iterator& itr);
        bool operator==(const SinglyLinkedList<T>::Iterator& itr);
        
        //operator overloading to dereference Iterator object and get the Object in the Node
        T operator*();

    private:
        //getter and setter
        Node<T> *ptr() const { return _ptr; }
        void setPtr(Node<T> *ptr) { _ptr = ptr; }

    };

    //member functions for SinglyLinkedList
    SinglyLinkedList<T>() = default;
    SinglyLinkedList<T>(const SinglyLinkedList<T>&) = delete;
    SinglyLinkedList<T>(SinglyLinkedList<T>&&) = delete;
    SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>&) = delete;
    SinglyLinkedList<T>&& operator=(SinglyLinkedList<T>&&) = delete;
    ~SinglyLinkedList<T>();

    //member functions for SinglyinkedList

    //to push an object of type T by taking an R value reference
    void push_back(T&& ele);
    //to remove and return the last pushed Object in the SinglyinkedList
    T pop_back();
    //to get the count of Objects present in the SinglyinkedList
    int size();
    //returns Iterator object to iterate over the SinglyinkedList
    typename SinglyLinkedList<T>::Iterator begin();
    typename SinglyLinkedList<T>::Iterator end();

    

};

#include"SinglyLinkedList.cpp"

#endif // SINGLYLINKEDLIST_H


