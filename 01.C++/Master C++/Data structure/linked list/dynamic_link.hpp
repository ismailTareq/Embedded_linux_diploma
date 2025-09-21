#ifndef DYNAMICLIST
#define DYNAMICLIST

#include <iostream>
using namespace std;

const int MAX_SIZE = 1024;
typedef int ElementType;

class DynamicList {

private:
   int mySize;                // current size of list
   int myCapacity;            // capacity of array
   ElementType* myArray;      // pointer to dynamic array

public:
   DynamicList(int maxSize = MAX_SIZE);
   ~DynamicList();
   DynamicList(const DynamicList& origList);
   DynamicList operator=(const DynamicList& rightHandSide);
   DynamicList operator+(const DynamicList& rightHandSide);
   bool empty() const;
   void insert(ElementType item, int pos);
   void erase(int pos);
   void display(ostream& out) const; 
   void leftRotation(int numOfRotations); 
   void removeDuplicates();
   void removeDuplicatesV2(); 
   void deleteByValue(ElementType item);

};

ostream& operator<< (ostream& out, const DynamicList& aList);

#endif /* DYNAMICLIST */
