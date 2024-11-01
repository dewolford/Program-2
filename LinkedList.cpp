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
		delete nodePtr->restaurant;
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
    LinkedList okay;                //list variable to be able to set headptr
    Node* temp = okay.headPtr;      //set temp to first node in the list
    Node* temp2;                    //temp 2 to iterate through the list
    int counter = 0;                //counter to get the length


    //iterate through list and add to counter each time
    for(int x = 1; temp2 != nullptr; x++)
    {
        temp = okay.headPtr->next;
        temp2 = temp->next;
        counter++;
    }

    size = counter;
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

//find the restaurent
Restaurants* LinkedList::findRestaureants(const string& name)
{
    Node* current = headPtr;
    while (current != nullptr)
    {
        if (current != nullptr)
        {
            return current->restaurant;//returns restaurant if fount
        }
        current = current->next;
    }
    return nullptr; // returns null if not found
}

//public node so main function can access
LinkedList::Node* LinkedList::findNode(const string& name)
{   Node* current = headPtr;
    while (current != nullptr)
    {
        if (current->restaurant->getName() == name)
        {
            return current;
        }
        current = current->next;
    }
    
    return nullptr;
}



//add to list (append, prepend, insert)

//function name:        insertAtFront
//function purpose:     insert a new node at the beginning of a list
void LinkedList::addRestaurant(Restaurants* temp)
{
    Node *newNode; //new node to insert at beginning

    newNode->restaurant = temp;
    newNode->next = NULL; 
    // If there are no nodes in the list make newNode the first node.
	if (!headPtr ) 
	{
		headPtr = newNode;
		tailPtr = newNode;
	}
	else  // Otherwise, insert newNode at end.
	{
		//set the current last node's next pointer to the new node
		tailPtr->next = newNode;
		
		//now the tail is the new node
		tailPtr = newNode;
	}
    cout << "\nSuccessfully added to restaurant list!\n";
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
    return temp.getHeadPtr()->restaurant->getRating();
}

//function name:        back
//function purpose:     return the last entry of a list
double LinkedList::back()
{
    LinkedList temp;    //temp variable to return the back
    return temp.getTailPtr()->restaurant->getRating();
}

//function name:        at
//function purpose:     return the entry at a specific point of a list
double LinkedList::at(int num)
{
    LinkedList okay;    //temp variable to return a node
    Node* temp = okay.headPtr;
    Node* temp2;

    for(int x = 1; 1 <= num; x++)
    {
        temp = okay.headPtr->next;
        temp2 = temp->next;
    }

    return temp->restaurant->getRating();
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
    if (headPtr == nullptr)
    {
        cout << "\nList is empty" << endl;
        return;
    }

    //will handle if headPtr needs to be deleted
    if (headPtr->restaurant->getName() == name)
    {
        Node* temp = headPtr;
        headPtr = headPtr->next;
        delete temp->restaurant;
        delete temp;
        cout << "\nRestaurant " << name << " has been deleted." << endl;
        return;
    }
    
    //Traverse list to the find the node user requested deletion
    Node* current = headPtr;
    while (current->next != nullptr && current->next->restaurant->getName() != name)
    {
        current = current->next;
    }
    
    //If restaurant was found it will be deleted
    if (current->next != nullptr)
    {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp->restaurant;
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
    double pivot = high->restaurant->getRating();        //variable to assist in sorting (using the high end)

    Node* temp = low->prev;                         //variable to assist in sorting (using the low end)


    //iterate through list and swap when needed
    for (Node* x = low; x != high; x = x->next)
    {
        if(x->restaurant->getRating() <= pivot)
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
        cout << "\nName: " << nodePtr->restaurant->getName();
        cout << ", Location: " << nodePtr->restaurant->getLocation();
        cout << ", Food: " << nodePtr->restaurant->getFood();
        cout << ", Rating: " << nodePtr->restaurant->getRating();
        
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
            if (name1 == currentNode->restaurant->getName()){
                res1 = currentNode;
                break;
            }
            //Moves to the next node
            currentNode = currentNode->next; 
        }
        if (name1 != currentNode->restaurant->getName()){
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
                if (name2 == currentNode->restaurant->getName()){
                    res2 = currentNode;
                    break;
                }
                //Moves to the next node
                currentNode = currentNode->next; 
            }
            if (name2 != currentNode->restaurant->getName()){
                cout << "\nCould not find restaurant: " << name2 << ". Would you like to try again(1) or quit?(2)\n";
                num = validateInput(num, 1,2);
                if (num == 1){
                    
                } else{
                    tryAgain = false;
                    correct = true;

                }
            }
        } while  (!correct);
        if (tryAgain){
            if (res1->restaurant> res2->restaurant){
                cout << res1->restaurant->getName() << " in " << res1->restaurant->getLocation() << " (" << res1->restaurant->getRating() << ") is rated higher than ";
                cout << res2->restaurant->getName() << " in " << res2->restaurant->getLocation() << " (" << res2->restaurant->getRating() << ").";
            } else if (res1->restaurant< res2->restaurant){
                cout << res1->restaurant->getName() << " in " << res1->restaurant->getLocation() << " (" << res1->restaurant->getRating() << ") is rated lower than ";
                cout << res2->restaurant->getName() << " in " << res2->restaurant->getLocation() << " (" << res2->restaurant->getRating() << ")."; 
            } else {
                cout << res1->restaurant->getName() << " in " << res1->restaurant->getLocation() << " (" << res1->restaurant->getRating() << ") is rated equal to ";
                cout << res2->restaurant->getName() << " in " << res2->restaurant->getLocation() << " (" << res2->restaurant->getRating() << ").";
            }
        }
    }
}