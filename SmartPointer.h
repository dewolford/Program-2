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
    private:
    T* ptr;
    public:
        explicit SmartPtr(T* p = nullptr) { ptr = p; }
    
    //destructor
    ~SmartPtr() { delete (ptr); }

    SmartPtr& operator = (T* p){
        if (ptr != p){
        delete ptr;
        ptr = p;
        }
        return *this;
    }

    //overloaded operator
    T& operator*() { return *ptr; }

    //overload with arrow so class members can be accessed like a pointer
    T* operator->() { return ptr; }

    T* get() const { return ptr; }

    bool operator == (const SmartPtr& other) const{
        return ptr == other.ptr || (ptr && other.ptr && *ptr == other.ptr);
    }

    bool operator != (const SmartPtr& other) const {
        return !(*this == other);
    }

};

#endif