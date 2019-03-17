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

//function to split string:
std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter))
    {
       splittedStrings.push_back(item);
    }
    return splittedStrings;
}

vector<Employee> employees(){
    std::string x;
    std::cout << "Enter input file name:";
    std::cin >> x;
    //if input fails, have error code
    std::ifstream in("testRecords.dat"); //use x variable instead of hardcoded string
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


