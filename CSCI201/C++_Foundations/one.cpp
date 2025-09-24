#include <iostream>
using namespace std;


int main () {

    //Variable Declaration
    string userName;
    int userAge;
    int favNum;

    cout << "Welcome to the C++ introduction program!" << endl << endl;
    //Asking users for their information
    cout << "What is your name?" << endl;
    cin >> userName;
    cout << "How old are you?" << endl;
    cin >> userAge;
    cout << "What is your favorite number?" << endl;
    cin >> favNum;

    //Greeting message plus age in ten years
    cout << "Hello " << userName << " you are currently " << userAge << " years old." <<
     " In 10 years you will be " << userAge + 10 << "." << endl; 

    //Checking if favorte number is even or odd and outputting the correct response
    if ((favNum % 2) == 0) {
        cout << "Your favorite number, which is " << favNum << ", is an even number." << endl;
    }
    else {
        cout << "Your favorite number, which is " << favNum << ", is an odd number." << endl;
    }

    //Checking what age range the user is in and outputting the correct response
    if (userAge < 18) {
        cout << "You are a teenager! Enjoy your youth." << endl;
    }
    else if ((userAge >= 18) && (userAge <= 30)) {
        cout << "You are in your prime years! Make the most of it." << endl;
    }
    else {
        cout << "Experience is valuable! Keep learning and growing." << endl;
    }
    return 0;
};