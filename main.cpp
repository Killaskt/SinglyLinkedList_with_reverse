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
    LinkedList();
    ~LinkedList();
    LinkedList(vector<int>&);

    bool insert(int);  
    bool reverse();
    void print();

  private:
    Node* head;
};

LinkedList::LinkedList() {
  head = NULL;
}

LinkedList::LinkedList(vector<int>& v) {
  int i = 1;
  head = new Node(v[0], NULL);
  Node* temp = head;
  while (i < v.size()) {
    Node* t = new Node(v[i], NULL);
    // cout << t->data << " ";
    temp->next = t;
    temp = temp->next;

    i++;
  }
}

LinkedList::~LinkedList() {
  Node* temp = head;
  while (temp != NULL) {
    Node* next = temp->next;
    delete temp;
    temp = next;
  }
  head = 0;
}

bool LinkedList::insert(int q) {
  Node* i1 = new Node(q, NULL);

  if (head == NULL) {
    head = i1;
  }
  else {
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = i1;
  }
  return true;
}

bool LinkedList::reverse() {

  try {
    if (head == NULL)
      throw 10;
    
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    head = prev;
  } catch (int x) {
    cout << "Error " << x << ": Head is empty." << endl;
    return false;
  }

  return true;
}

void LinkedList::print() {
  if (head == NULL)
    return;
  
  Node* temp = head;
  cout << "\nLinked List holds: ";
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next; 
  }
  cout << endl;
}


int main() {
  vector<int> yolo = {1,5,2,6,8,3,66,21,645,26};
  LinkedList ll(yolo);

  ll.print();
  ll.insert(10);
  ll.print();
  ll.reverse();
  ll.print();
}