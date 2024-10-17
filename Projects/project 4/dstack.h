//dstack.h
//shah, tirth
//tshah
#ifndef DSTACK_H
#define DSTACK_H
#include <iostream>
#include <string>

using namespace std;

class Dstack {
private:
// Inner class representing a node in the linked list
    class Node {
    public:
        double data; // data stored in the node
        Node* next; // pointer to the next node
        // Constructor to initialize the data and next pointers of the node
        Node(double d) {
        data = d;
        next = nullptr;
        }
        ~Node() { }
    };

public:
    Node* head;
    Dstack();
    ~Dstack();
    void push(double val);
    bool pop (double *val);
    double top();
    int size ();
    bool empty ();
    
};
#endif