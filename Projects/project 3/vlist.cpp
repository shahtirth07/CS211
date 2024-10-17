#include "vlist.h"
#include "SortedLinkedList.h"
#include<iostream>

using namespace std;

Vlist::~Vlist() {
    Node* current = m_head;
    while (current == nullptr) {
        Node* next = current->m_next;
        delete current->m_video;
        delete current;
        current = next;
    }
}

void Vlist::insert(Video* video) {
    Node* newNode = new Node{video, nullptr};
    if (m_head==nullptr || video->get_title() < m_head->m_video->get_title()) {
        newNode->m_next = m_head;
        m_head = newNode;
    } else {
        Node* current = m_head;
        while (current->m_next && current->m_next->m_video->get_title() < video->get_title()) {
            current = current->m_next;
        }
        newNode->m_next = current->m_next;
        current->m_next = newNode;
    }
}

void Vlist::print() {
    Node* current = m_head;
    while (current!=nullptr) {
        current->m_video->print();
        current = current->m_next;
    }
}

void Vlist::lookup(string& title) {
    Node* current = m_head;
    while (current) {
        if (current->m_video->get_title() == title) {
            current->m_video->print();
            return;
        }
        current = current->m_next;
    }
    cerr << "Title <" << title << "> not in list." << endl;
}

void Vlist::remove(string& title) {
    Node* current = m_head;
    Node* prev = nullptr;

    while (current) {
        if (current->m_video->get_title() == title) {
            if (prev) {
                prev->m_next = current->m_next;
            } else {
                m_head = current->m_next;
            }
            delete current->m_video;
            delete current;
            return;
        }
        prev = current;
        current = current->m_next;
    }
    cerr << "Title <" << title << "> not in list, could not delete." << endl;
}


int Vlist::length() {
    int count = 0;
    Node* current = m_head;
    while (current) {
        count++;
        current = current->m_next;
    }
    return count;
}
