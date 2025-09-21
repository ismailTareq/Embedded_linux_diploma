#include "double_linked_list.hpp"
#include <iostream>
using namespace std;

int main() {
   DoublyLinkedList list;
   list.insert(3, 0);
   list.insert(2, 0);
   list.insert(1, 0);
   cout << list << endl;

   list.insert(42, 2);
   cout << list << endl;

   list.erase(0);
   cout << list << endl;

   cout << (list.empty() ? "Empty" : "Not Empty") << endl;

   list.erase(0);
   list.erase(0);
   list.erase(0);

   cout << (list.empty() ? "Empty" : "Not Empty") << endl;

   DoublyLinkedList list1;
   list1.insert(5, 0);
   list1.insert(4, 0);
   list1.insert(3, 0);
   list1.insert(2, 0);
   list1.insert(1, 0);

   DoublyLinkedList list2;
   list2.insert(1, 0);
   list2.insert(2, 0);
   list2.insert(3, 0);
   list2.insert(4, 0);
   list2.insert(5, 0);

   cout << list1 << endl << list2 << endl;
   list1 = list2;
   cout << list1 << endl << list2 << endl;

   return 0;
}
