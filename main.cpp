#include <iostream>
#include <vector>
#include "SinglyLinkedList.h"

// TODO: add a function to remove duplicates

using namespace std;

int main() {
  vector<int> yolo = {1,5,2,6,8,3,66,21,645,26};
  LinkedList ll(yolo);

  ll.print();

  ll.insert(10);
  ll.print();

  ll.remove(5);
  ll.print();

  ll.remove(9);
  ll.print();

  ll.reverse();
  ll.print();

  ll.emplace(56);
  ll.print();

  LinkedList l2;

  l2.emplace(10);
  l2.print();
}