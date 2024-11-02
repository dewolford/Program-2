#include "functions.h"
#include <iostream>
#include <limits>
using namespace std;
// Function to print the main menu
void printMenu() {
    cout << "\nRestaurant List Menu:\n";
    cout << "1. Add Restaurant\n";
    cout << "2. Display Restaurants\n";
    cout << "3. Sort Restaurants by Rating (highest to lowest)\n";
    cout << "4. Remove Restaurant by Name\n";
    cout << "5. Quit\n";
}

// Function to validate user input within a specified range
double validateInput(double value, double min, double max) {
    while (true) {
        cin >> value;
        if (cin.fail() || value < min || value > max) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard the newline character
            return value;
        }
    }
}
