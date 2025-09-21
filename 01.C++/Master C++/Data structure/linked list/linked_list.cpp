#include "linked_list.hpp"

LinkedList::LinkedList() : first(0), mySize(0) {}

LinkedList::LinkedList(const LinkedList& origList) : first(0), mySize(origList.mySize) {
   if(mySize == 0)
        return ;
    LinkedList::NodePointer origPtr, lastPtr;
    first = new Node(origList.first->data);
    lastPtr = first;
    origPtr = origList.first->next;
    while(origPtr != 0)
    {
        lastPtr->next = new Node(origPtr->data);
        lastPtr = lastPtr->next;
        origPtr = origPtr->next;
    }

}

inline LinkedList::~LinkedList() {
   LinkedList::NodePointer prev = first, ptr;
   while (prev != 0)
   {
       ptr = prev->next;
       delete prev;
       prev = ptr;
   }
}

bool LinkedList::empty() {
   return mySize == 0;
}

const LinkedList& LinkedList::operator=(const LinkedList& rightSide) {
    if (mySize == 0) 
    {
        first = 0;
        return *this;
    }
    mySize = rightSide.mySize;
    if(this != &rightSide)
    {
        this->~LinkedList();
        LinkedList::NodePointer origPtr, lastPtr;
        first = new Node(rightSide.first->data);  // copy first node
        lastPtr = first;
        origPtr = rightSide.first->next;

        while (origPtr != 0)
        {
            lastPtr->next = new Node(origPtr->data);
            origPtr = origPtr->next;
            lastPtr = lastPtr->next;
        }
    }
    return *this;
}

void LinkedList::insert(ElementType dataVal, int index) {
   if (index < 0 || index > mySize)
   {
       cerr << "Illegal location to insert -- " << index << endl;
       return;
   }
   mySize++;
   LinkedList::NodePointer newPtr = new Node(dataVal), tempPtr = first;
   if (index == 0)
   {
       newPtr->next = first;
       first = newPtr;
   }
   else {
       for (int i = 1; i < index; i++)
           tempPtr = tempPtr->next;
       newPtr->next = tempPtr->next;
       tempPtr->next = newPtr;
   }
}

void LinkedList::erase(int index) {
   if (index < 0 || index >= mySize)
   {
       cerr << "Illegal location to delete" << index << endl;
       return;
   }
   mySize--;
   LinkedList::NodePointer ptr, tempPtr = first;
   if (index == 0)
   {
       ptr = first;
       first = ptr->next;
       delete ptr;
   }
   else {
       for (int i = 1; i < index; i++)
           tempPtr = tempPtr->next;
       ptr = tempPtr->next;
       tempPtr->next = ptr->next;
       delete ptr;
   }
}

int LinkedList::search(ElementType dataVal) {
   int loc;
   LinkedList::NodePointer tempPtr = first;
   for (loc = 0; loc < mySize; loc++)
       if (tempPtr->data == dataVal)
           return loc;
       else
           tempPtr = tempPtr->next;
   return -1;
}

void LinkedList::display(ostream& out) const {
   LinkedList::NodePointer tempPtr = first;
   while (tempPtr != 0)
   {
       out << tempPtr->data << "  ";
       tempPtr = tempPtr->next;
   }
}

int LinkedList::nodeCount() {
   int count = 0;
   LinkedList::NodePointer tempPtr = first;
   while (tempPtr != 0)
   {
       count++;
       tempPtr = tempPtr->next;
   }
   return count;
} 

void LinkedList::reverse() {
   NodePointer prevPtr = 0, currentPtr = first, nextPtr;
   while (currentPtr != 0)
   {
       nextPtr = currentPtr->next;
       currentPtr->next = prevPtr;
       prevPtr = currentPtr;
       currentPtr = nextPtr;
   }
   first = prevPtr;       
}

bool LinkedList::ascendingOrder() {
   if (mySize <= 1)
       return true;
   NodePointer prevPtr = first, tempPtr = first->next;
   while (tempPtr != 0 && prevPtr->data <= tempPtr->data)
   {
       prevPtr = tempPtr;
       tempPtr = tempPtr->next;
   }
   if (tempPtr != 0)
       return false;
   // else
   return true;
}

ostream& operator<<(ostream& out, const LinkedList& aList) {
   aList.display(out);
   return out;
}

istream& operator>>(istream& in, LinkedList& aList) {
   ElementType val;
   in >> val;
   aList.insert(val, aList.mySize); // Needed friend to access "mySize"
   return in;
}

