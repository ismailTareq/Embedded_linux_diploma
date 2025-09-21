#include "stack.hpp"
#ifdef DSTACK

Stack::Stack(int numElements) : myTop(-1) {
   if (numElements <= 0) {
       cerr << "Error: Negative or zero capacity required -- terminating execution\n";
       exit(1);
   }
   myCapacity = numElements;
   myArray = new (nothrow) StackElement[myCapacity];
   if (myArray == 0) {
       cerr << "Error: Inadequate memory to allocate stack -- terminating execution\n";
       exit(1);
   }
}

Stack::Stack(const Stack& original) : myTop(original.myTop), myCapacity(original.myCapacity) {
   myArray = new (nothrow) StackElement[myCapacity];
   if (myArray == 0) {
       cerr << "Error: Inadequate memory to allocate stack -- terminating execution\n";
       exit(1);
   }
   else {
       for (int i = 0; i <= myTop; i++) {
           myArray[i] = original.myArray[i];
       }
   }
}

Stack::~Stack() {
   delete[] myArray;
}

const Stack& Stack::operator=(const Stack& rhs) {
   if (this != &rhs) {
       if (myCapacity != rhs.myCapacity) {
           this->~Stack();
           myCapacity = rhs.myCapacity;
           myArray = new(nothrow) StackElement[myCapacity];
           if (myArray == 0) {
               cerr << "Error: Inadequate memory to allocate stack -- terminating execution\n";
               exit(1);
           }
       }
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

void Stack::pop() {
   if (!empty())
       myTop--;
   else {
       cerr << "Stack Empty!" << endl;
   }
}


#endif // DSTACK