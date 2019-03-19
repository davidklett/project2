//David Klett
//Data Structures Project 2
#include "Employee.h"
//Constructor:
Employee::Employee(int i, std::string n, int pay)
{
    identifier = i;
    lastname = n;
    salary = pay;
}

void Employee::print(std::ostream &out = std::cout)
{
    out << identifier << " " << lastname << " " << salary << ": ";
}


