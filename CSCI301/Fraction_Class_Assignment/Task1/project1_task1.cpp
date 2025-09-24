/*
* @instructor Dr. Jie Hu Meichsner
* @name Thomas Janckila
* @date 9/4/2025
* @file project1_task1.cpp
* @brief test code for the functions of the Fraction class
*/
#include <iostream>
#include "fraction.h"
#include "fraction.cpp"
using namespace std;

int main() {
    //setup using the default constructor
    Fraction fraction1;

    //Prints the function
    fraction1.DisplayFraction();

    //setting the numerator and denominator using public members
    fraction1.SetNumerator(6);
    fraction1.SetDenominator(7);
    //getting the numerator and denominator with public members
    cout << "The numerator is " << fraction1.GetNumerator() << endl;
    cout << "The denominator is " << fraction1.GetDenominator() << endl;


    return 0;
}