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
LinkedList::LinkedList()
{
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
    Restaurants();
}

LinkedList::LinkedList(Node* h, Node* t, int s, Restaurants r)
{
    headPtr = h;
    tailPtr = t;
    size = s;
    res = r;
}

//destructor
LinkedList::~LinkedList()
{
    Node* nodePtr;   // To traverse the list
	Node* nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = headPtr;

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
void LinkedList::setHeadPtr(Node* h)
{
    headPtr = h;
}

void LinkedList::setTailPtr(Node* t)
{
    tailPtr = t;
}

void LinkedList::setSize(int s)
{
    size = s;
}

void LinkedList::setRes(Restaurants r)
{
    res = r;
}

//getters
LinkedList::Node* LinkedList::getHeadPtr()
{
    return headPtr;
}

LinkedList::Node* LinkedList::getTailPtr()
{
    return tailPtr;
}

int LinkedList::getSize()
{
    return size;
}

Restaurants LinkedList::getRes()
{
    return res;
}





//add to list (append, prepend, insert)
void LinkedList::insertAtFront(LinkedList temp)
{
    Node* newData = temp.getHeadPtr();
    temp.setHeadPtr(newData);
    
    cout << "\nSuccessfully added to restaurant list!\n";
}

void LinkedList::insertAtBack(LinkedList temp)
{
    Node* newData = temp.getTailPtr();
    temp.setTailPtr(newData);

    cout << "\nSuccessfully added to restaurant list!\n";
}

//get from list (back, front, at)
int LinkedList::front()
{
    LinkedList temp;
    return temp.getHeadPtr()->data;
}

int LinkedList::back()
{
    LinkedList temp;
    return temp.getTailPtr()->data;
}

int LinkedList::at(int num)
{
    LinkedList okay;
    Node* temp = okay.headPtr;
    Node* temp2;

    for(int x = 1; 1 <= num; x++)
    {
        temp = okay.headPtr->next;
        temp2 = temp->next;
    }

    return temp->data;
}

//remove from list (pop, remove, etc)
LinkedList::Node* LinkedList::pop()
{
    LinkedList okay;

    if (okay.headPtr == nullptr)
    {
        return nullptr;
    }
    if (okay.headPtr->next == nullptr)
    {
        delete headPtr;
        return nullptr;
    }

    LinkedList temp;
    Node* curr, *nextVariable;
    while(temp.headPtr != nullptr)
    {
        curr = temp.headPtr->next;
        nextVariable = curr->next;
    }

    if(curr->prev != nullptr)
    {
        curr = nullptr;
    }

    delete curr;

    int sizeTemp;
    sizeTemp = getSize();
    sizeTemp = sizeTemp--;
    setSize(sizeTemp); 

    return headPtr;
}

LinkedList::Node* LinkedList::removeFrom(int pos)
{
    if (headPtr == nullptr)
    {
        cout << "\nSuccessfully removed from restaurant list!\n";
        return headPtr;
    }

    LinkedList curr;
    Node* temp1, *temp2;

    for(int x = 1; (curr.headPtr != nullptr) && (x < pos); x++)
    {
        temp1 = curr.headPtr->next;
        temp2 = temp1->next;
    }

    if(temp2 == nullptr)
    {
        return headPtr;
    }

    if(temp2->prev != nullptr)
    {
        temp2 = temp2->next;
    }

    if(temp2->next != nullptr)
    {
        temp2 = temp2->prev;
    }

    if(headPtr == temp2)
    {
        headPtr = temp2->next;
    }

    delete temp2;
    cout << "\nSuccessfully removed from restaurant list!\n";
    return headPtr;
}

//sorting function
void LinkedList::sort(Node* low, Node* high)
{
    LinkedList temp;

    cout << "\nSorting the array with the Quick Sort algorithm.\n\n";

    if((low != nullptr) && (high != nullptr) && (low != high) && (low != high->next))
    {
        Node* pivot = partition(low, high);

        sort(low, pivot->prev);

        sort(pivot->next, high);
    }

    cout << "\nSuccessfully sorted restaurant list!\n";
}

LinkedList::Node* LinkedList::partition(Node* low, Node* high)
{
    int pivot = high->data;

    Node* temp = low->prev;

    for (Node* x = low; x != high; x = x->next)
    {
        if(x->data <= pivot)
        {
            temp = temp->next;
            swap(temp, x);
        }
    }

    temp = temp->next;

    swap(temp, high);

    return temp;
}

void LinkedList::swap(Node* a, Node* b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}


//print function
void LinkedList::printList()
{
    LinkedList temp;
    Node* curr = temp.headPtr;
    while (curr != NULL)
    {
        cout << curr->data << "  ";
        curr = curr->next;
    }
    cout << endl;
}


//compare function
void LinkedList::compare(){
    string name1;   //stores name of first restaurant
    string name2;   //stores name of second restaurant
    LinkedList tempList;
    Node* currentNode = headPtr;
    Node* res1;     //pointer to the first restaurant in the linked list
    Node* res2;     //pointer to the second restaurant in the linked list
    int num;        //num used for user input
    bool tryAgain = true;
    bool correct = true;

    do{

    cout << "\nWhat is the name of the first restaurant?\n";
    getline(cin, name1);
    for (int i = 0;i< ){

        if (name1 == tempList.getRes().getName()){
            
        }
    }

    
    currentNode = tempList.headPtr->next;
    
    num = validateInput(num, 1,2);

    
    } while  (!correct);






}
    /*this one should be simple. all it does is take two objects as arguments, takes the 
    ratings, and prints "this restaurant (rating) is rated higher than that restaurant 
    (rating)" or "this restaurant and that restaurant are rated equally (rating)"*/
