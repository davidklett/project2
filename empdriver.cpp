
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
    //cout << x[7].id(); //works!
    map <int, vector<Employee> > suh;

    suh = mapSalRange(x); //works!!!
    int n = suh[50000].size();
    for(int i = 0; i < n; ++i)
    {
        //cout << suh[50000][i].name();
        //cout << endl;
    }
    printSalRange(suh); //works!
    return 0;
}
