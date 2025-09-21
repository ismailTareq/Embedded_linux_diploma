#ifndef HTable_hpp
#define HTable_hpp

#include <string>
#include <iostream>
using namespace std;

const int TableSize = 100;

class HashTable {
private:
   class Node {
   public:
       string key; 
       string value; 
       Node* next;
   };

   int numberOfElements;
   Node* table[TableSize];
   int hash(string key);
public:
   HashTable();
   void insert(string studentID, string studentName);
   void remove(string studentID);
   void print();
};

#endif /* HTable_hpp */
