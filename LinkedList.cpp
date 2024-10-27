/*
    Title: classes.cpp
    Purpose: hold all functions necessary for the classes made in classes.h
*/
#include "LinkedList.h"
#include "SmartPointer.h"
#include "Restaurants.h"
#include "functions.h"

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
~LinkedList()
{
    Node *nodePtr;   // To traverse the list
	Node *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
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
    Node temp;
    temp.data = &getHeadPtr();
    return temp.data;
}

int back()
{
    Node temp;
    temp.data = &getTailPtr();
    return temp.data;
}

int at(int num)
{
    Node* temp = headPtr;

    for(int x = 1; 1 <= num; x++)
    {
        temp = temp.next;
    }

    return temp.data;
}

//remove from list (pop, remove, etc)
Node* pop()
{
    if (headPtr == nullptr)
    {
        return nullptr;
    }
    if (headPtr.next == nullptr)
    {
        delete headPtr;
        return nullptr;
    }

    Node* temp;
    temp = headPtr;
    while(temp.next != nullptr)
    {
        curr = curr.next;
    }

    if(curr.prev != nullptr)
    {
        curr.prev.next = nullptr;
    }

    delete temp;

    int sizeTemp;
    sizeTemp = getSize();
    sizeTemp = sizeTemp--;
    setSize(sizeTemp); 

    return headPtr;
}

Node* removeFrom(int pos)
{
    if (headPtr == nullptr)
    {
        cout << "\nSuccessfully removed from restaurant list!\n";
        return headPtr;
    }

    Node* curr = headPtr;

    for(int x = 1; (curr != nullptr) && (i < pos); x++)
    {
        curr = curr.next;
    }

    if(curr == nullptr)
    {
        return headPtr;
    }

    if(curr.prev != nullptr)
    {
        curr.prev.next = curr.next;
    }

    if(curr.next != nullptr)
    {
        curr.next.prev = curr.prev;
    }

    if(headPtr == curr)
    {
        headPtr = curr.next;
    }

    delete curr;
    cout << "\nSuccessfully removed from restaurant list!\n";
    return headPtr;
}

//sorting function
void sort()
{
    Node* temp;

    cout << "\nSorting the array with the Bubble Sort algorithm.\n\n";

    for(int x=(size-1); x > 0; x--)
    {
        for(int i = 0; i < x; i++)
        {
            if(temp.data > temp.next.data)
            {
                temp = temp.next;
            }
        }
    }

    cout << "\nSuccessfully sorted restaurant list!\n";
}

//stream opperator (<<)
void streamOperator()
{

}

//print function
void printList()
{
    Node* curr = headPtr;
    while (curr != NULL)
    {
        cout << curr.data << "  ";
        curr = curr.next;
    }
    cout << endl;
}

//compare function
    /*this one should be simple. all it does is take two objects as arguments, takes the 
    ratings, and prints "this restaurant (rating) is rated higher than that restaurant 
    (rating)" or "this restaurant and that restaurant are rated equally (rating)"*/