#include <iostream>
#include <iomanip>
#include <vector>
#include "employee.h"
using namespace std;

int main() {
    //Variable Declaration
    int i;
    int idNumber;
    int numEmployees;
    vector<Employee> employeeList;
    string name;
    string department;
    string position;
    Employee newEmployee;

    cout << "Enter the number of employees" << endl;
    cin >> numEmployees;
    
    cout << "Enter the name, ID number, department, and position for each employee. Make sure each is seperated by whitespace" << endl;
    //Loop for entering Employee info
    for (i = 0; i < numEmployees; i++) {
        cout << "Employee #" << i + 1 << endl;
        cin >> name >> idNumber >> department >> position;
        newEmployee = Employee(name, idNumber, department, position);
        employeeList.push_back(newEmployee);
    }
    //Loop for outputting employee Info
    for (i = 0; i < numEmployees; i++) {
        employeeList[i].Print();
    }
}