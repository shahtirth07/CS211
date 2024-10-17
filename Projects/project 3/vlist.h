#ifndef VLIST_H
#define VLIST_H
#include "video.h"

using namespace std;


class Vlist {
public:
   Vlist() { m_head = NULL; }
   void insert(Video *video);
    void print();
    int length();
    void lookup(string& title);
    void remove(string& title);
    ~Vlist();



private:
  class Node {
  public:
    Node(Video *video, Node *next) { m_video = video; m_next = next; }
    Video *m_video;
    Node *m_next;
  };
  Node *m_head;
};
#endif
