#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "SmartPointer.h"
#include <iostream>
using namespace std;
template <typename T>
class LinkedList {
public:
    struct Node {
        SmartPointer<T> data;
        Node* next;

        Node(T* value) : data(value), next(nullptr) {}
    };

private:
    Node* headPtr;
    Node* tailPtr;
    int size;

public:
    LinkedList() : headPtr(nullptr), tailPtr(nullptr), size(0) {}
    ~LinkedList();

    void append(T* data);
    void deleteRestaurant(const std::string& name);
    void sort();  // Sort the list in descending order

private:
    void sort(Node* low, Node* high);
    Node* partition(Node* low, Node* high);
    void swap(Node* a, Node* b);

    friend std::ostream& operator<<(std::ostream& out, const LinkedList& list) {
        Node* current = list.headPtr;
        while (current) {
            out << *current->data << "\n";
            current = current->next;
        }
        return out;
    }
};

// Destructor to free memory
template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = headPtr;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// Append a new element
template <typename T>
void LinkedList<T>::append(T* data) {
    Node* newNode = new Node(data);
    if (!headPtr) {
        headPtr = tailPtr = newNode;
    } else {
        tailPtr->next = newNode;
        tailPtr = newNode;
    }
    ++size;
}

// Delete a restaurant by name
template <typename T>
void LinkedList<T>::deleteRestaurant(const std::string& name) {
    Node* current = headPtr;
    Node* previous = nullptr;
    
    while (current) {
        if (current->data->getName() == name) {
            if (previous) previous->next = current->next;
            else headPtr = current->next;
            delete current;
            std::cout << "Restaurant " << name << " deleted.\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    std::cout << "Restaurant " << name << " not found.\n";
}

// Sort function called externally for descending order
template <typename T>
void LinkedList<T>::sort() {
    std::cout << "\nSorting the restaurant list with Quick Sort (descending).\n\n";
    if (headPtr != nullptr && tailPtr != nullptr) {
        sort(headPtr, tailPtr);  // Calls recursive sort function
    }
    std::cout << "\nSuccessfully sorted restaurant list!\n";
}

// Recursive sort function for descending order
template <typename T>
void LinkedList<T>::sort(Node* low, Node* high) {
    if (low != nullptr && high != nullptr && low != high && low != high->next) {
        Node* pivot = partition(low, high);
        if (pivot != nullptr && pivot != low) {
            sort(low, pivot);  // Sort left side
        }
        if (pivot != nullptr && pivot->next != nullptr) {
            sort(pivot->next, high);  // Sort right side
        }
    }
}

// Partition function for sorting, with descending order logic
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::partition(Node* low, Node* high) {
    double pivotValue = high->data->getRating();  // Choose the high node's rating as the pivot
    Node* i = low;

    for (Node* j = low; j != high; j = j->next) {
        if (j->data->getRating() >= pivotValue) {  // Descending order
            if (i != j) {
                swap(i, j);  // Swap the data within nodes, not the nodes themselves
            }
            i = i->next;
        }
    }
    swap(i, high);  // Place pivot in its correct position
    return i;
}

// Swap function to swap data between two nodes
template <typename T>
void LinkedList<T>::swap(Node* a, Node* b) {
    SmartPointer<T> temp = a->data;
    a->data = b->data;
    b->data = temp;
}

#endif
