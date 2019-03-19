//Data Structures Project 2:
//David Klett dgk10 Mar.17/19
#include <iostream>
#include "Employee.h"
#include <vector>
#include "empmaps.h"

using namespace std;

int main()
{
    vector<Employee> empObj;
    empObj = employees();
    map <int, vector<Employee> > emp1;
    emp1 = mapEmpDept(empObj);
    emp1 = mapSalRange(empObj); //works!!!
    printSalRange(emp1); //works!
    unordered_map <int, vector<Employee> > emp2;
    emp2 = umapEmpDept(empObj);
    emp2 = umapSalRange(empObj);
    uprintSalRange(emp2);
    return 0;
}
