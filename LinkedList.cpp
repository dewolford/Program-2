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
    size = 0;
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
}

void insertAtBack(Node temp)
{
    temp.prev = getTailPtr();
    setTailPtr(&temp.data);
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

}

//sorting function
void sort()
{

}

//stream opperator (<<)
void streamOperator()
{

}

//print function
void printList()
{

}