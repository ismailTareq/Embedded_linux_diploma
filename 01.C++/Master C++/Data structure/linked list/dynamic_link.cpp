#include "dynamic_link.hpp"

DynamicList::DynamicList(int maxSize) : mySize(0), myCapacity(maxSize), myArray(0) {
   myArray = new (nothrow) ElementType[myCapacity];
   if (myArray == NULL) {
       cout << "Error in allocating memory";
       exit(0);
   }
}

DynamicList::~DynamicList() {
   delete[] myArray;
}

DynamicList::DynamicList(const DynamicList& origList) : mySize(origList.mySize), myCapacity(origList.myCapacity) {
   myArray = new(nothrow) ElementType[myCapacity];

   if (myArray != 0)
       for (int i = 0; i < mySize; i++)
           myArray[i] = origList.myArray[i];
   else
   {
       cerr << "Inadequate memory to allocate storage for list\n";
       exit(1);
   }
}

DynamicList DynamicList::operator=(const DynamicList& rightHandSide) {
   if (this != &rightHandSide) 
   {
       if (myCapacity != rightHandSide.myCapacity)
       {
           delete[] myArray;
           myCapacity = rightHandSide.myCapacity;
           myArray = new(nothrow) ElementType[myCapacity];

           if (myArray == 0)
           {
               cerr << "Inadequate memory to allocate stack\n";
               exit(1);
           }
       }
       mySize = rightHandSide.mySize;
       for (int i = 0; i < mySize; i++)
           myArray[i] = rightHandSide.myArray[i];
   }
   return *this;
}

DynamicList DynamicList::operator+(const DynamicList& rightHandSide) {
   DynamicList l3(myCapacity + rightHandSide.myCapacity);
   for (int i = 0; i < mySize; i++)
       l3.insert(myArray[i], i);
   for (int i = 0; i < rightHandSide.mySize; i++)
       l3.insert(rightHandSide.myArray[i], mySize + i);
   return l3;
}

//--- Definition of empty()
bool DynamicList::empty() const {
   return mySize == 0;
}

//--- Definition of display()
void DynamicList::display(ostream& out) const {
   for (int i = 0; i < mySize; i++)
       out << myArray[i] << "  ";
}

//--- Definition of output operator
ostream& operator<< (ostream& out, const DynamicList& aList) {
   aList.display(out);
   return out;
}

//--- Definition of insert()
void DynamicList::insert(ElementType item, int pos) {
   if (mySize == myCapacity)
   {
       cerr << "No space for list element.\n";
       exit(1);
   }
   if (pos < 0 || pos > mySize)
   {
       cerr << "Illegal location to insert" << pos << ".  List unchanged.\n";
       return;
   }
   for (int i = mySize; i > pos; i--)
       myArray[i] = myArray[i - 1];
   myArray[pos] = item;
   mySize++;
}

void DynamicList::erase(int pos) {
   if (mySize == 0)
   {
       cerr << "List is empty\n";
       return;
   }
   if (pos < 0 || pos >= mySize)
   {
       cerr << "Illegal location to delete " << pos << ".  List unchanged.\n";
       return;
   }
   for (int i = pos; i < mySize - 1; i++)
       myArray[i] = myArray[i + 1];
   mySize--;
}

void DynamicList::leftRotation(int numOfRotations) {

   int rotations = numOfRotations % mySize;
   for (int i = 0; i < rotations; i++) {

       ElementType temp = myArray[0];
       erase(0);
       insert(temp, mySize);
   }

}

void DynamicList::removeDuplicates() {

   for (int i = 0; i < mySize - 1; i++) {

       if (myArray[i] == myArray[i + 1])
           erase(i);
   }

}

void DynamicList::deleteByValue(ElementType item) {

   for (int i = 0; i < mySize; i++) {

       if (myArray[i] == item)
           erase(i);

   }

}

void DynamicList::removeDuplicatesV2() {

   for (int i = 0; i < mySize; i++) {
       for (int j = 0; j < i; j++) {
           if (myArray[i] == myArray[j]) {
               erase(i);
               j = -1;
           }
       }
   }
}
