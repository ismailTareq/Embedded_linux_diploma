#include "hash_chain.hpp"

HashTable::HashTable() {
   numberOfElements = 0;
   for (int i = 0; i < TableSize; i++)
        table[i] = NULL;
}

int HashTable::hash(string key) {
   int asciiSum = 0;
   for (int i = 0; i < key.length(); i++)
        asciiSum += key[i];
   return asciiSum % TableSize;
}

void HashTable::insert(string studentID, string studentName) {
   Node* studentNode = new Node;
   studentNode->key = studentID;
   studentNode->value = studentName;
   studentNode->next = NULL;

   int index = hash(studentID);

   if (table[index] == NULL) {
       table[index] = studentNode;
       numberOfElements++;
   }
   else {
       Node* temp = table[index];
       while (temp->key != studentID && temp->next != NULL) {
           temp = temp->next;
       }
       if (temp->key == studentID) {
           cout << "Student with ID: " << temp->key << " and name: " << temp->value << " exists." << endl;
       } 
       else {
           temp->next = studentNode;
           numberOfElements++;
       }
   }
}

void HashTable::remove(string studentID) {
   int index = hash(studentID);
   if (table[index] == NULL) {
       cout << "Student not found." << endl;
   }
   else if (table[index]->key == studentID) {
       // Deleting first node in the linkedList
       Node* temp = table[index];
       table[index] = table[index]->next;
       delete temp;
       numberOfElements--;
   }
   else {
       Node* parent = table[index], * locptr = table[index];
       while (locptr != NULL && locptr->key != studentID) {
           parent = locptr;
           locptr = locptr->next;
       }
       if (locptr == NULL) {
           cout << "Student not found." << endl;
       }
       else {
           parent->next = locptr->next;
           delete locptr;
           numberOfElements--;
       }
   }
}

void HashTable::print() {
   for (int i = 0; i < TableSize; i++) {
       if (table[i] != NULL) {
           cout << i << ": ";
           Node* temp = table[i];
           while (temp != NULL) {
               cout << temp->key << ": " << temp->value << "    ";
               temp = temp->next;
           }
           cout << endl;
       }
   }
}
