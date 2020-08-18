#ifndef SinglyLinkedList
#define SinglyLinkedList
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  Node(int d, Node* n) : data(d), next(n) {};
  int data;
  Node* next;
};

class LinkedList {
  public:
    LinkedList() : head(NULL), len(0) {};
    ~LinkedList();
    LinkedList(vector<int>&);

    bool insert(int);
    bool emplace(int);  
    bool reverse();
    bool remove(int);
    void print();

  private:
    Node* head;
    int len = 0;
};
 
#endif