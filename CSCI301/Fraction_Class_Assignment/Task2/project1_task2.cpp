/*
* @instructor Dr. Jie Hu Meichsner
* @name Thomas Janckila
* @date 9/4/2025
* @file project1_task2.cpp
* @brief test code for the functions for the operators of the fraction class
*/
#include <iostream>
#include <string>
#include "newfraction1.h"
#include "newfraction1.cpp"

using namespace std;

int main() {
    int input1;
    int input2;

    cout << "Please enter the first fraction" << endl;
    cin >> input1 >> input2;
    Fraction f1(input1, input2, "f1");

    cout << "Please enter the second fraction" << endl;
    cin >> input1 >> input2;
    Fraction f2(input1, input2, "f2");

    cout << "The frractions you entered are " << endl;
    f1.DisplayFraction();
    cout << endl;
    f2.DisplayFraction();
    cout << endl;

    cout << "Adding the fractions gives ";
    AddFractions(f1, f2).DisplayFraction();

    cout << endl << "The difference between the fractions is ";
    SubtractFractions(f1, f2).DisplayFraction();

    cout << endl << "Multiplying the fractions gives ";
    MultiplyFractions(f1, f2).DisplayFraction();

    cout << endl << "Dividing the fractions gives ";
    DivideFractions(f1, f2).DisplayFraction();

    return 0;
}