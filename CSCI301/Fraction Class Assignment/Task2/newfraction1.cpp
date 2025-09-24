/*
* @file fraction.cpp
* @brief declarations for the functions of the Fraction class
*/

#include <iostream>
#include <string>
#include "newfraction1.h"
using namespace std;

//----------Class Member Functions--------------------
Fraction::Fraction(int numerator, int denominator, string name) {
    this->numerator = numerator;
    this->denominator = denominator;
    this->name = name;
}

void Fraction::SetNumerator(int input) {
    numerator = input;
}
void Fraction::SetDenominator(int input) {
    denominator = input;
}

int Fraction::GetNumerator() const {
    return numerator;
}

int Fraction::GetDenominator() const {
    return denominator;
}

void Fraction::DisplayFraction() const {
    cout << name << " = " << numerator << "/" << denominator << endl;
}

//-----------Non-Member Functions---------------------


/*
* @brief adds two fractions
* @param a the first fraction
* @param b the fraction being added to the first
* @return a new Fraction object that is the sum of the two inputs
*/
Fraction AddFractions(const Fraction& a, const Fraction& b) {
    //create copies of the fractions in case we need to change the denominator
    Fraction copyA = a;
    Fraction copyB = b;
    //so we don't accidently change the fractions denominators
    int denominatorA = copyA.GetDenominator();
    int denominatorB = copyB.GetDenominator();
    //Fraction to return
    Fraction newFraction;

    //Check if we need to change the denominator. If so simply multiply them by each other
    if(copyA.GetDenominator() != b.GetDenominator()) {
        copyA.SetDenominator(denominatorA * denominatorB);
        copyA.SetNumerator(copyA.GetNumerator() * denominatorB);

        copyB.SetDenominator(denominatorA * denominatorB);
        copyB.SetNumerator(copyB.GetNumerator() * denominatorA);
    }
    //Add the numerators together
    newFraction.SetNumerator(copyA.GetNumerator() + copyB.GetNumerator());
    newFraction.SetDenominator(copyA.GetDenominator());
    
    return newFraction;
}

/*
* @brief subtracts two fractions
* @param a the first fraction
* @param b the fraction being subtracted from the first
* @return a new Fraction object that is the difference of the two inputs
*/
Fraction SubtractFractions(const Fraction& a, const Fraction& b) {
    //create copies of the fractions in case we need to change the denominator
    Fraction copyA = a;
    Fraction copyB = b;
    //so we don't accidently change the fractions denominators
    int denominatorA = copyA.GetDenominator();
    int denominatorB = copyB.GetDenominator();
    //Fraction to return
    Fraction newFraction;

    //Check if we need to change the denominator. If so simply multiply them by each other
    if(copyA.GetDenominator() != b.GetDenominator()) {
        copyA.SetDenominator(denominatorA * denominatorB);
        copyA.SetNumerator(copyA.GetNumerator() * denominatorB);

        copyB.SetDenominator(denominatorA * denominatorB);
        copyB.SetNumerator(copyB.GetNumerator() * denominatorA);
    }
    //Subtract the numerator
    newFraction.SetNumerator(copyA.GetNumerator() - copyB.GetNumerator());
    newFraction.SetDenominator(copyA.GetDenominator());
    
    return newFraction;
}

/*
* @brief subtracts two fractions
* @param a the first fraction
* @param b the fraction being multiplied the first
* @return a new Fraction object that is the product of the two inputs
*/
Fraction MultiplyFractions(const Fraction& a, const Fraction& b) {
    Fraction copyA = a;
    Fraction copyB = b;
    //Fraction to return
    Fraction newFraction;

    newFraction.SetNumerator(copyA.GetNumerator() * copyB.GetNumerator());
    newFraction.SetDenominator(copyA.GetDenominator() * copyB.GetDenominator());

    return newFraction;
}

/*
* @brief divides two fractions
* @param a the first fraction
* @param b the fraction being divided the first
* @return a new Fraction object that is the quotient of the two inputs
*/
Fraction DivideFractions(const Fraction& a, const Fraction& b) {
    Fraction copyA = a;
    Fraction copyB = b;
    Fraction newFraction;

    newFraction.SetNumerator(copyA.GetNumerator() * copyB.GetDenominator());
    newFraction.SetDenominator(copyA.GetDenominator() * copyB.GetNumerator());

    return newFraction;
}