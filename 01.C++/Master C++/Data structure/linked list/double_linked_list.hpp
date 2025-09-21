#ifndef DLinkedList
#define DLinkedList

#include <iostream>
using namespace std;

typedef int ElementType;

class DoublyLinkedList {
private:
   class Node {
   public:
       ElementType data;
       Node* next;
       Node* prev;
       Node(ElementType dataValue);
   };

   typedef Node* NodePointer;
   NodePointer first;
   NodePointer last;
   int mySize;

public:
   DoublyLinkedList();
   DoublyLinkedList(const DoublyLinkedList& origList);
   ~DoublyLinkedList();
   const DoublyLinkedList& operator=(const DoublyLinkedList& rightSide);
   bool empty();
   void insert(ElementType dataVal, int index);
   void erase(int index);
   int search(ElementType dataVal);
   void display(ostream& out) const;
   int nodeCount();
   void reverse();
   bool ascendingOrder();

   friend ostream& operator<<(ostream& out, const DoublyLinkedList& aList);
   friend istream& operator>>(istream& in, DoublyLinkedList& aList);
};

#endif /* DLinkedList */
