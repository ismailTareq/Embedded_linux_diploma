#include "dynamic_link.hpp"
#include <iostream>
using namespace std;

int main() {

   DynamicList dlist;
   dlist.insert(3, 0);
   dlist.insert(2, 0);
   dlist.insert(1, 0);
   cout << dlist << endl;
   dlist.insert(42, 2);
   cout << dlist << endl;
   dlist.erase(0);
   cout << dlist << endl;
   dlist.deleteByValue(42);
   cout << dlist << endl;
   cout << (dlist.empty() ? "Empty" : "Not Empty") << endl;
   dlist.erase(0);
   cout << (dlist.empty() ? "Empty" : "Not Empty") << endl;
   dlist.erase(0);
   cout << (dlist.empty() ? "Empty" : "Not Empty") << endl;
   dlist.erase(0);
   cout << (dlist.empty() ? "Empty" : "Not Empty") << endl;
   dlist.erase(0);
   dlist.insert(5, 0);
   dlist.insert(4, 0);
   dlist.insert(3, 0);
   dlist.insert(2, 0);
   dlist.insert(1, 0);
   cout << "Input list: " << dlist << endl;
   dlist.leftRotation(1);
   cout << "leftRotation(1) output: " << dlist << endl << endl;
   dlist.leftRotation(4);
   cout << "Input list:" << dlist << endl;
   dlist.leftRotation(2);
   cout << "leftRotation(2) output: " << dlist << endl;

   DynamicList dlist1;
   dlist1.insert(5, 0);
   dlist1.insert(4, 0);
   dlist1.insert(3, 0);
   dlist1.insert(2, 0);
   dlist1.insert(1, 0);

   DynamicList dlist2;
   dlist2.insert(1, 0);
   dlist2.insert(2, 0);
   dlist2.insert(3, 0);
   dlist2.insert(4, 0);
   dlist2.insert(5, 0);

   DynamicList dlist3 = dlist1 + dlist2;
   cout << dlist3 << endl;
//    dlist3.removeDuplicates();
//    cout << dlist3 << endl;
//    dlist3.removeDuplicates();
//    cout << dlist3 << endl;
   dlist3.removeDuplicatesV2();
   cout << dlist3 << endl;
}

/*
dlist1 = {1, 2, 3, 4, 5}
dlist2 = {5, 4, 3, 2, 1}

dlist3 = dlist1 + dlist2; // List becomes: {1, 2, 3, 4, 5, 5, 4, 3, 2, 1}
cout << dlist3 << endl; // Output: 1 2 3 4 5 5 4 3 2 1

dlist3.removeDuplicates(); // Removes consecutive duplicates. No changes, as there are no consecutive duplicates.
cout << dlist3 << endl; // Output: 1 2 3 4 5 5 4 3 2 1

dlist3.removeDuplicatesV2(); // Removes all duplicates: {1, 2, 3, 4, 5}
cout << dlist3 << endl; // Output: 1 2 3 4 5

*/