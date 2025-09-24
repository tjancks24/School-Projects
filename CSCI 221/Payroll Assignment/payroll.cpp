#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
//Function for inputting hours
 int inputHours() {
    bool validator = true;
    int numLoops = 0;
    int hours;
    do {
        if (numLoops >= 1){
            cout << "Invalid number of hours. Hours must not be negative" << endl;
        }
        cin >> hours;
        if (hours <= 0) {
            numLoops++;
        }
        else {
            validator = false;
        }
    } while (validator == true);

    return hours;
}
//Function for inputting pay rate
double inputPay() {
    bool validator = true;
    int numLoops = 0;
    double payRate;

    do {
        if (numLoops >= 1){
            cout << "Invalid pay rate. Pay rate must be greater than or equal to 15" << endl;
        }
        cin >> payRate;
        if (payRate < 15) {
            numLoops++;
        }
        else {
            validator = false;
        }
    } while (validator == true);

    return payRate;
} 
//Function for calculating gross wages
double calculateWages(int hours, double payRate) {
    return (hours * payRate);
}
//Function for outputting employee wages
void printInfo(vector<int> employeeID, vector<double> wages) {
    int i;
    cout << fixed << setprecision(2) << endl;
    for (i = 0; i < employeeID.size(); i++) {
        cout << "Employee number " << employeeID[i] << "'s gross wages are: $" << wages[i] << endl << endl;
    }
}
//Main function
int main() {
    //Varible declaration
    vector<int> employeeID = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    vector<int> hours;
    vector<double> payRate;
    vector<double> wages;
    int i;
    //Loop for entering employee info
    for (i = 0; i < employeeID.size(); i++) {
        cout << "Please enter the hours for employee " << employeeID[i] << "." << endl;
        hours.push_back(inputHours());
        cout << "Please enter the pay rate for employee " << employeeID[i] << "." << endl;
        payRate.push_back(inputPay());

    }

    for (i = 0; i < employeeID.size(); i++) {
        wages.push_back(calculateWages(hours[i], payRate[i]));
    }

    printInfo(employeeID, wages);

    return 0;
}