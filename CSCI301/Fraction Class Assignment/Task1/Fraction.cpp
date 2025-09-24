/*
* @file fraction.cpp
* @brief declarations for the functions of the Fraction class
*/

#include <iostream>
#include "fraction.h"
using namespace std;

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

void Fraction::SetNumerator(int input) {
    numerator = input;
}
void Fraction::SetDenominator(int input) {
    denominator = input;
}

int Fraction::GetNumerator() {
    return numerator;
}

int Fraction::GetDenominator() {
    return denominator;
}

void Fraction::DisplayFraction() {
    cout << numerator << "/" << denominator << endl;
}