//pqueue.cpp
//shah, tirth
//tshah

#include <iostream>
#include "cust.h"
#include "pqueue.h"
using namespace std;


// Destructor deallocates memory used by the nodes in the priority queue
PQueue::~PQueue() {
    Cust* data = nullptr;
    while (head) {
        dequeue( data);
    }
}

// enqueue() function inserts an element with given data and priority into the priority queue
// The element is inserted according to its priority in descending order (highest priority first)
// If two elements have the same priority, they maintain their relative order (stable priority queue)
void PQueue::enqueue(Cust* data, int priority) {
    Node* newNode = new Node(data, priority, nullptr);

    // If the list is empty or the priority is higher than the head node's priority,
    // insert the new node at the beginning of the list
    if (!head || priority < head->priority) {
        newNode->next = head;
        head = newNode;
    } else {
        // Traverse the list to find the correct position for the new node
        Node* current = head;
        while (current->next && priority >= current->next->priority) {
            current = current->next;
        }
        // Insert the new node after the current node
        newNode->next = current->next;
        current->next = newNode;
    }
        
}

// dequeue() function removes and returns the data of the element with the highest priority
// If the priority queue is empty, an exception is thrown
bool PQueue::dequeue(Cust*& data) {
    if (!head) {
        // throw runtime_error("Empty priority queue");
        return false;
    }

    // Remove the head node from the list and save its data
    Node* temp = head;
    data = temp->data;
    head = head->next;

    // Deallocate memory used by the removed node and return its data
    delete temp;
    return true;
}

// isEmpty() function checks if the priority queue is empty
// Returns true if the head node is nullptr (no elements in the list), false otherwise
bool PQueue::isEmpty() {
    return head == nullptr;
}

bool PQueue::getFirstPriority(int &priority){
        
    if (head!=nullptr)
    {
        priority = head->priority;
        return true;
    }
    else
    {
    return false;
    }
        
       
}
int PQueue::getSize(){
    int size = 0;
    Node* Current = head;
    while (Current != nullptr)
    {
        size = size + 1;
        Current = Current->next;
    }
    return size;
}
void PQueue::print(ostream &os){
    if (isEmpty())
    {
        return;
    }
    Node* Current = head;
    while (Current!= nullptr)
    {
        Current->data->print(os);
        Current = Current->next;
    }   
}