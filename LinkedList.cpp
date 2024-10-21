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

//get from list (back, front, at)

//remove from list (pop, remove, etc)

//sorting function

//stream opperator (<<)