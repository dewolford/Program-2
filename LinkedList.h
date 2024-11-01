/*
    Title: classes.h
    Purpose: store our classes and definitions
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "SmartPointer.h"
#include "Restaurants.h"
#include "functions.h"
#include <iostream>
#include <list>

using namespace std;



class LinkedList
{
    private:
        struct Node 
        {   
            Restaurants* resty;
            Node* next;
            Node* prev;

            Node(Restaurants* res) : resty(res), next(nullptr) {}
            /*Node() {
                prev = next = nullptr;
                resty->setFood(" ");
                resty->setLocation(" ");
                resty->setName(" ");
                resty->setRating(0);

            }

            Node(string food, string location, string name, double rating) {
                prev = next = nullptr;
                resty->setFood(" ");
                resty->setLocation(" ");
                resty->setName(" ");
                resty->setRating(0);
            }*/
        };
        
        Node* headPtr;
        Node* tailPtr;
        int size;

    public:
        //constructors
        LinkedList();
        LinkedList(Node*, Node*, int);
        
        //destructor
        ~LinkedList();
        
        //setters
        void setHeadPtr(Node*);
        void setTailPtr(Node*);
        void setSize(int);

        //getters
        Node* getHeadPtr();
        Node* getTailPtr();
        int getSize();
        



        //add to list (append, prepend, insert)
        void addRestaurant(Restaurants*);
        void insertAtBack(LinkedList);
        
        //get from list (back, front, at)
        double front();
        double back();
        double at(int);
        
        //remove from list (pop, remove, etc)
        Node* pop();
        Node* removeFrom(int);
        
        //sorting function
        void sort();
        void sort(Node*, Node*);
        Node* partition(Node*, Node*);
        void swap(Node*, Node*);


        //print function
        void printList();

        //compare function
        void compare();

        //overloaded << operator
        //this does the same thing as print function, but it's easier to access.
        friend std::ostream& operator<<(std::ostream& os, const LinkedList& linkedList) {
            Node* nodePtr = linkedList.headPtr;//starts the current node at the front
    
            if(linkedList.headPtr == NULL)
                cout << "\nThere are no restaurants in the list.\n";
            else{
                while (nodePtr) {
                    // Display the value in this node.
                    os << nodePtr->resty << endl;

                    // Move to the next node.
                    nodePtr = nodePtr->next;
                }
            }
            return os;
        }
};

#endif