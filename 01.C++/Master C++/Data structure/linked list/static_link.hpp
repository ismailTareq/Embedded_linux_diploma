#ifndef STATICLIST
#define STATICLIST

#include <iostream>
using namespace std;

const int CAPACITY = 1024;
typedef int ElementType;

class StaticList {

private:
   int mySize;                              // Current size of list stored in myArray
   ElementType myArray[CAPACITY];           // Array to store list elements

public:
   StaticList();                            // Construct an empty (mySize=0) List object.
   bool empty() const;                      // Check if a list is empty.
   void insert(ElementType item, int pos);  // Insert a value into the list at a given position.
   void erase(int pos);                     // Remove a value from the list at a given position.
   void display(ostream& out) const;        // Prints out the list
   // Extra -----------------------------------------------------------------------------------
   void leftRotation(int numOfRotations);
   void removeDuplicates();
   void deleteByValue(ElementType item);
};

ostream& operator<< (ostream& out, const StaticList& aList);

#endif /* STATICLIST */
