/*
* @instructor Dr. Jie Hu Meichsner
* @name Thomas Janckila
* @starID cd2898vx
* @date 9/4/2025
* @file project1_task3.cpp
* @brief test code for the operator overloads on the Fraction class
*/
#include <iostream>
#include <string>
#include "newfraction2.h"
#include "newfraction2.cpp"

using namespace std;

int main() {
    Fraction f1;
    Fraction f2;

    cout << "Please enter the first fraction" << endl;
    cin >> f1;
    cout << "Please enter the second fraction" << endl;
    cin >> f2;
    cout << "The two fractions you entered are " << f1 << " and " << f2 << endl;

    cout << "Adding them gives" << endl;
    (f1 + f2).DisplayFraction();

    cout << "The difference between the first and second is" << endl;
    (f1 - f2).DisplayFraction();

    
    cout << "Multiplying them gives" << endl;
    (f1 * f2).DisplayFraction();

    
    cout << "Dividing the first by the second gives" << endl;
    (f1 / f2).DisplayFraction();
    
    return 0;
}