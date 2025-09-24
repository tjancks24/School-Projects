/*
* @file fraction.cpp
* @brief header file that contains declarations for the Fraction class
* @date 9/4/2025
* @author Thomas Janckila
*/

#ifndef fraction
#define fraction

/*
* @breif the Fraction class stores a numerator and a denominator
* it has functions to call and set those values and one for printing the results
*/

class  Fraction {
    private:
    int numerator; ///< numerator (top) of the fraction
    int denominator; ///< denominator (bottom) of the fraction

    public:
    /*
    * @breif default constructor with the option to pass values or use deafaults
    * @param numerator numerator of the fraction. Default of 1
    * @param denominator numerator of the fraction. Default of 1
    */
    Fraction(int numerator = 1, int denominator = 1);

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
    int GetNumerator();

    /*
    * @brief getter function for the denominator value
    * @return the denominator value
    */
    int GetDenominator();
    
    /*
    * @brief prints the fraction in the style numerator/denominator
    */
    void DisplayFraction();

};

#endif