#include "queue.hpp"
#ifdef DQUEUE

Queue::Queue(int numElements) : myFront(0), myBack(0) {
   if (numElements <= 0) {
       cerr << "Error: Negative or zero capacity required -- terminating execution\n";
       exit(1);
   }
   myCapacity = numElements;
   myArray = new (nothrow) QueueElement[myCapacity];
   if (myArray == 0) {
       cerr << "Error: Inadequate memory to allocate queue -- terminating execution\n";
       exit(1);
   }
}

Queue::Queue(const Queue& original) : myFront(original.myFront), myBack(original.myBack), myCapacity(original.myCapacity) {
   myArray = new (nothrow) QueueElement[myCapacity];
   if (myArray == 0) {
       cerr << "Error: Inadequate memory to allocate queue -- terminating execution\n";
       exit(1);
   }
   else {
       for (int i = myFront; i < myBack; i++) {
           myArray[i] = original.myArray[i];
       }
   }
}

Queue::~Queue() {
   delete[] myArray;
}

const Queue& Queue::operator=(const Queue& rhs) {
   if (this != &rhs) {
       if (myCapacity != rhs.myCapacity) {
           this->~Queue();
           myCapacity = rhs.myCapacity;
           myArray = new(nothrow) QueueElement[myCapacity];
           if (myArray == 0) {
               cerr << "Error: Inadequate memory to allocate stack -- terminating execution\n";
               exit(1);
           }
       }
       myFront = rhs.myFront;
       myBack = rhs.myBack;
       for (int i = myFront; i < myBack; i++) {
           myArray[i] = rhs.myArray[i];
       }
   }
   return *this;
}

bool Queue::empty() const {
   return myFront == myBack;
}

void Queue::enqueue(const QueueElement& value) {
   int newBack = (myBack + 1) % myCapacity;
   if (newBack != myFront) { // i.e., queue isn't full
       myArray[myBack] = value;
       myBack = newBack;
   }
   else {
       cerr << "Queue-full! " << endl;
       exit(1);
   }
}

void Queue::display(ostream& out) const {
   if (empty()) {
       cerr << "Queue-empty!" << endl;
       return;
   }
   for (int i = myFront; i != myBack; i = (i + 1) % myCapacity) {
       out << myArray[i] << ' ';
   }
   cout << endl;
}

ostream& operator<< (ostream& out, const Queue& aQueue) {
   aQueue.display(out);
   return out;
}

QueueElement Queue::front() const {
   if (!empty())
       return myArray[myFront];
   else {
       cerr << "Queue Empty -- Returning garbage." << endl;
       QueueElement garbage;
       return garbage;
   }
}

void Queue::dequeue() {
   if (!empty())
       myFront = (myFront + 1) % myCapacity;
   else {
       cerr << "Queue Empty!" << endl;
   }
}

#endif // DQUEUE