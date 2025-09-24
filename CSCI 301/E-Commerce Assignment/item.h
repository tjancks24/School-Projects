/**
 * @brief declarations of the item class
 * @name Thomas Janckila StarID: cd2898vx
 * @date 9/22/25
 * @instructor Jie Hu Meichsner
 */

#ifndef ITEM
#define ITEM
#include <string>
#include <iostream>
#include <iomanip>
using std::string;
using namespace std;

class Item {
    private:
    string name;
    double price;
    int quantity;

    public:
    Item(string name = "", double price = 0.0, int quantity = 0);

    void setName(string input);

    void setPrice(double input);

    void setQuantity(int input);

    string getName() const;

    double getPrice() const;

    int getQuantity() const;
};


bool operator== (const Item& lhs, const Item& rhs);

istream& operator>> (istream& in, Item& I);

ostream& operator<< (ostream& out, Item& I);
#endif