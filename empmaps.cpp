//cpp file for empmaps
//David Klett


/*
This function builds and returns a vector of employees using the Employee class file. You can prompt
the user for the input file in this function. Give the user a nice error message if the input file does not
exist and exit.
*/
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Employee.h"
#include <sstream>
#include <algorithm>
#include <vector>
#include <String>
#include <iterator>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <map>
//function to split string:

/*
This function builds and returns a vector of employees using the Employee class file. You can prompt
the user for the input file in this function. Give the user a nice error message if the input file does not
exist and exit.
*/
vector<Employee> employees(){
    std::string x;
    std::cout << "Enter input file name:";
    std::cin >> x;
    //if input fails, have error code
    std::ifstream in("records.dat"); //use x variable instead of hardcoded string
    std::vector <Employee> employees;
    std::string line;
    //Read the next line from the file until it reaches the end
    while(std::getline(in, line))
    {
        //Parse the string into three elements in a vector:
        std::istringstream iss(line);
        std::vector<std::string> splittedStrings(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());

        int x = stoi(splittedStrings[0]);
        std::string y = splittedStrings[1];
        int z = stoi(splittedStrings[2]);
        Employee e(x,y,z);
        employees.push_back(e);
    }

    return employees;
}

/*
This function builds and returns an ordered map. The key for this map is the employee’s department
id. The department id is the first four most significant digits of the employee identifier. For example,
a record in the records.dat file contains “882966 Etzel 120580” with 882966 as the
employee id. The department this employee belongs to is 8829.

*/
std::map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp)
{
    int employeeSize = emp.size();
    std::map<int, vector<Employee>> myMap;

    for(int i = 0; i < employeeSize; ++i)
    {
        stringstream ss;
        int number = emp[i].id();
        ss << number;
        int firstFourNumbers = atoi(ss.str().substr(0, 4).c_str());
        myMap[firstFourNumbers].push_back(emp[i]);
    }

    return myMap;
}

/*
This function builds and returns an ordered map. The key for this map is related to the employee’s
salary based on 10,000 range increments. If the employee’s salary is in the range of 40,000 to
49,999, the key is 40000. For example, a record in the records.dat file contains
“882966 Etzel 120580” with 120580 as the employee’s salary. The salary range for this
employee is 120000. Thus, the range is in 10,000 increments. Range 0 takes values [0,10000) and
the key for this is 0, range 10,000 takes values from [10000, 20000) and the key for this is 10000, …
*/
map<int,vector<Employee>> mapSalRange(vector<Employee> & emp)
{
    int employeeSize = emp.size();
    std::map<int, vector<Employee>> myMap;

    for(int i = 0; i < employeeSize; ++i)
    {
        stringstream ss;
        int salary = emp[i].sal();
        ss << salary;
        int salRange = (salary/10000)*10000;
        //cout << salRange << endl;
        myMap[salRange].push_back(emp[i]);
    }
    return myMap;
}

/*
This function prints the number of employees within each range using an ordered map. Afterwards,
it print the salary range with the most number of employees and prints the number of employees in
this range. Example output produced by this function is:
ORDERED Map Salary Range with most employees: 130000 containing 6400
employees.
*/
void printSalRange(map<int,vector<Employee>> & salRange)
{
    int mostEmp = 0; //initialize to zero
    int mostEmpNumber = 0;
    for(auto const& pair: salRange)
    {
        cout << "Salary Range: " << pair.first;
        cout << " # employees is " << pair.second.size();
        cout << endl;
        if(pair.second.size() > mostEmpNumber)
        {
             mostEmp = pair.first;
             mostEmpNumber = pair.second.size();
        }

    }
    cout << endl;
    cout << "The sal range with most employees is " << mostEmp;
    cout << endl << "with " << mostEmpNumber << " employees.";
}
