/*
* @file newfraction2.cpp
* @brief implamentations of the functions and overloaders of the Fraction class
*/

#include <iostream>
#include <string>
#include <iostream>
#include "newfraction2.h"
using std::string;
using namespace std;

//----------Class Member Functions--------------------

/*
* @breif default constructor with the option to pass values or use deafaults
* @param numerator numerator of the fraction. Default of 1
* @param denominator numerator of the fraction. Default of 1
* @param 
*/
Fraction::Fraction(int numerator, int denominator, string name) {
    this->numerator = numerator;
    this->denominator = denominator;
    this->name = name;
}

/*
* @brief setter function for the numerator value
* @param input the new numerator value
*/
void Fraction::SetNumerator(int input) {
    numerator = input;
}

/*
* @brief setter function for the denominator value
* @param input the new denominator value
*/
void Fraction::SetDenominator(int input) {
    denominator = input;
}

/*
* @brief getter function for the numerator value
* @return the numerator value
*/
int Fraction::GetNumerator() const {
    return numerator;
}

/*
* @brief getter function for the denominator value
* @return the denominator value
*/
int Fraction::GetDenominator() const {
    return denominator;
}

/*
* @brief prints the fraction in the style numerator/denominator
*/
void Fraction::DisplayFraction() const {
    cout << name << " = " << numerator << "/" << denominator << endl;
}

/*
* @brief adds two fractions
* @param other the fraction being added to the first
* @return a new Fraction object that is the sum of the two inputs
*/
Fraction Fraction::operator+(const Fraction& other) const {
    int newDenom = denominator * other.GetDenominator();
    int newNumer = (numerator * other.GetDenominator()) + (other.GetNumerator() * denominator);

    return Fraction(newNumer, newDenom);
}

/*
* @brief subtracts two fractions
* @param other the fraction being subtracted from the first
* @return a new Fraction object that is the difference of the two inputs
*/
Fraction Fraction::operator-(const Fraction& other) const {
    int newDenom = denominator * other.GetDenominator();
    int newNumer = (numerator * other.GetDenominator()) - (other.GetNumerator() * denominator);

    return Fraction(newNumer, newDenom);
}

/*
* @breif allows for direct reading of Fraction from input
* @param in istream object for reading inputs
* @param f the Fraction object that the inputs will be used to intialize
* @return the instream for chaining
*/
istream &operator>>(istream &in, Fraction& f) {
    int numer;
    int denom;

    in >> numer >> denom;
    f.SetNumerator(numer);
    f.SetDenominator(denom);

    return in;
}

//----------Non-Member Functions------------------------------


/*
* @breif multiplies two Fractions
* @param lhs the first Fraction being multiplied
* @param rhs the second Fraction being multiplied
* @return a new Fraction that is the product of the two inputs
*/
Fraction operator*(const Fraction &lhs, const Fraction &rhs)
{
    int newNumer = lhs.GetNumerator() * rhs.GetNumerator();
    int newDenom = lhs.GetDenominator() * rhs.GetDenominator();
    return Fraction(newNumer, newDenom);
}

/*
* @breif divides two Fractions
* @param lhs the first Fraction (Divedend)
* @param rhs the second Fraction (Divisor)
* @return a new Fraction that is the quotient of the two inputs
*/
Fraction operator/(const Fraction &lhs, const Fraction &rhs) {
    int newNumer = lhs.GetNumerator() * rhs.GetDenominator();
    int newDenom = lhs.GetDenominator() * rhs.GetNumerator();
    return Fraction(newNumer, newDenom);
}

/*
* @breif outputs the Fraction in the form numer/denom
* @param out ostream object for output
* @param f the fraction being outputted
* @return the ostream for chaining
*/
ostream &operator<<(ostream &out, Fraction& f) {
    out << f.GetNumerator() << "/" << f.GetDenominator() << endl;
    return out;
}


