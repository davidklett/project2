
//Data Structures Project 2:
//David Klett dgk10 Mar.17/19
#include <iostream>
#include "Employee.h"
#include <vector>
#include "empmaps.h"

using namespace std;

int main()
{
    vector<Employee> x;
    x = employees();
    cout << x[7].id(); //works!
    return 0;
}
