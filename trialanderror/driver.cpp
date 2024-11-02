#include "LinkedList.h"
#include "Restaurant.h"
#include "functions.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    LinkedList<Restaurant> restaurantList;
    int choice;

    while (true) {
        printMenu();  // Use the function to print the menu
        cout << "Enter your choice: ";
        
        // Use validateInput for choice to ensure it's within valid bounds
        choice = static_cast<int>(validateInput(choice, 1, 6));

        switch (choice) {
            case 1: {
                string name, location, food;
                double rating;
                
                cout << "Enter the restaurant name: ";
                getline(cin, name);
                
                cout << "Enter the restaurant location: ";
                getline(cin, location);
                
                cout << "Enter the type of food: ";
                getline(cin, food);
                
                cout << "Enter the rating (0-5): ";
                rating = validateInput(rating, 0, 5);  // Use validateInput for rating

                // Add restaurant to the linked list
                restaurantList.append(new Restaurant(name, location, food, rating));
                break;
            }
            case 2:
                cout << "\nRestaurants:\n" << restaurantList << endl;
                break;
            case 3:
                restaurantList.sort();  // Sorts in descending order by rating
                cout << "\nRestaurants sorted by rating (highest to lowest).\n";
                break;
            case 4: {
                string name;
                cout << "Enter the name of the restaurant to remove: ";
                getline(cin, name);
                restaurantList.deleteRestaurant(name);
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
