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
}

LinkedList::LinkedList(Node* h, Node* t, int s)
{
    headPtr = h;
    tailPtr = t;
    size = s;
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




//add to list (append, prepend, insert)
void LinkedList::insertAtFront(Restaurants* temp)
{
    Node *newNode;

    newNode = new Node;
    newNode->resty = temp;
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
}

void LinkedList::insertAtBack(LinkedList temp)//should be able to remove later
{
    Node* newData = temp.getTailPtr();
    temp.setTailPtr(newData);

    cout << "\nSuccessfully added to restaurant list!\n";
}


//get from list (back, front, at)
double LinkedList::front()
{
    LinkedList temp;
    return temp.getHeadPtr()->resty.getRating();
}

double LinkedList::back()
{
    LinkedList temp;
    return temp.getTailPtr()->resty.getRating();
}

double LinkedList::at(int num)
{
    LinkedList okay;
    Node* temp = okay.headPtr;
    Node* temp2;

    for(int x = 1; 1 <= num; x++)
    {
        temp = okay.headPtr->next;
        temp2 = temp->next;
    }

    return temp->resty.getRating();
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

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************
/*void LinkedList::displayList() const
{
	ListNode *nodePtr;  // To move through the list

	if(head != NULL)
	{
		// Position nodePtr at the head of the list.
		nodePtr = head;
		// While nodePtr points to a node, traverse the list.
		while (nodePtr)
		{
			// Display the value in this node.
			cout << nodePtr->value << endl;

			// Move to the next node.
			nodePtr = nodePtr->next;
		}
	}
	else
		cout << "\nThere are no nodes in the list.\n\n";
}*/// this is an example code, we can use this to correct the print function for the list

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
    //LinkedList tempList;
    Node* currentNode = headPtr;
    Node* res1;     //pointer to the first restaurant in the linked list
    Node* res2;     //pointer to the second restaurant in the linked list
    int num;        //num used for user input
    bool tryAgain = true;
    bool correct = false;

    //gets pointer to the first restaurant
    do{

        cout << "\nWhat is the name of the first restaurant?\n";
        getline(cin, name1);
        for (int i = 0;i< getSize(); i++){
            if (name1 == currentNode.getRes().getName()){
                res1 = currentNode;
                break;
            }
            currentNode = currentNode->next; 
        }
        if (name1 != currentNode.getRes().getName()){
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
                if (name2 == currentNode.getRes().getName()){
                    res2 = currentNode;
                    break;
                }
                currentNode = currentNode->next; 
            }
            if (name2 != currentNode.getRes().getName()){
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
            if (res1.getRes()> res2.getRes()){
                cout << res1.getRes().getName() << " in " << res1.getRes().getLocation() << " (" << res1.getRes().getRating() << ") is rated higher than ";
                cout << res2.getRes().getName() << " in " << res2.getRes().getLocation() << " (" << res2.getRes().getRating() << ").";
            } else if (res1.getRes()< res2.getRes()){
                cout << res1.getRes().getName() << " in " << res1.getRes().getLocation() << " (" << res1.getRes().getRating() << ") is rated lower than ";
                cout << res2.getRes().getName() << " in " << res2.getRes().getLocation() << " (" << res2.getRes().getRating() << ")."; 
            } else {
                cout << res1.getRes().getName() << " in " << res1.getRes().getLocation() << " (" << res1.getRes().getRating() << ") is rated equal to ";
                cout << res2.getRes().getName() << " in " << res2.getRes().getLocation() << " (" << res2.getRes().getRating() << ").";
            }
        }
    }






}
    /*this one should be simple. all it does is take two objects as arguments, takes the 
    ratings, and prints "this restaurant (rating) is rated higher than that restaurant 
    (rating)" or "this restaurant and that restaurant are rated equally (rating)"*/
