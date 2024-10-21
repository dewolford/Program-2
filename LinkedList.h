/*
    Title: classes.h
    Purpose: store our classes and definitions
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "SmartPointer.h"
#include "Restaurants.h"
#include <iostream>
#include <list>

using namespace std;

class ListClass
{
    private:
        int* headPtr;
        int* tailPtr;
        int size;

    public:
        //constructors
        ListClass();
        ListClass(int*, int*, int);
        
        //destructor
        ListClass();
        
        //setters
        void setHeadPtr(int*);
        void setTailPtr(int*);
        void setSize(int);

        //getters
        int* getHeadPtr();
        int* getTailPtr();
        int getSize();
        
        //add to list (append, prepend, insert)
        
        //get from list (back, front, at)
        
        //remove from list (pop, remove, etc)
        
        //sorting function
        
        //stream opperator (<<)

};

#endif