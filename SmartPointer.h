/*
    Title: SmartPointer.cpp
    Purpose: contains the functions for the smart pointer
*/

#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "Restaurants.h"
#include "LinkedList.h"
#include <memory>

template <class SP> class SmartPointer{
    SP* ptr;
    public:
        explicit SmartPtr(SP* p = NULL) { ptr = p; }
    
    //destructor
    ~SmartPtr() { delete (ptr); }

    //overloaded operator
    SP& operator*() { return *ptr; }

    //overload with arrow so class members can be accessed like a pointer
    SP* operator->() { return ptr; }

};

#endif