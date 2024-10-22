/*
    Title: driver.cpp
    Purpose: Runs the main menu case statement
*/
#include "LinkedList.h"     //includes linked list functions
#include "SmartPointer.h"   //includes smart pointer functions
#include "Restaurants.h"    //includes restaurant functions
#include "functions.cpp"    //includes various other helper functions

using namespace std;

int main(){

    int choice; //contains the users choice for the menu
    bool cont = true; //used in the do while loop to determine if they quit or not

    
    do {
        //prints the main menu
        printMenu();                /*why is this erroring? can someone fix if its still here? thanks -Gabe*/
        //takes and validates input 
        validateInput(choice);      //this is borrowed from project 1

        switch(choice){

            case 1:
                // add a restaurant case

                /*call constrctor for restaurant?*/
                /*call append list funtion*/

                break;
            case 2: 
                //delete a restaurant case

                /*call destructor for restraunt*/
                /*call remove list function*/
                break;
            case 3: 
                //display a restaurant case

                /*call << Restaurant function*/
                break;
            case 4:
                //sort restaurant list case

                /*AHHHHHHHHHHH (call sort linked list function? maybe smart pointer idk)*/
                break;
            case 5: 
                //Compare restaurants case

                /*call restaurant < or > or = idk yet ill figure it out -Gabe*/
                break;
            default:
                //this case quits if any number besides 1-5 are entered
                cout << "\n\nYou have successfully quit! Thanks for visiting!";
                cont = false;
                break;
        }
    } while(cont);//continues if anything but quit is chosen

    return 0;//end of code

}/* its giving me an error here but i think its trippin, if not, my Bad-Gabe*/