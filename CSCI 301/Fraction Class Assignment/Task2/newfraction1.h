/*
* @file fraction.cpp
* @brief header file that contains declarations for the Fraction class
* @date 9/4/2025
* @author Thomas Janckila
*/

#ifndef fraction
#define fraction
#include <string>
using std::string;

/*
* @breif the Fraction class stores a numerator and a denominator
* it has functions to call and set those values and one for printing the results
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
};

/*
* @brief adds two fractions
* @param a the first fraction
* @param b the fraction being added to the first
* @return a new Fraction object that is the sum of the two inputs
*/
Fraction AddFractions(const Fraction& a, const Fraction& b);

/*
* @brief subtracts two fractions
* @param a the first fraction
* @param b the fraction being subtracted from the first
* @return a new Fraction object that is the difference of the two inputs
*/
Fraction SubtractFractions(const Fraction& a, const Fraction& b);

/*
* @brief subtracts two fractions
* @param a the first fraction
* @param b the fraction being multiplied the first
* @return a new Fraction object that is the product of the two inputs
*/
Fraction MultiplyFractions(const Fraction& a, const Fraction& b);

/*
* @brief divides two fractions
* @param a the first fraction
* @param b the fraction being divided the first
* @return a new Fraction object that is the quotient of the two inputs
*/
Fraction DivideFractions(const Fraction& a, const Fraction& b);

#endif