/*
    Title: restaurants.h
    Purpose: make and store the restaurants class and its various functions
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

        //destructor
        ~Restaurants();

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
        
        //overloaded << operator
        friend std::ostream& operator<<(std::ostream& os, const Restaurants& restaurants) {
            os << restaurants.name << " (" << restaurants.rating << ") in " << restaurants.location << " sells " << restaurants.food << "."; /* */
            return os;
        }

        // == boolean operator
        bool operator==(const Restaurants& right_comparison) {
            return this->rating == right_comparison.rating;
        }

        // < boolean operator
        bool operator < (const Restaurants& right_comparison) { 
            return this->rating  < right_comparison.rating;
        }
        
        // > boolean operator
        bool operator > (const Restaurants& right_comparison) {
            return this->rating > right_comparison.rating;
        }
};

#endif 