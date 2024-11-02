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
    void deleteRestaurant(const string& name);
    void sort();  // Sort the list using the recursive sort function

private:
    void sort(Node* low, Node* high);
    Node* partition(Node* low, Node* high);
    void swap(Node* a, Node* b);

    friend ostream& operator<<(ostream& out, const LinkedList& list) {
        Node* current = list.headPtr;
        while (current) {
            out << *current->data << "\n";
            current = current->next;
        }
        return out;
    }
};

#endif
