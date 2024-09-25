#include <iostream>
using namespace std;
 
class LinkedList
{
   
    private:
    class Node
    {
        public:
        int data;
        Node* next;
 
        Node(int d,Node* n)
        {
            this->data=d;
            this->next=n;
        }
    };
     
    Node* head;
    int size;
    public:
    LinkedList()
    {
        head=nullptr;
        size=0;
    }
    ~LinkedList()
    {
        Node* previous=nullptr;
        Node* current=head;
        while(current!=nullptr)
        {
            previous=current;
            current=current->next;
            delete previous;
        }
    }
   void insertAtHead(int x)
    {
                head=new Node(x,head);
    }
    void printLinkedList()
    {
        Node* current=head;
        while(current!=nullptr)
        {
              cout << "The data is " <<current->data <<endl;
              current=current->next;
        }
        //current must be null for the entire linked list to be printed
 
    }
    void insertAtTail(int x)
    {
        if (head==nullptr)
        {
            this->head=new Node(x,nullptr);      
        }
        else
        {
            Node* current=head;
            Node* previous=nullptr;
            while(current!=nullptr)
            {
                  previous=current;
                current=current->next;
            }
            previous->next=new Node (x,nullptr);        
        }
    }
 
    void removeAllOccurrences(int x)
    {
        if (head == nullptr) {
            return;
        } 
        else {
          head =  __removeAllOccurences(head, x);
        }
    }

    Node* __removeAllOccurences(Node* current, int data) {
        if (current == nullptr) {
            return nullptr;
        }
        Node* newHead =  __removeAllOccurences(current->next, data);
        if (current->data == data) {
            delete current;
            return newHead;
        } else {
            current -> next = newHead;
            return current;
        }
    }
};
 
 
int main()
{
    LinkedList *l1 = new LinkedList();
    //l1->insertAtHead(1);
    //l1->insertAtHead(2);
    //l1->insertAtHead(3);
    //l1->insertAtHead(4);
    //l1->insertAtHead(5);
    l1->insertAtTail(3);
    l1->insertAtTail(2);
    l1->insertAtTail(3);
    l1->insertAtTail(3);
    l1->insertAtTail(3);
    l1->insertAtTail(3);
    l1->insertAtTail(4);
    l1->insertAtTail(5);
    l1->insertAtTail(3);
    l1->printLinkedList();
    l1->removeAllOccurrences(3);
    cout <<endl;
    l1->printLinkedList();
    delete l1;
 
}