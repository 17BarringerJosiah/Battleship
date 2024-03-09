// Project8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// <Project8> -- Programming: MULTI-ARRAY Assignment
// CSIS111-<B01>

#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 25;

char ocean[SIZE][SIZE];

// initialize the ocean
void createOcean(const char* filename) {
    ifstream file(filename);

//error statement for if the file does not open
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        exit(EXIT_FAILURE);
    }

//for loop that uses the ocean
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            file >> ocean[i][j];
        }
    }

    file.close();
}

//display the ocean using the for loop
void displayOcean() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << ocean[i][j] << " ";
        }
        cout << endl;
    }
}

//if-else statement for the shoot ability of the user
void Shoot(int x, int y) {
    if (ocean[x][y] == '#') {
        if (ocean[x][y] == 'H') {
            cout << "HIT AGAIN" << endl;
        }
        else {
            cout << "HIT" << endl;
            ocean[x][y] = 'H';
        }
    }
    else {
        cout << "MISS" << endl;
    }
}

// boolean that will tell if the fleet is sunk or not
bool FleetSunk() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (ocean[i][j] == '#') {
                return false;
            }
        }
    }
    return true;
}

int main() {

    cout << "Josiah Barringer -- CSIS111_B01" << endl << endl;
 
    // uses text file batttleground
    const char* filename = "battleground.txt";
    createOcean(filename);

    //while loop for the user to enter coordinates as guesses to where the ships are
    while (!FleetSunk()) {
        int x, y;
        cout << "Enter coordinates (X Y): ";
        cin >> x >> y;

    //prints an error message if the user enters coordinates that are not available for them to shoot at
        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            cout << "Invalid coordinates." << endl;
            continue;
        }

        Shoot(x, y);
    }

    //prints message to user when all ships are sunk
    cout << "You sunk the fleet!" << endl;
    displayOcean();

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
