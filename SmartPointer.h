/*
    Title: SmartPointer.cpp
    Purpose: contains the functions for the smart pointer
*/

#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "Restaurants.h"
#include "LinkedList.h"
#include <memory>

template <class T> class SmartPtr{
    T* ptr;
    public:
        explicit SmartPtr(T* p = NULL) { ptr = p; }
    
    //destructor
    ~SmartPtr() { delete (ptr); }

    //overloaded operator
    T& operator*() { return *ptr; }

    //overload with arrow so class members can be accessed like a pointer
    T* operator->() { return ptr; }

};

#endif