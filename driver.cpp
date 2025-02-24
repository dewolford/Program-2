/*
    Title: driver.cpp

    https://github.com/dewolford/Program-2

    Purpose: Runs the main menu in a case statement format
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
    bool correct = false; //used to determine if the correct name has been found while searching the list
    bool tryAgain = true; //used to determine if the user wants to try again 
    string nameHolder, locationHolder, typeHolder,PHH;  //holds other restaurant information for constructor
    double ratingHolder;    //holds the rating of the restaurant for the constructor
    LinkedList::Node* currentNode = linkLst.getHeadPtr();   //hold the current node in the linked list while parcing
    LinkedList::Node* displayedRestaurant;  //hold the node of the linked list that will be displayed
    Restaurants *Rst;
    SmartPtr<string> ptr(new string());
    //*ptr = PHH;
    //double P = stod(PHH);
    list<SmartPtr<Restaurants> > restaurantList;
    //auto itorator = restaurantList.begin();
    do {
        //prints the main menu
        printMenu();

        //takes and validates input 
        choice = (int)validateInput((double)choice, 1, 6);
        switch(choice){

            case 1:
                // add a restaurant

                //reads in new restaurant information
                cout << "\n\nWhat is your restaurant name?";
                cin.ignore(10000, '\n'); //clears buffer before name is typed
                getline(cin, nameHolder);
                cout << "\n\nWhat is your restaurant location?";
                getline(cin, locationHolder);
                cout << "\n\nWhat is your restaurant's type of food?";
                getline(cin, typeHolder);
                cout << "\n\nWhat is your restaurant rating (0.0-5.0)?";
                ratingHolder = validateInput(ratingHolder, 0, 5);
                
                Rst = new Restaurants(nameHolder, locationHolder, typeHolder, ratingHolder);

                //restyList.push_back(SmartPtr<Restaurants>(Rst));  
                
                //calls append list funtion with constructed restaurant
                linkLst.addRestaurant(Rst);
                break;

            case 2: 
                //deletes a restaurant
                cout << "\nWhat is the name of the Restaurant you want to delete? (copy name as shown)";
                linkLst.printList();
                cin.ignore(10000, '\n'); //clears buffer before name is typed
        
                getline(cin, nameHolder);
                linkLst.deleteRestaurant(nameHolder);
                break;

            case 3: 
                //display a restaurant 
                cout << "\nDisplay one restaurant(1) or all restaurants(2)?";
                linkLst.printList();

                cin.ignore(10000, '\n'); //clears buffer before name is typed
                choice2 = validateInput(choice2, 1, 2);
                if (choice2 == 1){
                    do{

                        cout << "\nWhat is the name of the restaurant you want to display?\n";
                        cin.ignore(10000, '\n'); //clears buffer before name is typed
                        getline(cin, nameHolder);
                        for (int i = 0;i< linkLst.getSize(); i++){
                            if (nameHolder == currentNode->restaurant->getName()){
                                displayedRestaurant = currentNode;
                                break;
                            }
                            //Moves to the next node
                            currentNode = currentNode->next; 
                        }
                        //if (nameHolder != currentNode->restaurant->getName()){
                            cout << "\nCould not find restaurant: " << nameHolder << ". Would you like to try again(1) or quit?(2)\n";
                            choice2 = validateInput(choice2, 1,2);
                            if (choice2 == 1){
                                
                            } else{
                                tryAgain = false;
                                correct = true;
                            }
                       // }
                    } while  (!correct);
                    if (tryAgain){
                        //prints restaurant using its << operator
                        cout << currentNode->restaurant;
                    }
                } else {
                    linkLst.printList();
                }
                break;

            case 4:
                //sort restaurant list
                
                //calls sort function that sorts the linked list
                linkLst.sort();
                break;
            case 5: 
                //Compare restaurants
                cin.ignore(10000, '\n'); //clears buffer before name is typed
                linkLst.compare();
                break;
            default:    //this case quits if any number besides 1-5 are entered
                //quit case
                
                cout << "\n\nYou have successfully quit! Thanks for visiting!\n\n";
                cont = false;
                break;
        }
    } while(cont);//continues to loop if anything but quit is chosen

    return 0;//end of code

}