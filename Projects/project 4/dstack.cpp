//dstack.cpp
//shah, tirth
//tshah
#include "dstack.h"
#include <iostream>

using namespace std;

int count = 0;

Dstack::Dstack() {
    head = nullptr;
}

void Dstack::push(double val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    count++;
}

bool Dstack::pop(double *val) {
    if (!empty()) {
        Node* temp = head;
        head = head->next;
        *val = temp->data;
        delete temp;
        count--;
        return true;
    }
    return false;
}

int Dstack::size() {
    return count;
}

bool Dstack::empty() {
    if(head != nullptr) {
        return false;
    }
    return true;
}

double Dstack::top()
    {
        if (head != nullptr)
        {
            return head->data;
        }
        return 0;
    }

Dstack::~Dstack() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}