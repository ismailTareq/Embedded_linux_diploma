#include "static_link.hpp"


StaticList::StaticList() : mySize(0) {}

bool StaticList::empty() const { return mySize == 0; }

void StaticList::display(ostream& out) const 
{
   for (int i = 0; i < mySize; i++)
       out << myArray[i] << "  ";
}

ostream& operator<< (ostream& out, const StaticList& aList) 
{
   aList.display(out);
   return out;
}

void StaticList::insert(ElementType item, int pos) 
{
   if (mySize == CAPACITY){
       cerr << "No space for list element\n";
       exit(1);
   }
   if (pos < 0 || pos > mySize){
       cerr << "*** Illegal location to insert -- " << pos << ".  List unchanged. ***\n";
       return;
   }
   for (int i = mySize; i > pos; i--)
       myArray[i] = myArray[i - 1];
   myArray[pos] = item;
   mySize++;
}

void StaticList::erase(int pos) 
{
   if (empty()){
       cerr << "List is empty\n";
       return;
   }
   if (pos < 0 || pos >= mySize){
       cerr << "Illegal location to delete -- " << pos << ".  List unchanged. ***\n";
       return;
   }
   for (int i = pos; i < mySize; i++)
       myArray[i] = myArray[i + 1];
   mySize--;
}

void StaticList::leftRotation(int numOfRotations) 
{

   int rotations = numOfRotations % mySize;
   for (int i = 0; i < rotations; i++) {
        ElementType temp = myArray[0];
        erase(0);
        insert(temp,mySize);
   }

}

void StaticList::removeDuplicates() 
{

   for (int i = 0; i < mySize; i++) {

       if (myArray[i] == myArray[i + 1])
           erase(i);
   }

}


void StaticList::deleteByValue(ElementType item) 
{
   for (int i = 0; i < mySize; i++) {

       if (myArray[i] == item)
           erase(i);
   }

}
