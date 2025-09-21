#include "queue.hpp"
#ifdef LLQUEUE

Queue::Queue(int) : myFront(NULL), myBack(NULL) {} 

Queue::Queue(const Queue& original) {
   if (original.empty()) {
       myFront = myBack = NULL;
   }
   else {
       myFront = myBack = new Queue::Node(original.front());
       Queue::NodePointer origPtr = original.myFront->next;
       while (origPtr != NULL) {
           myBack->next = new Queue::Node(origPtr->data);
           myBack = myBack->next;
           origPtr = origPtr->next;
       }
   }
}

Queue::~Queue() {
   Queue::NodePointer currPtr = myFront, nextPtr = NULL;
   while (currPtr != NULL) {
       nextPtr = currPtr->next;
       delete currPtr;
       currPtr = nextPtr;
   }
}

const Queue& Queue::operator=(const Queue& rhs) {
   if (this != &rhs) {
       this->~Queue();
       if (rhs.empty()) {
           myFront = myBack = NULL;
       }
       else {
           myFront = myBack = new Queue::Node(rhs.front());
           Queue::NodePointer rhsPtr = rhs.myFront->next;
           while (rhsPtr != NULL) {
               myBack->next = new Queue::Node(rhsPtr->data);
               myBack = myBack->next;
               rhsPtr = rhsPtr->next;
           }
       }
   }
   return *this;
}

bool Queue::empty() const {
   return myFront == NULL;
}

void Queue::enqueue(const QueueElement& value) {
   Queue::NodePointer newptr = new Queue::Node(value);
   if (empty()) {
       myFront = myBack = newptr;
   }
   else {
       myBack->next = newptr;
       myBack = newptr;
   }
}

void Queue::display(ostream& out) const {
   if (empty()) {
       cerr << "Queue-empty!" << endl;
       return;
   }
   Queue::NodePointer myPtr = myFront;
   while (myPtr != NULL) {
       out << myPtr->data << ' ';
       myPtr = myPtr->next;
   }
   out << endl;
}

ostream& operator<< (ostream& out, const Queue& aQueue) {
   aQueue.display(out);
   return out;
}

QueueElement Queue::front() const {
   if (!empty())
       return myFront->data;
   else {
       cerr << "Queue Empty -- Returning garbage." << endl;
       QueueElement garbage;
       return garbage;
   }
}

void Queue::dequeue() {
   if (!empty()) {
       Queue::NodePointer ptr = myFront;
       myFront = myFront->next;
       delete ptr;
       if (myFront == NULL)    
           myBack = NULL;
   }
   else {
       cerr << "Queue Empty!" << endl;
   }
}

#endif // LLQUEUE