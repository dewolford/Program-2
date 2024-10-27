/*
    Title: classes.cpp
    Purpose: hold all functions necessary for the classes made in classes.h
*/
#include "LinkedList.h"
#include "SmartPointer.h"
#include "Restaurants.h"

using namespace std;

//constructors
LinkedList()
{
    headPtr = NULL;
    tailPtr = NULL;
    int size = 0;
}

LinkedList(Node* h, Node* t, int s)
{
    headPtr = h;
    tailPtr = t;
    size = s;
}

//destructor
LinkedList()
{

}

//setters
void setHeadPtr(Node* h)
{
    headPtr = h;
}

void setTailPtr(Node* t)
{
    tailPtr = t;
}

void setSize(int s)
{
    size = s;
}



//getters
Node* getHeadPtr()
{
    return headPtr;
}

Node* getTailPtr()
{
    return tailPtr;
}

int getSize()
{
    return size;
}

//add to list (append, prepend, insert)
void insertAtFront(Node temp)
{
    temp.next = getHeadPtr();
    setHeadPtr(&temp.data);
    
    cout << "\nSuccessfully added to restaurant list!\n";
}

void insertAtBack(Node temp)
{
    temp.prev = getTailPtr();
    setTailPtr(&temp.data);
    
    cout << "\nSuccessfully added to restaurant list!\n";
}

//get from list (back, front, at)
int front()
{
    
}

int back()
{

}

int at(int)
{

}

//remove from list (pop, remove, etc)
void pop()
{
    
}

void removeFrom(int)
{
    
    cout << "\nSuccessfully removed from restaurant list!\n";
}

//sorting function
void sort()
{
    
    cout << "\nSuccessfully sorted restaurant list!\n";
}

//stream opperator (<<)
void streamOperator()
{

}

//print function
void printList()
{

}

//compare function
    /*this one should be simple. all it does is take two objects as arguments, takes the 
    ratings, and prints "this restaurant (rating) is rated higher than that restaurant 
    (rating)" or "this restaurant and that restaurant are rated equally (rating)"*/