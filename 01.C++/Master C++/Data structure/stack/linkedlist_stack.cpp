#include "stack.hpp"
#ifdef LLSTACK

Stack::Stack(int) : myTop(NULL) {}

Stack::Stack(const Stack& original) {
   if (original.empty()) {
       myTop = NULL;
   }
   else {
       myTop = new Stack::Node(original.top());
       Stack::NodePointer currPtr = myTop, origPtr = original.myTop->next;
       while (origPtr != NULL) {
           currPtr->next = new Stack::Node(origPtr->data);
           currPtr = currPtr->next;
           origPtr = origPtr->next;
       }
   }
}

Stack::~Stack() {
   Stack::NodePointer currPtr = myTop, nextPtr = NULL;
   while (currPtr != NULL) {
       nextPtr = currPtr->next;
       delete currPtr;
       currPtr = nextPtr;
   }
}

const Stack& Stack::operator=(const Stack& rhs) {
   if (this != &rhs) {
       this->~Stack();
       if (rhs.empty()) {
           myTop = NULL;
       }
       else {
           myTop = new Stack::Node(rhs.top());
           Stack::NodePointer currPtr = myTop, rhsPtr = rhs.myTop->next;
           while (rhsPtr != NULL) {
               currPtr->next = new Stack::Node(rhsPtr->data);
               currPtr = currPtr->next;
               rhsPtr = rhsPtr->next;
           }
       }
   }
   return *this;
}

bool Stack::empty() const {
   return myTop == NULL;
}

void Stack::push(const StackElement& value) {
   myTop = new Stack::Node(value, myTop);
}

void Stack::display(ostream& out) const {
   if (empty()) {
       cerr << "Stack-empty!" << endl;
       return;
   }
   Stack::NodePointer myPtr = myTop;
   while (myPtr != NULL) {
       out << myPtr->data << ' ';
       myPtr = myPtr->next;
   }
   out << endl;
}

ostream& operator<< (ostream& out, const Stack& aStack) {
   aStack.display(out);
   return out;
}

StackElement Stack::top() const {
   if (!empty())
       return myTop->data;
   else {
       cerr << "Stack Empty -- Returning garbage." << endl;
       StackElement garbage;
       return garbage;
   }
}

void Stack::pop() {
   if (!empty()) {
       Stack::NodePointer ptr = myTop;
       myTop = myTop->next;
       delete ptr;
   }
   else {
       cerr << "Stack Empty!" << endl;
   }
}

#endif // LLSTACK