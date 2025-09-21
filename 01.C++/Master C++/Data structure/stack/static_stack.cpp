#include "stack.hpp"
#ifdef SSTACK

Stack::Stack(int numElements) : myTop(-1), myCapacity(DEFAULT_CAPACITY) {}

Stack::Stack(const Stack& original) : myTop(original.myTop), myCapacity(DEFAULT_CAPACITY) {
   for (int i = 0; i <= myTop; i++) {
       myArray[i] = original.myArray[i];
   }
}

Stack::~Stack() {
}

const Stack& Stack::operator=(const Stack& rhs) {
   if (this != &rhs) {
       myTop = rhs.myTop;
       for (int i = 0; i <= myTop; i++) {
           myArray[i] = rhs.myArray[i];
       }
   }
   return *this;
}

bool Stack::empty() const {
   return myTop == -1;
}

void Stack::push(const StackElement& value) {
   if (myTop >= myCapacity - 1) {
       cerr << "Stack-full! " << endl;
       exit(1);
   }
   myArray[++myTop] = value;
}

void Stack::pop() {
   if (!empty())
       myTop--;
   else {
       cerr << "Stack Empty!" << endl;
   }
}

void Stack::display(ostream& out) const {
   if (empty()) {
       cerr << "Stack-empty!" << endl;
       return;
   }
   for (int i = myTop; i >= 0; i--) {
       out << myArray[i] << ' ';
   }
   out << endl;
}

ostream& operator<< (ostream& out, const Stack& aStack) {
   aStack.display(out);
   return out;
}

StackElement Stack::top() const {
   if (!empty())
       return myArray[myTop];
   else {
       cerr << "Stack Empty -- Returning garbage." << endl;
       StackElement garbage;
       return garbage;
   }
}


#endif // SSTACK