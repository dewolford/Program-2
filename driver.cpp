/*
    Title: driver.cpp

    / * DANI can you add a link to the repository here? thanks* /

    Purpose: Runs the main menu case statement
*/
#include "LinkedList.h"     //includes linked list functions
#include "SmartPointer.h"   //includes smart pointer functions
#include "Restaurants.h"    //includes restaurant functions
#include "functions.cpp"    //includes various other helper functions

using namespace std;

int main(){

    int choice; //contains the users choice for the menu
    int choice2;//contains the users choice for inside the menu
    bool cont = true; //used in the do while loop to determine if they quit or not

    
    do {
        //prints the main menu
        printMenu();

        //takes and validates input 
        validateInput(choice);

        switch(choice){

            case 1:
                // add a restaurant case
                cout << "\n\nWhat is your restaurant name?";
                getline(/*string holder*/);
                cout << "\n\nWhat is your restaurant location?";
                getline(/*string holder*/);
                cout << "\n\nWhat is your restaurant rating?";
                cin >> /*double holder*/;
                cout << "\n\nWhat is your restaurant's type of food?";
                getline(/*string holder*/);
                /*call constrctor for restaurant?*/


                /*call append list funtion?*/

                break;
            case 2: 
                //delete a restaurant case

                /*call destructor for restaurant?*/
                /*call remove list function?*/

                break;
            case 3: 
                //display a restaurant case
                cout << "\nDisplay one restaurant(1) or all restaurants(other number)?";
                validateInput(choice2);
                if (choice2 == 1){
                    /*call << Restaurant function*/
                } else {
                    /*call << Restaurant function for all in list (sorry), this can be done in a for statement if need be*/
                }
                break;
            case 4:
                //sort restaurant list case
                
                /*call sort linked list sort function*/
                
                break;
            case 5: 
                //Compare restaurants case
                /*asks for both restaurant names*/
                /*call compare restaurant function with two restaurants as arguments*/
                break;
            default:
                //this case quits if any number besides 1-5 are entered
                cout << "\n\nYou have successfully quit! Thanks for visiting!";
                cont = false;
                break;
        }
    } while(cont);//continues to loop if anything but quit is chosen

    return 0;//end of code

}