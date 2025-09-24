#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;
//Employee Class
class Employee {
    //Initializers for different cases
    public:
    Employee() {
        this->name = "";
        this->idNumber = 0;
        this->department = "";
        this->position = "";
    };
    Employee(string name, int idNumber, string department, string position) {
        this->name = name;
        this->idNumber = idNumber;
        this->department = department;
        this->position = position;
    };
    Employee(string name, int idNumber){
        this->name = name;
        this->idNumber = idNumber;
        this->department = "";
        this->position = "";
    };
    //Accessor Functions
    string GetName() const { return name; }
    string GetDepartment() const { return department; }
    string GetPosition() const { return position; }
    int GetID() const { return idNumber; }
    //Mutator Functions
    void SetName(string name) { this->name = name; }
    void SetPosition(string position) { this->position = position; }
    void SetDepartment(string department) { this->department = department; }
    void SetIDNumber(int idNumber) { this->idNumber = idNumber; }
    //Print Function
    void Print() {
        cout << "Name: " << name
        << " IdNumber: " << idNumber
        << " Department: " << department
        << " Position: " << position << endl;
    }
    private:

    string name;
    int idNumber;
    string department;
    string position;
};

#endif