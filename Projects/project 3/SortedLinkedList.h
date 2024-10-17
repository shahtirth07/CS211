#include <iostream>
#include "video.h"

using namespace std;
/*
Here's a breakdown of what's happening in the code:
This class is a linked list of integers where the integers always remain sorted. The insert and the remove function in this class 
preserves the sorted invariant property of the class. 

We define a class called SortedLinkedList, which contains an inner class called node.
The node class contains two member variables: data, which stores the integer value associated with the node, and next, which is a pointer to the next node in the list.
The node class also has a constructor that takes an integer argument and initializes data to that value, and sets next to nullptr.
The SortedLinkedList class has a private member variable called head, which is a pointer to the first node in the list.
The SortedLinkedList class also has a constructor that initializes head to nullptr.
The SortedLinkedList class has a destructor that frees up memory by deleting each node in the list.
The insert function inserts a new element into the list in sorted order.
If the list is empty, the new element becomes the head of the list.
If the new element is less than the head of the list, it becomes the new head.
Otherwise, we traverse the list until we find the correct position to insert the new element, and then insert it there.
The remove function removes the first occurrence of an element from the list.
It traverses the list until it finds the node containing the element to be removed, or reaches the end of the list.
If it finds the node containing the element to be removed, it updates the pointers to remove the node from the list and then frees up the memory used by that node.

*/
class SortedLinkedList {

    // inner class for each node in the list
    class Node {
    public:
        Video* data; // data stored in the node
        Node* next; // pointer to next node in the list

        // constructor for creating a new node
        Node(Video* data) {
            this->data = data;
            next = nullptr;
        }
    };

private:
    Node* head; // pointer to the head of the list

public:
    // constructor for creating a new empty list
    SortedLinkedList() {
        head = nullptr;
    }

    // destructor to free up memory when the list is destroyed
    ~SortedLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // insert a new element into the list in sorted order
    void insertInList(Video* data) {
        Node* newnode = new Node(data);

        // if list is empty, insert newnode as head
        if (head == nullptr) {
            head = newnode;
        }
        // if newnode is less than the head, insert it as the new head
        else if (data < head->data) {
            newnode->next = head;
            head = newnode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr && current->next->data <= data) {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }

    // remove the first occurrence of an element from the list
    void remove(Video* data) {
        Node* current = head;
        Node* prev = nullptr;

        // traverse the list until we find the node containing data or reach the end
        while (current != nullptr && current->data != data) {
            prev = current;
            current = current->next;
        }

        // if we didn't find the data in the list, do nothing
        if (current == nullptr) {
            return;
        }

        // if the node containing data is the head, update the head
        if (current == head) {
            head = current->next;
        }
        else {
            prev->next = current->next;
        }

        // delete the node containing data and free up memory
        delete current;
    }
};

/* int main() {
    SortedLinkedList list;

    list.insert(3);
    list.insert(1);
    list.insert(4);
    list.insert(1);
    list.insert(5);

    list.remove(4);

    //make sure to add in a print function to test it out. 

    return 0;
} */

