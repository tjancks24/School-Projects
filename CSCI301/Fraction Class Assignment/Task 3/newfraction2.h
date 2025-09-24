/*
* @file newfraction2.cpp
* @brief header file that contains declarations for functions and overloaders of the Fraction class
* @date 9/4/2025
* @author Thomas Janckila
*/

#ifndef fraction
#define fraction
#include <string>
#include <iostream>
using std::string;
using namespace std;

/*
* @breif the Fraction class stores a numerator and a denominator
* it has functions to call and set those values and one for printing the results
* and overloaders for easy arithmatic operations and input/output
*/

class  Fraction {
    private:
    int numerator; ///< numerator (top) of the fraction
    int denominator; ///< denominator (bottom) of the fraction
    string name; ///< name of the Fraction

    public:
    /*
    * @breif default constructor with the option to pass values or use deafaults
    * @param numerator numerator of the fraction. Default of 1
    * @param denominator numerator of the fraction. Default of 1
    * @param 
    */
    Fraction(int numerator = 1, int denominator = 1, string name ="");

    /*
    * @brief setter function for the numerator value
    * @param input the new numerator value
    */
    void SetNumerator(int input);

    /*
    * @brief setter function for the denominator value
    * @param input the new denominator value
    */
    void SetDenominator(int input);

    /*
    * @brief getter function for the numerator value
    * @return the numerator value
    */
    int GetNumerator() const;

    /*
    * @brief getter function for the denominator value
    * @return the denominator value
    */
    int GetDenominator() const;

    /*
    * @brief prints the fraction in the style numerator/denominator
    */
    void DisplayFraction() const;

    /*
    * @brief adds two fractions
    * @param other the fraction being added to the first
    * @return a new Fraction object that is the sum of the two inputs
    */
    Fraction operator+ (const Fraction& other) const;

    /*
    * @brief subtracts two fractions
    * @param other the fraction being subtracted from the first
    * @return a new Fraction object that is the difference of the two inputs
    */
    Fraction operator- (const Fraction& other) const;
    
    /*
    * @breif allows for direct reading of Fraction from input
    * @param in istream object for reading inputs
    * @param f the Fraction object that the inputs will be used to intialize
    * @return the instream for chaining
    */
    friend istream& operator>> (istream& in, Fraction& f);
};

/*
* @breif multiplies two Fractions
* @param lhs the first Fraction being multiplied
* @param rhs the second Fraction being multiplied
* @return a new Fraction that is the product of the two inputs
*/
Fraction operator* (const Fraction& lhs, const Fraction& rhs);

/*
* @breif divides two Fractions
* @param lhs the first Fraction (Divedend)
* @param rhs the second Fraction (Divisor)
* @return a new Fraction that is the quotient of the two inputs
*/
Fraction operator/ (const Fraction& lhs, const Fraction& rhs);

/*
* @breif outputs the Fraction in the form numer/denom
* @param out ostream object for output
* @param f the fraction being outputted
* @return the ostream for chaining
*/
ostream& operator<< (ostream& out, Fraction& f);


#endif