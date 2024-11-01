/*
    Title: functions.cpp
    Purpose: hold the extra functions d:^)-><
*/
#include <iostream>

using namespace std;

//prints the main menu
void printMenu(){
    cout << "\nMAIN MENU (Enter a Number):\n\t(1) Add a Restaurant\n\n\t(2) Delete a Restaurant\n\n\t(3) Display a Restaurant\n\n\t(4) Sort Restaurants\n\n\t(5) Compare Restaurants\n\n\t(6) Quit\n\n";
}

//validates double input in a range between two ints
double validateInput(double dub, int min, int max){
    while(!(cin >> dub)|| dub < min || max < dub){
        cout << "Please enter a valid number inside the bounds" << endl;
        cin.clear();
        cin.ignore(10000, '\n'); //removes up to 10000 characters from buffer until a newline is removed
        cout << "\nEnter a number: ";
    }
    return dub;
}