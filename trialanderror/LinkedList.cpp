#include "LinkedList.h"
using namespace std;

// Destructor
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
void LinkedList<T>::deleteRestaurant(const string& name) {
    Node* current = headPtr;
    Node* previous = nullptr;
    
    while (current) {
        if (current->data->getName() == name) {
            if (previous) previous->next = current->next;
            else headPtr = current->next;
            delete current;
            cout << "Restaurant " << name << " deleted.\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Restaurant " << name << " not found.\n";
}

// Sort function called without parameters for external use
template <typename T>
void LinkedList<T>::sort() {
    cout << "\nSorting the restaurant list with the Quick Sort algorithm.\n\n";
    if (headPtr != nullptr && tailPtr != nullptr) {
        sort(headPtr, tailPtr);  // Calls recursive sort function with the head and tail pointers
    }
    cout << "\nSuccessfully sorted restaurant list!\n";
}

// Recursive sort function for internal use with low and high pointers
template <typename T>
void LinkedList<T>::sort(Node* low, Node* high) {
    if (low != nullptr && high != nullptr && low != high && low != high->next) {
        Node* pivot = partition(low, high);
        sort(low, pivot);             // Recursively sort the left part of the list
        sort(pivot->next, high);      // Recursively sort the right part of the list
    }
}

// Partition function for sorting purposes
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::partition(Node* low, Node* high) {
    double pivot = high->data->getRating();  // Choose the last element's rating as the pivot
    Node* i = low;

    for (Node* j = low; j != high; j = j->next) {
        if (j->data->getRating() >= pivot) {  // Sort in descending order by rating
            if (i != j) {
                swap(i, j);                   // Swap the data in the nodes
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
