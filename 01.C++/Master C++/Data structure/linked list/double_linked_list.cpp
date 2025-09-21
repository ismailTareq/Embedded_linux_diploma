#include "double_linked_list.hpp"

DoublyLinkedList::Node::Node(ElementType dataValue) : data(dataValue), next(nullptr), prev(nullptr) {}

DoublyLinkedList::DoublyLinkedList() : first(nullptr), last(nullptr), mySize(0) {}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& origList) : first(nullptr), last(nullptr), mySize(origList.mySize) {
   if (mySize == 0) return;
   DoublyLinkedList::NodePointer origPtr = origList.first;
   first = new Node(origPtr->data);
   first->prev = nullptr;
   last = first;
   origPtr = origPtr->next;
   while(origPtr != 0)
   {
        DoublyLinkedList::NodePointer newNode = new Node(origPtr->data);
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
        origPtr = origPtr->next;
   }
}

DoublyLinkedList::~DoublyLinkedList() {
   DoublyLinkedList::NodePointer temp = first;
   while (temp) {
       DoublyLinkedList::NodePointer nextNode = temp->next;
       delete temp;
       temp = nextNode;
   }
}

const DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& rightSide) {
   if (this != &rightSide) {
       this->~DoublyLinkedList();
       mySize = rightSide.mySize;
       if (mySize == 0) {
           first = last = nullptr;
           return *this;
       }
       DoublyLinkedList::NodePointer origPtr = rightSide.first;
       first = new Node(origPtr->data);
       first->prev = nullptr;
       last = first;
       origPtr = origPtr->next;
       while (origPtr != 0) {
           DoublyLinkedList::NodePointer newNode = new Node(origPtr->data);
           last->next = newNode;
           newNode->prev = last;
           last = newNode;
           origPtr = origPtr->next;
       }
   }
   return *this;
}

bool DoublyLinkedList::empty() {
   return mySize == 0;
}

void DoublyLinkedList::insert(ElementType dataVal, int index) {
   if (index < 0 || index > mySize) {
       cerr << "Illegal location to insert -- " << index << endl;
       return;
   }
   DoublyLinkedList::NodePointer newNode = new Node(dataVal);
   if (index == 0) {
       newNode->next = first;
       if (first) first->prev = newNode;
       first = newNode;
       if (!last) last = newNode;
   }
   else if (index == mySize) {
       newNode->prev = last;
       last->next = newNode;
       last = newNode;
   }
   else {
       DoublyLinkedList::NodePointer temp = first;
       for (int i = 0; i < index - 1; i++) temp = temp->next;
       newNode->next = temp->next;
       newNode->prev = temp;
       temp->next->prev = newNode;
       temp->next = newNode;
   }
   mySize++;
}

void DoublyLinkedList::erase(int index) {
   if (index < 0 || index >= mySize) {
       cerr << "Illegal location to delete -- " << index << endl;
       return;
   }
   DoublyLinkedList::NodePointer temp;
   if (index == 0) {
       temp = first;
       first = first->next;
       if (first) first->prev = nullptr;
       else last = nullptr;
   }
   else if (index == mySize - 1) {
       temp = last;
       last = last->prev;
       last->next = nullptr;
   }
   else {
       temp = first;
       for (int i = 0; i < index; i++) temp = temp->next;
       temp->prev->next = temp->next;
       temp->next->prev = temp->prev;
   }
   delete temp;
   mySize--;
}

int DoublyLinkedList::nodeCount() {
   return mySize;
}

void DoublyLinkedList::reverse() {
   DoublyLinkedList::NodePointer temp = nullptr;
   DoublyLinkedList::NodePointer current = first;
   while (current) {
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;
       current = current->prev;
   }
   if (temp) first = temp->prev;
}

bool DoublyLinkedList::ascendingOrder() {
   if (mySize <= 1) return true;
   DoublyLinkedList::NodePointer temp = first;
   while (temp->next) {
       if (temp->data > temp->next->data) return false;
       temp = temp->next;
   }
   return true;
}

void DoublyLinkedList::display(ostream& out) const {
   DoublyLinkedList::NodePointer temp = first;
   while (temp) {
       out << temp->data << " ";
       temp = temp->next;
   }
}

ostream& operator<<(ostream& out, const DoublyLinkedList& aList) {
   aList.display(out);
   return out;
}

istream& operator>>(istream& in, DoublyLinkedList& aList) {
   ElementType val;
   in >> val;
   aList.insert(val, aList.mySize);
   return in;
}
