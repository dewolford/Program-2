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

            Node() {
                prev = next = nullptr;
                resty.setFood(" ");
                resty.setLocation(" ");
                resty.setName(" ");
                resty.setRating(0);//again should not need

            }

            Node(string food, string location, string name, double rating) {
                prev = next = nullptr;
                resty.setFood(food);
                resty.setLocation(location);
                resty.setName(name);
                resty.setRating(rating);//should not need the resty functions.
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
        void insertAtFront(Restaurants*);
        void insertAtBack(LinkedList);
        
        //get from list (back, front, at)
        double front();
        double back();
        double at(int);
        
        //remove from list (pop, remove, etc)
        Node* pop();
        Node* removeFrom(int);
        
        //sorting function
        void sort(Node*, Node*);
        Node* partition(Node*, Node*);
        void swap(Node*, Node*);


        //print function
        void printList();

        //compare function
        void compare();
};

#endif