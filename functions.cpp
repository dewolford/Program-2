/*
    Title: functions.cpp
    Purpose: hold the extra functions 
*/
#include <iostream>

using namespace std;

void printMenu();
int validateInput(int);

                            /*is this formatting right? -Gabe*/

void printMenu(){
    cout << "MAIN MENU (Enter a Number):\n\t(1) Add a Restaurant\n\n\t(2) Delete a Restaurant\n\n\t(3) Display a Restaurant\n\n\t(4) Sort Restaurants\n\n\t(5) Compare Restaurants\n\n\t(6) Quit\n\n";
}
int validateInput(int num)
{
    while(!(cin >> num))
    {
        cout << "Please enter a valid number" << endl;
        cin.clear(); //clears all stream bits (good, bad, eof, fail)
        cin.ignore(10000, '\n'); //removes up to 10000 characters from buffer until a newline is removed
        cout << "\nEnter a number: ";
    }
    return num;
}