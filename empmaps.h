//David Klett
#include "Employee.h"
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

std::vector<Employee> employees();
map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp);
map<int,vector<Employee>> mapSalRange(vector<Employee> & emp);
void printSalRange(map<int,vector<Employee>> & salRange);
unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp);
unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp);
void uprintSalRange(unordered_map<int,vector<Employee>> & salRange);
