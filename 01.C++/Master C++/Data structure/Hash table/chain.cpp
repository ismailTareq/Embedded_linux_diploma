#include "hash_chain.hpp"
int main() 
{
   HashTable students;
   students.insert("ID1", "Name1");
   students.insert("ID2", "Name2");
   students.insert("e07981", "Nada Amr");
   students.insert("B", "Nada");
   cout << "After Insertion:" << endl;
   students.print();
   cout << endl;
   students.remove("B");
   cout << "After Deletion:" << endl;
   students.print();
   cout << endl;

   return 0;
}