/*
    compile only Main.cpp file no need to compile other cpp files as they are included in .h files ,
    they will get auto compiled
*/


#include<iostream>
#include"SinglyLinkedList.h"
#include<list>
#include"Employee.h"

int main()
{
    SinglyLinkedList<Employee> list;
    //the push_back function only takes Object by R VALUE REFERENCE
    list.push_back(Employee(1,"ravi"));
    list.push_back(Employee(2,"varma"));
    list.push_back(Employee(3,"uday"));
    list.push_back(Employee(4,"chandra"));
    list.push_back(Employee(5,"harsha"));
    list.push_back(Employee(6,"vijay"));

    std::cout<<list.pop_back()<<std::endl;

    std::cout<<"size at first : "<<list.size()<<std::endl;

    std::cout<<"pre-increment\n";
    SinglyLinkedList<Employee>::Iterator itr = list.begin();
    for(;itr!=list.end();++itr){
        std::cout<<*itr<<std::endl;
    }

    std::cout<<"post-increment\n";
    SinglyLinkedList<Employee>::Iterator itr1 = list.begin();
    for(;itr1!=list.end();itr1++){
        std::cout<<*itr1<<std::endl;
    }

    std::cout<<"pre-decrement\n";
    SinglyLinkedList<Employee>::Iterator itr2 = list.begin()+4;
    for(;itr2!=list.begin();--itr2){
        std::cout<<*itr2<<std::endl;
    }

    std::cout<<"post-decrement\n";
    SinglyLinkedList<Employee>::Iterator itr3 = list.end()-2;
    for(;itr3!=list.begin();itr3--){
        std::cout<<*itr3<<std::endl;
    }

}
