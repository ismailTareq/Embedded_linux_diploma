#ifndef LList
#define LList

#include <iostream>
using namespace std;
typedef int ElementType;

class LinkedList {
private:
   class Node {
   public:

       ElementType data;
       Node* next; 

       Node() : next(0) {}
       Node(ElementType dataValue) : data(dataValue), next(0) {}
   };
   typedef Node* NodePointer;
   NodePointer first;
   int mySize;

public:
   LinkedList(); 
   LinkedList(const LinkedList& origList);
   ~LinkedList(); 
   const LinkedList& operator=(const LinkedList& rightSide); 
   bool empty(); 
   void insert(ElementType dataVal, int index); 
   void erase(int index); 
   int search(ElementType dataVal); 
   void display(ostream& out) const; 
   int nodeCount(); 
   void reverse(); 
   bool ascendingOrder(); 
   friend istream& operator>>(istream& in, LinkedList& aList);
};

ostream& operator<<(ostream& out, const LinkedList& aList);
istream& operator>>(istream& in, LinkedList& aList);

#endif /* LList */

