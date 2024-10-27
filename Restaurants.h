/*
    Title: restaurants.h
    Purpose: make the restaurants class
*/

#ifndef RESTAURANTS_H
#define RESTAURANTS_H

#include "LinkedList.h"
#include "SmartPointer.h"
#include "functions.h"

#include <iostream>
#include <string>

using namespace std;

class Restaurants
{
    private:
        string name, location, food;
        double rating;

    public:
        //constructor
        Restaurants(); //default
        Restaurants(string, string, string, double); //overloaded

        //deconstructor
        //~Restaurants();                           /*Does this destructor need to exist? -Gabe* /

        //setters
        void setName(string);
        void setLocation(string);
        void setFood(string);
        void setRating(double);

        //getters
        string getName();
        string getLocation();
        string getFood();
        double getRating();
};

#endif 