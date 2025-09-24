#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //varible declaration
    // occ short for Occupied
    int numFloors;
    int numRooms;
    int occRooms;
    double roomTotal;
    double totalOcc;
    int i;
    roomTotal = 0;
    totalOcc = 0;
    
    //Ask user for number of floors
    cout << "How many floors are in the hotel? Numbers lower than 1 will be set to 1." << endl;
    cin >> numFloors;
    if (numFloors < 1) { //check if less than one, set to one if true
        numFloors = 1;
    }

    // loop for rooms on each floor
    for (i = 0; i < numFloors; i++) {

        if (i == 13) {
            continue;
        }

        if (i == 0) {
            cout << "How many rooms are on the ground floor?" << endl;
        }
        else {
            cout << "How many rooms are on the " << i << " floor." << endl;
        }

        cin >> numRooms;
        if (numRooms < 10) { //check if less than 10. set to ten if true
            numRooms = 10;
        }
        roomTotal += numRooms;
        
        if (i == 0) {
            cout << " When entering occupied rooms, numbers less than 0 will be set to 0. Numbers greater than the number of rooms on the floor will be set to that number" << endl;
        }

        cout << "Enter the number of occupied rooms on floor number " << i << endl; 
            cin >> occRooms;

            if (occRooms < 0) { //check if less than 0
                occRooms = 0;
            }
            else if (occRooms > numRooms) {
                occRooms = numRooms;
            }
            totalOcc += occRooms;
    }

    //Data output
    cout << "The number of rooms in the hotel is " << roomTotal << "." << endl;
    cout << "The number of occupied rooms in the hotel is " << totalOcc << "." << endl;
    cout << "The number of unoccupied rooms in the hotel is " << roomTotal - totalOcc << "." << endl;
    cout << fixed << setprecision(2) << "The percentage of occupied rooms in the hotel is " << (totalOcc / roomTotal) * 100 << "%." << endl;

    return 0;
}