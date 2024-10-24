/*
    Title: classes.cpp
    Purpose: hold all functions necessary for the classes made in classes.h
*/
#include "LinkedList.h"
#include "SmartPointer.h"
#include "Restaurants.h"

using namespace std;

//constructors
ListClass()
{
    headPtr = 0;
    tailPtr = 0;
    size = 0;
}

ListClass(int* h, int* t, int s)
{
    headPtr = h;
    tailPtr = t;
    size = s;
}

//destructor

//setters
void setHeadPtr(int* h)
{
    headPtr = h;
}

void setTailPtr(int* t)
{
    tailPtr = t;
}

void setSize(int s)
{
    size = s;
}



//getters
int* getHeadPtr()
{
    return headPtr;
}

int* getTailPtr()
{
    return tailPtr;
}

int getSize()
{
    return size;
}

//add to list (append, prepend, insert)
    /*please add the following line of code to the end of the function*/
    cout << "\nSuccessfully added to restaurant list!\n";

//get from list (back, front, at)

//remove from list (pop, remove, etc)
    /*please add the following line of code to the end of the function*/
    cout << "\nSuccessfully removed from restaurant list!\n";

//sorting function
    /*please add the following line of code to the end of the function*/
    cout << "\nSuccessfully sorted restaurant list!\n";

//stream opperator (<<)

//compare function 
    /*this one should be simple. all it does is take two objects as arguments, takes the 
    ratings, and prints "this restaraunt (rating) is rated higher than that restaurant 
    (rating)" or "this restaraunt and that restaraunt are rated equally (rating)"*/