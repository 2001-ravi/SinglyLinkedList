#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<string>
#include <ostream>


class Employee
{
private:
    int _empId;
    std::string _name;

public:
    Employee() = default;
    Employee(const Employee&) = default;
    Employee(Employee&&) = delete;
    Employee& operator=(const Employee&) = delete;
    Employee&& operator=(Employee&&) = delete;
    ~Employee() = default;   

    Employee(int id,std::string name){
        _empId = id;
        _name = name;
    }

    int empId() const { return _empId; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "_empId: " << rhs._empId
           << " _name: " << rhs._name;
        return os;
    }

};

#endif // EMPLOYEE_H
