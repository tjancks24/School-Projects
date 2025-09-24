/**
 * @brief implementations of the shoppingCart class
 * @name Thomas Janckila 
 * @date 9/22/25
 * @instructor Jie Hu Meichsner
 */

#include <string>
#include <iostream>
#include <iomanip>
#include "shoppingCart.h"
#include "Bag.h"
#include "item.h"
using std::string;
using namespace std;

/**
 * @brief initializes a new shoppingCart object from given inputs, if none are given defaults are used
 * also calls the base class constructor
 * 
 * @param totalPrice totalPrice for the new shoppingCart object, default of 0.0
 * 
 * @post new initialized shoppingCart item with totalPrice
 */

ShoppingCart::ShoppingCart(double totalPrice): Bag<Item>(){
    this->totalPrice = totalPrice;
}

/**
 * @brief getter for the price of the cart
 * 
 * @return the price of the cart
 */

double ShoppingCart::GetTotalPrice() {
    return totalPrice;
}

/**
 * @brief overloader for the base class' add function
 * in addition to adding the new item it updates total price based on the items data members (price * quantity)
 * 
 * @param newItem the item to be added to the cart
 * 
 * @post cart object and totalPrice are updated with another item if it can be and, otherwise nothing is changed
 * 
 * @return true if the item can be added, false if it cannot
 */

bool ShoppingCart::add(const Item &newItem) {
   bool canAdd = Bag<Item>::add(newItem);
    if(canAdd) {
        totalPrice += newItem.getPrice() * newItem.getQuantity();
    }

    return canAdd;
}

/**
 * @brief overloader for the class' remove function
 * in addition to removing an item it removes its price from the cart's totalPrice (price * quantity)
 * 
 * @param anItem the item to be removed
 * 
 * @post  total price is reduced and the item is removed from the object if it can be, otherwise nothing is changed
 * 
 * @return true if the item can be removed, false if it cannot
 */

bool ShoppingCart::remove(const Item &anItem) {
    bool canRemove = Bag<Item>::remove(anItem);
    if(canRemove) {
        totalPrice -= anItem.getPrice() * anItem.getQuantity();
    }

    return canRemove;
}

/**
 * @brief overloader of the base class' clear function
 * in addition to removing all items it sets totalPrice to zero to reflect the empty cart
 * 
 * @post all items are removed from the cart, and total price is reset to 0.0
 */

void ShoppingCart::clear() {
    Bag<Item>::clear();
    totalPrice = 0.0;
}