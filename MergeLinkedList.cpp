#include <iostream>
using namespace std;

class LinkedList {
private:
class Node {
public:
int data;
Node* next;
Node(int x) {

data = x;

next = nullptr;

}

};

Node* head;

public:

LinkedList() {

head = nullptr;

}

void insert(int x) {

Node* newNode = new Node(x);

if (head == nullptr) {

head = newNode;

} else {

Node* temp = head;

while (temp->next != nullptr) {

temp = temp->next;

}

temp->next = newNode;

}

}

LinkedList merge(LinkedList& list1, LinkedList& list2) {

    LinkedList list3;

    Node* curr1 = list1.head;

    Node* curr2 = list2.head;

    if (curr1 == nullptr && curr2 == nullptr)

    {

        list3.head = nullptr;

        return list3;

    }

    else if (curr1 == nullptr)

    {

        return list2;

    }

    else if (curr2 == nullptr)

    {

        return list1;

    }

    else

    {

        while (curr1 != nullptr || curr2 != nullptr)

        {

            if (curr1 != nullptr && curr1->data <= curr2->data)

            {

                list3.insert(curr1->data);

                curr1 = curr1->next;

            }

            else{

                list3.insert(curr2->data);

                curr2 = curr2->next;

            }

           

        }

        return list3;

    }

   

    

 

//TODO

}

void printList() {

Node* temp = head;

while (temp != nullptr) {

cout << temp->data << " ";

temp = temp->next;

}

cout << endl;

}

}

;

int main() {

LinkedList list1;

list1.insert(1);

list1.insert(3);

list1.insert(5);

list1.insert(7);

LinkedList list2;

list2.insert(2);

list2.insert(4);

list2.insert(6);

list2.insert(8);

 

LinkedList mergedList;

mergedList = mergedList.merge(list1, list2);

 

cout << "Merged list: ";

mergedList.printList();

 

return 0;

}