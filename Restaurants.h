/*
    Title: restaurants.h
    Purpose: make the restaurants class
*/

#ifndef RESTAURANTS_H
#define RESTAURANTS_H

#include "LinkedList.h"
#include "SmartPointer.h"

#include <iostream>
#include <string>

using namespace std;

class Restaurants
{
    private:
        string name, location, food;

    public:
        //constructor
        Restaurants(); //default
        Restaurants(string, string, string); //overloaded

        //deconstructor
        ~Restaurants();

        //setters
        void setName(string);
        void setLocation(string);
        void setFood(string);

        //getters
        string getName();
        string getLocation();
        string getFood();
};

#endif 