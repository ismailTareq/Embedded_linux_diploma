#include "linked_list.hpp"
#include <iostream>
using namespace std;

int main() {

   LinkedList llist;
   llist.insert(3, 0);
   llist.insert(2, 0);
   llist.insert(1, 0);
   cout << llist << endl;
   llist.insert(42, 2);
   cout << llist << endl;
   llist.erase(0);
   cout << llist << endl;
   cout << llist << endl;
   cout << (llist.empty() ? "Empty" : "Not Empty") << endl;
   llist.erase(0);
   cout << (llist.empty() ? "Empty" : "Not Empty") << endl;
   llist.erase(0);
   cout << (llist.empty() ? "Empty" : "Not Empty") << endl;
   llist.erase(0);
   cout << (llist.empty() ? "Empty" : "Not Empty") << endl;
   llist.erase(0);

   LinkedList llist1;
   llist1.insert(5, 0);
   llist1.insert(4, 0);
   llist1.insert(3, 0);
   llist1.insert(2, 0);
   llist1.insert(1, 0);

   LinkedList llist2;
   llist2.insert(1, 0);
   llist2.insert(2, 0);
   llist2.insert(3, 0);
   llist2.insert(4, 0);
   llist2.insert(5, 0);

   cout << llist1 << endl << llist2 << endl;
   llist1 = llist2;
   cout << llist1 << endl << llist2 << endl;
}