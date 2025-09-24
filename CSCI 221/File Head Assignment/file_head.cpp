#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    //Variable Declaration
    string fileName;
    string currLine;
    int lineCounter = 0;
    ifstream inFS;
    
    cout << "Please enter the file you wish to display" << endl;
    cin >> fileName;

    inFS.open(fileName);
    //Check if file can be opened/exists
    if(!inFS.is_open()) {
        cout << "File name \"" << fileName << "\" was unable to be opened" << endl;
        return 1;
    }
    //Loop to output the file contents
    while (getline(inFS, currLine) && lineCounter < 10) {
        cout << currLine << endl;
        lineCounter++;
    }

    inFS.close();
    //Checking if less than 10 lines were displayed
    //Or if the file was empty
    if (lineCounter < 10) {
        if (lineCounter < 1) {
            cout << "The chosen file was empty" << endl;
        }
        else {
            cout << "Fewer than 10 lines were shown" << endl;
        }
    }
    
    return 0;
}