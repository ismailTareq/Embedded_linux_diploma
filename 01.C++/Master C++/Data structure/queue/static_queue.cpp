#include "queue.hpp"
#ifdef SQUEUE

Queue::Queue(int numElements) : myFront(0), myBack(0), myCapacity(DEFAULT_CAPACITY) {}

Queue::Queue(const Queue& original) : myFront(original.myFront), myBack(original.myBack), myCapacity(DEFAULT_CAPACITY) {
   for (int pos = myFront; pos < myBack; pos++) {
       myArray[pos] = original.myArray[pos];
   }
}

Queue::~Queue() {}

const Queue& Queue::operator=(const Queue& rhs) {
   if (this != &rhs) {
       myFront = rhs.myFront;
       myBack = rhs.myBack;
       for (int pos = myFront; pos < myBack; pos++) { 
           myArray[pos] = rhs.myArray[pos];
       }
   }
   return *this;
}

bool Queue::empty() const {
   return myFront == myBack;
}

void Queue::enqueue(const QueueElement& value) {
   int newBack = (myBack + 1) % myCapacity;
   if (newBack != myFront) { 
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

#endif // SQUEUE