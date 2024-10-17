//pqueue.h
//shah, tirth
//tshah

#ifndef PQUEUE_H
#define PQUEUE_H
#include <iostream>
#include <string>
#include "cust.h"
using namespace std;

class PQueue
{
    private:
    // Node inner class represents an element in the priority queue
    class Node {
    public:
        Cust *data;       // Data of the element
        int priority;   // Priority of the element
        Node* next;     // Pointer to the next node in the list

        // Node constructor initializing data, priority, and next pointer
        Node(Cust* data, int priority, Node* next) {
            this->data = data;
            this->priority = priority; 
            this->next = next;
        }
    };

    Node* head;  // Pointer to the head node of the priority queue

    public:
    // Default constructor initializes the head node to nullptr (empty list)
    PQueue() : head(nullptr) {}
     ~PQueue();
    // Destructor deallocates memory used by the nodes in the priority queue
    
    
    void enqueue(Cust *cust, int priority);
    bool dequeue(Cust *&c);
    bool isEmpty();
    bool getFirstPriority(int &priority);
    int getSize();
    void print(ostream &os);

};

#endif