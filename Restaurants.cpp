/*
    Title: restaurants.cpp
    Purpose: contains the functions from the restaurants class
*/
#include "LinkedList.h"
#include "SmartPointer.h"
#include "Restaurants.h"

using namespace std;

//default constructor
Restaurants::Restaurants(){
    name = "Restaurant Name";
    location = "Cookeville";
    food = "Good Food!";
    rating = 2.5;

    
} 

//overloaded constructor
Restaurants::Restaurants(string name, string location, string food, double rating){
    this->name = name;
    this->location = location;
    this->food = food;
    this->rating = rating;
} 

//destructor
/*
Restaurants::~Restaurants(){
    delete name;
    delete location;                        /*Does this destructor need to exist? -Gabe* /
    delete food;
    delete rating;
}*/

//setters
void Restaurants::setName(string newName){
    name = newName;
}
void Restaurants::setLocation(string newLocation){
    location = newLocation;
}
void Restaurants::setFood(string newFood){
    food = newFood;
}
void Restaurants::setRating(double newRating){
    rating = newRating;
}

//getters
string Restaurants::getName(){
    return name;
}
string Restaurants::getLocation(){
    return location;
}
string Restaurants::getFood(){
    return food;
}
double Restaurants::getRating(){
    return rating;
}