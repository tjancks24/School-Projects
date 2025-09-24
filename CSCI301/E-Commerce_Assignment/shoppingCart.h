/**
 * @brief declarations of the shoppingCart class
 * @name Thomas Janckila 
 * @date 9/22/25
 * @instructor Jie Hu Meichsner
 */

#ifndef SHOPPINGCART
#define SHOPPINGCART
#include <string>
#include <iostream>
#include <iomanip>
#include "Bag.h"
#include "item.h"
using std::string;
using namespace std;



class ShoppingCart:public Bag<Item> {
    private:
    double totalPrice;

    public:
    ShoppingCart(double totalPrice = 0.0);
    double GetTotalPrice();
    bool add(const Item &newItem);
    bool remove(const Item &anItem);
    void clear();
};

#endif