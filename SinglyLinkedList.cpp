#include "SinglyLinkedList.h"

// LinkedList::LinkedList() {
//   head = NULL;
// }

LinkedList::LinkedList(vector<int>& v) {
  int i = 1;
  this->len = v.size();

  this->head = new Node(v[0], NULL);
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
  len = 0;
  head = 0;
}

bool LinkedList::insert(int q) {
  Node* n = new Node(q, NULL);
  len++;

  if (head == NULL) {
    head = n;
    cout << n->data << " is now the start of the list." << endl;
  }
  else {
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    cout << "Inserting " << n->data << " at the end of the list." << endl;
    temp->next = n;
  }
  return true;
}

bool LinkedList::emplace(int q) {
  Node* n = new Node(q, NULL);
  len++;

  if (head == NULL) {
    head = n;
    cout << n->data << " is now the start of the list." << endl;
  }
  else {
    cout << "Inserting " << n->data << " at the start of the list." << endl;
    Node* temp = head;
    head = n;
    head->next = temp;
  }

  return true;
}

bool LinkedList::remove(int q) {
  if (q > this->len) {
    cout << "Error: " << q << " is greater than the LinkedList size, " << len << "." << endl;
    return false;
  }
  
  Node* temp = head;
  Node* prev = NULL;
  int run = 0;

  while (temp != NULL && ++run != q) {
    prev = temp;
    temp = temp->next;
  }

  cout << "Removing the " << q << "th index (1-based), " << temp->data << "." << endl;

  // removing logic
  prev->next = temp->next;
  delete temp;
  len--;

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
    cout << "The Linked List has now been reversed." << endl;
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
  cout << "\nLinked List [len=" << len << "]: ";
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next; 
  }
  cout << endl;
}