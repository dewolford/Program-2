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
        struct Node {
            int data;
            Node* next;
            Node* prev;

            Node() {
                data = 0;
                prev = next = nullptr;
            }

            Node(int d) {
                data = d;
                prev = next = nullptr;
            }
        };
        
        Node* headPtr;
        Node* tailPtr;
        int size;

    public:
        //constructors
        LinkedList();
        LinkedList(Node*, Node*, int);
        
        //destructor
        LinkedList();
        
        //setters
        void setHeadPtr(Node*);
        void setTailPtr(Node*);
        void setSize(int);

        //getters
        Node* getHeadPtr();
        Node* getTailPtr();
        int getSize();
        



        //add to list (append, prepend, insert)
        void insertAtFront(Node);
        void insertAtBack(Node);
        
        //get from list (back, front, at)
        int front();
        int back();
        int at(int);
        
        //remove from list (pop, remove, etc)
        void pop();
        void removeFrom(int);
        
        //sorting function
        void sort();
        
        //stream opperator (<<)
        void streamOperator();

        //print function
        void printList();
};

#endif