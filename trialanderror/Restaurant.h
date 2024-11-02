#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <iostream>
using namespace std;
class Restaurant {
private:
    string name;
    string location;
    string foodType;
    double rating;
    

public:
    Restaurant(string n = "", string l = "", string f = "", double r = 0.0)
        : name(n), location(l), foodType(f), rating(r) {}

    string getName() const { return name; }
    double getRating() const { return rating; }

    friend ostream& operator<<(ostream& out, const Restaurant& res) {
        out << res.name << " at " << res.location << ", serves " << res.foodType
            << ", rated " << res.rating;
        return out;
    }

    // Operator for descending order (highest rating to lowest)
    bool operator>(const Restaurant& other) const { return rating > other.rating; }
};

#endif
