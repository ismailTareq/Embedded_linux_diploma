#ifndef STACK
#define STACK

// #define SSTACK 
// #define DSTACK 
// #define LLSTACK 

#include <iostream>
using namespace std;
typedef int StackElement;
const int DEFAULT_CAPACITY = 128;

class Stack {

public:
   Stack(int numElements = DEFAULT_CAPACITY);
   Stack(const Stack& original);
   ~Stack();
   const Stack& operator= (const Stack& rhs);
   bool empty() const;
   void push(const StackElement& value);
   void pop();
   void display(ostream& out) const;
   StackElement top() const;

private:
#ifdef SSTACK
   StackElement myArray[DEFAULT_CAPACITY];
#else
   StackElement* myArray;
#endif

#ifdef LLSTACK
   class Node {
   public:
       StackElement data;
       Node* next;
       Node(StackElement value, Node* link = 0) : data(value), next(link) {}
   };
   typedef Node* NodePointer;
   NodePointer myTop; // Pointer to top node of stack
#else
   int myTop; // Top index in stack
   int myCapacity; // Capacity of dynamic stack
#endif
};

ostream& operator<< (ostream& out, const Stack& aStack);

#endif /* STACK */

