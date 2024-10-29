/*
    Title: driver.cpp

                                                    / * DANI can you add a link to the repository here? thanks* /

    Purpose: Runs the main menu case statement
*/
#include "LinkedList.h"     //includes linked list functions
#include "SmartPointer.h"   //includes smart pointer functions
#include "Restaurants.h"    //includes restaurant functions
#include "functions.h"    //includes various other helper functions
#include <string>

using namespace std;

int main(){
    LinkedList linkLst;
    int choice; //contains the users choice for the menu
    int choice2;//contains the users choice for inside the menu
    bool cont = true; //used in the do while loop to determine if they quit or not
    string nameHolder, locationHolder, typeHolder,PHH;  //holds other restaurant information for constructor
    double ratingHolder;                                //holds restaurant rating for constructor
    Restaurants Rst;
    SmartPtr<string> ptr(new string());
    *ptr = PHH;
    double P = stod(PHH);
    list<SmartPtr<Restaurants>> restyList;
    auto itorator = restyList.begin();
    do {
        //prints the main menu
        printMenu();

        //takes and validates input 
        choice = (int)validateInput(choice, 1, 6);
        switch(choice){

            case 1:
                // add a restaurant case

                //reads in new restaurant information
                cout << "\n\nWhat is your restaurant name?";
                cin.ignore(10000, '\n'); //clears buffer before name is typed
                getline(cin, nameHolder);
                cout << "\n\nWhat is your restaurant location?";
                getline(cin, locationHolder);
                cout << "\n\nWhat is your restaurant's type of food?";
                getline(cin, typeHolder);
                cout << "\n\nWhat is your restaurant rating?";
                validateInput(ratingHolder, 0, 5);
                
                restyList.push_back(SmartPtr<Restaurants>(new Restaurants(nameHolder, locationHolder, typeHolder, ratingHolder)));
                Restaurants(nameHolder, locationHolder, typeHolder, ratingHolder);/*idk if this is right please double check*/
                /*call append list funtion? with constructed restaurant*/    
                linkLst.insertAtBack(itorator);
                break;
            case 2: 
                //delete a restaurant case
                for (auto it = restyList.begin(); it != restyList.end(); it++ )
                {   if((*it)->getName/*would work if added to restarunt.h so it accesses name directly*/ == nameHolder)
                        restyList.erase(it);
                        break;
                }
                restyList;
                /*call destructor for restaurant?*/                 /*idk if this is right please double check*/
                /*call remove list function?*/

                break;
            case 3: 
                //display a restaurant case
                cout << "\nDisplay one restaurant(1) or all restaurants(2)?";
                validateInput(choice2, 1, 2);
                if (choice2 == 1){
                    /*call << Restaurant function*/
                } else {
                    /*call << Restaurant function for all in list (sorry), this can be done in a for statement if need be*/
                }
                break;
            case 4:
                //sort restaurant list case
                linkLst.sort();
                break;
            case 5: 
                //Compare restaurants case
                linkLst.compare();
                break;
            default:    //this case quits if any number besides 1-5 are entered
                //quit case

                cout << "\n\nYou have successfully quit! Thanks for visiting!";
                cont = false;
                break;
        }
    } while(cont);//continues to loop if anything but quit is chosen

    return 0;//end of code

}