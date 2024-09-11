#include <iostream>
using namespace std;
class Stack
{
private:
    // Inner class representing a node in the linked list
    class Node
    {
    public:
        int data;   // data stored in the node
        Node *next; // pointer to the next node
        // Constructor to initialize the data and next pointers of the node
        Node(int d)
        {
            data = d;
            next = nullptr;
            int size = 0;
        }
        // Destructor for the node (currently empty)
        ~Node() {}
    };
    Node *head; // Pointer to the head node of the linked list
public:
    // Constructor for the stack, initializing the head pointer to null
    Stack()
    {
        head = nullptr;
    }
    // Destructor for the stack, freeing up all the dynamically allocated memory
    ~Stack()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    // Method to add a new element to the top of the stack
    void push(int x)
    {
        // Create a new node with the given data
        Node *newNode = new Node(x);
        // Set the next pointer of the new node to point to the current top node
        newNode->next = head;
        // Set the head pointer to point to the new node, making it the new top
        head = newNode;
    }
    // Method to remove the top element from the stack
    void pop()
    {
        // Check if there is at least one element in the stack
        if (head != nullptr)
        {
            // Create a temporary pointer to the current top node
            Node *temp = head;
            // Set the head pointer to point to the next node in the list
            head = head->next;
            // Delete the original top node
            delete temp;
        }
    }
    // Method to return the value of the top element in the stack
    int top()
    {
        // Check if there is at least one element in the stack
        if (head != nullptr)
        {
            // Return the data stored in the current top node
            return head->data;
        }
        // Return 0 if the stack is empty
        return 0;
    }
};