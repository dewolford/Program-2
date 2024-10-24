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
<<<<<<< HEAD
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
=======
    /*please add the following line of code to the end of the function*/
    cout << "\nSuccessfully added to restaurant list!\n";
>>>>>>> 9987b9935cd520e59aab5380745dee8ca1e7ea80

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
<<<<<<< HEAD
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
=======
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
>>>>>>> 9987b9935cd520e59aab5380745dee8ca1e7ea80
