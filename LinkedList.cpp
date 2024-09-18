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
        Node* current=head;
        Node* previous=nullptr;
 
        while(current!=nullptr)
        {
                if (x==current->data)
                {
                     if (previous!=nullptr)
                     {
                            previous->next=current->next;
                            current=previous->next;
                            continue;
                     }
                     else
                     {
                        //previous is already null if you are inside the else block.
                        Node *toDelete=head;
                        head=head->next;
                        current=head;
                        continue;
                     }
                }
            previous=current;
            current=current->next;
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