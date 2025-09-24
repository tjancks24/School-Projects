/**
 * @brief file for implementing and using the item and shoppingCart class
 * @name Thomas Janckila 
 * @date 9/22/25
 * @instructor Jie Hu Meichsner
 */

#include <string>
#include <iostream>
#include <iomanip>
#include "item.cpp"
#include "shoppingCart.cpp"
using std::string;
using namespace std;

/**
* @brief handles the creation of new items from user input
*
* @post returns a fully intialized item from user input
*
* @return the created item
*
**/

Item CreateItem() {
    Item newItem;


    cout << "--> ";
    cin >> newItem;
    cout << endl;

    return newItem;
}

/**
 * @brief determines if the inputted item is in the inputted cart
 * 
 * @param checkItem the item being searched for
 * @param cart the cart object being searched through
 * 
 * @return true if the item is in the cart, false otherwise
 */

bool ItemExists(Item checkItem, ShoppingCart& cart) {
    bool contains;
    
    contains = cart.contains(checkItem);
    return contains;
}

/**
 * @brief allows the user to make changes to items in their cart
 * 
 * If not simply moves on
 * Otherwise the user can add new item or remove or modify quantity of existing items
 * 
 * @post If the user added there will be a new item in the cart
 * If they removed an item it will not be in the cart
 * If the modified an item its quantity will have changed
 * If no action is made the cart is unchanged
 * 
 * @param cartAction set to true if an action is made, false otherwise
 * @param userAction determines if the user wants to make an action, then reused to determine which action
 * @param cart reference to the cart being modified
 * 
 * @return true if the user choose to make an action, false if not
 */

bool CartOptions(bool& cartAction, char userAction, ShoppingCart& cart) {
    if (userAction == 'y') {

        cout << "What do you want to do? add: 1,  remove: 2,  change quantity: 3" << endl;
        cout << "--> ";
        cin >> userAction;
        cartAction = true;

        if (userAction == '1') {

            Item newItem;
            cout << "Please enter in order: Name, Unit Price, Quantity, of the item you want to add." << endl;
            newItem = CreateItem();
            cart.add(newItem);
            cout << "Item added" << endl;

            cartAction = true;
        }
        else if (userAction == '2') {
            bool exists = true;
            Item item;

            while (exists) {
                
                cout << "Please enter in order: Name, Unit Price, Quantity, of the item you want to remove." << endl;
                
                item = CreateItem();

                if (ItemExists(item, cart)) {
                    cart.remove(item);
                    cout << "Item removed" << endl;
                    exists = false;
                } else {
                    cout << "No entry matches the entered item. Double check and try again" << endl;
                }
            }
            cartAction = true;
        }
        else if (userAction == '3') {
            bool exists = true;
            Item item;

            while (exists) {
                
                cout << "Please enter in order: Name, Unit Price, Quantity, of the item you would like to modify." << endl;
                
                item = CreateItem();

                if (ItemExists(item, cart)) {
                    bool validQuant = true;

                    while (validQuant) {
                        int newQuant;

                        cout << "Enter the new Quantity" << endl;
                        cout << "--> ";
                        cin >> newQuant;

                        if (newQuant > 0) {
                            cart.remove(item);

                            item.setQuantity(newQuant);
                            cart.add(item);
                            cout << "Item modified" << endl;
                            validQuant = false;
                        }
                        else {
                            cout << "Invalid quantity entered. Try again." << endl;
                        }
                    }
                    exists = false;
                } else {
                    cout << "No entry matches the entered item. Double check and try again" << endl;
                }
            }
            cartAction = true;
        }
        return cartAction;
    }
    else {
        cartAction = false;
        return cartAction;
    }
}

/**
 * @brief prints every item from a vector using a loop
 * 
 * @post the items of the vector are displayed
 * 
 * @param itemVector vector of items to be printed
 */

void PrintCart(vector<Item>& itemVector) {
    for (int i = 0; i < static_cast<int>(itemVector.size()); i++) {
        cout << itemVector[i] << endl;
    }
}

/**
 * @brief creates formatted output for the items of shoppingCart objects
 * 
 * @pre must have a vector made from the items of the cart being printed
 * 
 * @post formatted output for items and then the total price of items
 * 
 * @param itemVector vector of items to be printed
 * @param cart reference to the cart the items belong to 
 */

void ShowCart(vector<Item>& itemVector, ShoppingCart& cart) {
    cout << setw(60) << setfill('-') << "" << endl <<
    left << setw(25) << setfill(' ') << "Name:" <<
    right << setw(15) << "Price:" << 
    right << setw(15) << "Quantity:" << endl; //output formatting needs work on item.cpp
    PrintCart(itemVector);
    cout << "The total charge is: $" << cart.GetTotalPrice() << endl;
    cout << setw(60) << setfill('-') << "" << endl;
}

int main() {
    ShoppingCart cart1;
    bool addItem = true;
    bool cartActions = true;
    Item newItem;
    char userAction;
    vector<Item> itemVector;

    cout << "Welcome to the CSCI 301 Shopping Center!" << endl;
    cout << "Please enter the items you ordered in the following order with space between each" << endl;
    cout << "Do not put spaces in the names, otherwise there will be errors" << endl;
    cout << "Name, Unit Price, Quantity" << endl;

    while(addItem) {
        
        newItem = CreateItem();
        cart1.add(newItem);

        cout << "Want to add another Item? y/n --> ";
        cin >> userAction;
        cout << endl;

        if (userAction == 'n') {
            addItem = false;
        }
    }

    itemVector = cart1.toVector();

    cout << "Here is your order:" << endl;
    ShowCart(itemVector, cart1);

    while(cartActions) {
        cout << "Do you want to modify your order? y/n --> ";
        cin >> userAction;
        cartActions = CartOptions(cartActions, userAction, cart1);
    }

    itemVector = cart1.toVector();

    cout << "Here is your final order:" << endl;
    ShowCart(itemVector, cart1);
    cout << "Thank you for shopping at CSCI 301 Shopping Center!" << endl;

    return 0;
}


