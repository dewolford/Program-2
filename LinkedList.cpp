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
//default constructor
LinkedList::LinkedList()
{
    headPtr = NULL;     //points to first node in a list
    tailPtr = NULL;     //points to last node in a list
    size = 0;           //size of the list
}
//overloaded constructor
LinkedList::LinkedList(Node* h, Node* t, int s)
{
    headPtr = h;        //points to first node in a list
    tailPtr = t;        //points to last node in a list
    size = s;           //size of the list
}

//destructor
LinkedList::~LinkedList()
{
    Node* nodePtr;   // To traverse the list
	Node* nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = headPtr;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr->resty;
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

//public node so main function can access
LinkedList::Node* LinkedList::findNode(const string& name)
{   Node* current = headPtr;
    while (current != nullptr)
    {
        if (current->resty->getName() == name)
        {
            return current;
        }
        current = current->next;
    }
    
    return nullptr;
}

//add to list (append, prepend, insert)
void LinkedList::addRestaurant(Restaurants* temp)
{
    Node* newNode;

    newNode = new Node(temp);
    if (headPtr == nullptr)
    {
        headPtr = newNode;
    }
    else
    {
        Node* current = headPtr;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

//function name:        insertAtBack
//function purpose:     insert a new node at the end of a list
void LinkedList::insertAtBack(LinkedList temp)//should be able to remove later
{
    Node* newData = temp.getTailPtr();      //node for the new data getting added to the list
    temp.setTailPtr(newData);

    cout << "\nSuccessfully added to restaurant list!\n";
}


//get from list (back, front, at)

//function name:        front
//function purpose:     return the first entry of a list
double LinkedList::front()
{
    LinkedList temp;    //temp variable to return the front
    return temp.getHeadPtr()->resty->getRating();
}

//function name:        back
//function purpose:     return the last entry of a list
double LinkedList::back()
{
    LinkedList temp;    //temp variable to return the back
    return temp.getTailPtr()->resty->getRating();
}

//function name:        at
//function purpose:     return the entry at a specific point of a list
double LinkedList::at(int num)
{
    LinkedList okay;    //tmep variable to return a node
    Node* temp = okay.headPtr;
    Node* temp2;

    for(int x = 1; 1 <= num; x++)
    {
        temp = okay.headPtr->next;
        temp2 = temp->next;
    }

    return temp->resty->getRating();
}

//remove from list (pop, remove, etc)

//function name:        pop
//function purpose:     remove the first node of a list
LinkedList::Node* LinkedList::pop()
{   
    LinkedList okay;        //list variable to test if null

    if (okay.headPtr == nullptr)
    {
        return nullptr;
    }
    if (okay.headPtr->next == nullptr)
    {
        delete headPtr;
        return nullptr;
    }

    LinkedList temp;        //temp variable to delete a node
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
    sizeTemp--;
    setSize(sizeTemp); 

    return headPtr;
}

//function name:        removeFrom
//function purpose:     remove a node from a specific point in the list
LinkedList::Node* LinkedList::removeFrom(int pos)
{
    if (headPtr == nullptr)
    {
        cout << "\nSuccessfully removed from restaurant list!\n";
        return headPtr;
    }

    LinkedList curr;            //temp list to find the position wanted and then delete
    Node* temp1, *temp2;        //nodes to swap to find position

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

void LinkedList::deleteRestaurant(const string& name)
{   
    if ( headPtr == nullptr)
    {
        cout << "\nList is empty" << endl;
        return;
    }

    //will handle if headPtr needs to be deleted
    if (headPtr->resty->getName() == name)
    {
        Node* temp = headPtr;
        headPtr = headPtr->next;
        delete temp->resty;
        delete temp;
        cout << "\nRestaurant " << name << " has been deleted." << endl;
        return;
    }
    
    //Traverse list to the find the node user requested deletion
    Node* current = headPtr;
    while (current->next != nullptr && current->next->resty->getName() != name)
    {
        current = current->next;
    }
    
    //If restaurant was found it will be deleted
    if (current->next != nullptr)
    {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp->resty;
        delete temp;
        cout << "\nRestaurant " << name << " has been deleted." << endl;

    }
    
}

//sorting functions

//this sorting function with no arguments is used to be called in driver without parameters
//function name:        sort
//function purpose:     call the recursive sort function
void LinkedList::sort(){
    //using the tail and head of the list to sort the whole list
    sort(tailPtr, headPtr);
}

//this sorting function has parameters so it can be called recursively
//function name:        sort
//function purpose:     recursively sort the list
void LinkedList::sort(Node* low, Node* high)
{
    cout << "\nSorting the array with the Quick Sort algorithm.\n\n";

    if((low != nullptr) && (high != nullptr) && (low != high) && (low != high->next))
    {
        Node* pivot = partition(low, high);

        sort(low, pivot->prev);

        sort(pivot->next, high);
    }

    cout << "\nSuccessfully sorted restaurant list!\n";
}

//function name:        partition
//function purpose:     partition the list for sorting purposes
LinkedList::Node* LinkedList::partition(Node* low, Node* high)
{
    double pivot = high->resty->getRating();        //variable to assist in sorting (using the high end)

    Node* temp = low->prev;                         //variable to assist in sorting (using the low end)


    //iterate through list and swap when needed
    for (Node* x = low; x != high; x = x->next)
    {
        if(x->resty->getRating() <= pivot)
        {
            temp = temp->next;
            swap(temp, x);
        }
    }

    temp = temp->next;

    swap(temp, high);

    return temp;
}

//function name:        swap
//function purpose:     swap 2 variable for sorting purposes
void LinkedList::swap(Node* a, Node* b){
    Node* temp = a;
    a = b;
    b = temp;
}

//function name:        printList
//function purpose:     print all nodes of a list
void LinkedList::printList() const{

	Node* nodePtr = headPtr;//starts the current node at the front
    if (nodePtr == nullptr)
    {
        cout << "\nNothing to see here, add a restaurant first." << endl;
    }
    
	while (nodePtr != nullptr)
    {
        cout << "\nName: " << nodePtr->resty->getName();
        cout << ", Location: " << nodePtr->resty->getLocation();
        cout << ", Food: " << nodePtr->resty->getFood();
        cout << ", Rating: " << nodePtr->resty->getRating();
        nodePtr = nodePtr->next;
    }
    
}


//compare function

//function name:        compare
//function purpose:     compares 2 nodes in the list against each other
void LinkedList::compare(){
    string name1;   //stores name of first restaurant
    string name2;   //stores name of second restaurant
    Node* currentNode = headPtr;    //starts the current node at the front
    Node* res1;     //pointer to the first restaurant in the linked list
    Node* res2;     //pointer to the second restaurant in the linked list
    int num;        //num used for user input
    bool tryAgain = true;   //
    bool correct = false;   //

    //gets pointer to the first restaurant
    do{

        cout << "\nWhat is the name of the first restaurant?\n";
        getline(cin, name1);
        for (int i = 0;i< getSize(); i++){
            if (name1 == currentNode->resty->getName()){
                res1 = currentNode;
                break;
            }
            //Moves to the next node
            currentNode = currentNode->next; 
        }
        if (name1 != currentNode->resty->getName()){
            cout << "\nCould not find restaurant: " << name1 << ". Would you like to try again(1) or quit?(2)\n";
            num = validateInput(num, 1,2);
            if (num == 1){
                
            } else{
                tryAgain = false;
                correct = true;

            }
        }
    } while  (!correct);

    //if they didn't quit
    if (tryAgain){
        do{

            cout << "\nWhat is the name of the second restaurant?\n";
            getline(cin, name2);
            for (int i = 0;i< getSize(); i++){
                if (name2 == currentNode->resty->getName()){
                    res2 = currentNode;
                    break;
                }
                //Moves to the next node
                currentNode = currentNode->next; 
            }
            if (name2 != currentNode->resty->getName()){
                cout << "\nCould not find restaurant: " << name1 << ". Would you like to try again(1) or quit?(2)\n";
                num = validateInput(num, 1,2);
                if (num == 1){
                    
                } else{
                    tryAgain = false;
                    correct = true;

                }
            }
        } while  (!correct);
        if (tryAgain){
            if (res1->resty> res2->resty){
                cout << res1->resty->getName() << " in " << res1->resty->getLocation() << " (" << res1->resty->getRating() << ") is rated higher than ";
                cout << res2->resty->getName() << " in " << res2->resty->getLocation() << " (" << res2->resty->getRating() << ").";
            } else if (res1->resty< res2->resty){
                cout << res1->resty->getName() << " in " << res1->resty->getLocation() << " (" << res1->resty->getRating() << ") is rated lower than ";
                cout << res2->resty->getName() << " in " << res2->resty->getLocation() << " (" << res2->resty->getRating() << ")."; 
            } else {
                cout << res1->resty->getName() << " in " << res1->resty->getLocation() << " (" << res1->resty->getRating() << ") is rated equal to ";
                cout << res2->resty->getName() << " in " << res2->resty->getLocation() << " (" << res2->resty->getRating() << ").";
            }
        }
    }






}
    /*this one should be simple. all it does is take two objects as arguments, takes the 
    ratings, and prints "this restaurant (rating) is rated higher than that restaurant 
    (rating)" or "this restaurant and that restaurant are rated equally (rating)"*/
