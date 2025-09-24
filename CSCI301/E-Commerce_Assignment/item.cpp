/**
 * @brief implementations of the item class
 * @name Thomas Janckila StarID: cd2898vx
 * @date 9/22/25
 * @instructor Jie Hu Meichsner
 */

#include <string>
#include <iostream>
#include <iomanip>
#include "item.h"
using std::string;
using namespace std;

/**
 * @brief initializes a new Item object with inputs, if none are given uses defaults
 * 
 * @param name name of the new item, default value of ""
 * @param price price of the new item, default value of 0.0
 * @param quantity quantity of the new item, default value of 0
 * 
 * @post newly created Item object with user defined or default inputs
 */

Item::Item(string name, double price, int quantity) {
    this->name = name;
    this->price = price;
    this-> quantity = quantity;
};

/**
 * @brief setter for the name of the item
 * 
 * @post the items name will be updated to the input
 * 
 * @param input string to be used as the new name
 */

void Item::setName(string input) {
    name = input;
};

/**
 * @brief setter for the price of the item
 * 
 * @post the items price will be updated to the input
 * 
 * @param input double to be used as the new price
 */

void Item::setPrice(double input) {
    price = input;
};

/**
 * @brief setter for the quantity of the item
 * 
 * @post the items quantity will be updated to the input
 * 
 * @param input int to be used as the new quantity
 */

void Item::setQuantity(int input) {
    quantity = input;
};

/**
 * @brief getter for retreiving the name of the item
 * 
 * @return the name of the object
 */

string Item::getName() const {
    return name;
};

/**
 * @brief getter for retreiving the price of the item
 * 
 * @return the price of the object
 */


double Item::getPrice() const {
    return price;
};

/**
 * @brief getter for retreiving the quantity of the item
 * 
 * @return the quantity of the object
 */

int Item::getQuantity() const {
    return quantity;
};

/**
 * @brief == overloader for easy compairison of two objects of the item class
 * 
 * compares name, price and quantity of the two inputted items
 * 
 * @note is not a member function
 * 
 * @param lhs first item to be compared
 * @param rhs second item to be compared
 * 
 * @return true if the two items are the same, false if they are not
 */

bool operator== (const Item& lhs, const Item& rhs) {
    if (lhs.getName() == rhs.getName() && lhs.getPrice() == rhs.getPrice() && lhs.getQuantity() == rhs.getQuantity()) {
        return true;
    }
    return false;
};

/**
 * @brief input overloader for simpler code and easier readibilty when creating item objects
 * 
 * takes user for input for name, price, and quantity and then assigns them to their respective data members
 * 
 * @pre assumes the user inputs name, price, and quantity in order
 * @post updated item object with user updated name, price, and quantity
 * 
 * @param in istream operator to be overloaded
 * @param I item whos data members are to be updated
 * 
 * @return istream for chaining multiple inputs if desired
 */

istream& operator>> (istream& in, Item& I) {
    string name;
    double price;
    int quantity;

    in >> name >> price >> quantity;
    I.setName(name);
    I.setPrice(price);
    I.setQuantity(quantity);

    return in;
};

/**
 * @brief output overloader for simpler and more readable code
 * 
 * formatted output for name, price, and quantity to fit in tables
 * 
 * @post output of each of the data members of the item class
 * 
 * @param out ostream operator to be overloaded
 * @param I item whos data is to be outputted
 * 
 * @return ostream for chaining if desired
 */

ostream& operator<< (ostream& out, Item& I) {
    out << left << setw(20) << I.getName() << setfill(' ') << 
    right << setw(15) << "$" << fixed << setprecision(2) << I.getPrice() <<  
    right << setw(15) << I.getQuantity();
    return out;
}