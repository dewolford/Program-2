/*
    Title: restaurants.cpp
    Purpose: contains the functions from the restaurants class
*/

#include "LinkedList.h"
#include "SmartPointer.h"
#include "Restaurants.h"
#include "functions.h"

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
Restaurants::~Restaurants(){
    
}

//setters
    //sets the name of the restaurant
void Restaurants::setName(string newName){
    name = newName;
}
    //sets the location of the restaurant
void Restaurants::setLocation(string newLocation){
    location = newLocation;
}
    //sets the food the restaunrant sells
void Restaurants::setFood(string newFood){
    food = newFood;
}
    //sets the rating of the restaurant
void Restaurants::setRating(double newRating){
    rating = newRating;
}

//getters
    //returns the name of the restaurant
string Restaurants::getName(){
    return name;
}
    //returns the location of the restaurant
string Restaurants::getLocation(){
    return location;
}
    //returns the type of food the restaurant sells
string Restaurants::getFood(){
    return food;
}
    //returns the restaurants rating (0-5)
double Restaurants::getRating(){
    return rating;
}