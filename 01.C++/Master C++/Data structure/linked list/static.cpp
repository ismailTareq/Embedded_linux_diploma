#include "static_link.hpp"
#include <iostream>
using namespace std;

int main() {

   StaticList staticlist;
   staticlist.insert(3, 0);
   staticlist.insert(2, 0);
   staticlist.insert(1, 0);
   cout << staticlist << endl;
   staticlist.insert(42, 2);
   cout << staticlist << endl;
   staticlist.erase(0);
   cout << staticlist << endl;
   staticlist.deleteByValue(42);
   cout << staticlist << endl;
   cout << (staticlist.empty() ? "Empty" : "Not Empty") << endl;
   staticlist.erase(0);
   cout << (staticlist.empty() ? "Empty" : "Not Empty") << endl;
   staticlist.erase(0);
   cout << (staticlist.empty() ? "Empty" : "Not Empty") << endl;
   staticlist.erase(0);
   cout << (staticlist.empty() ? "Empty" : "Not Empty") << endl;
   staticlist.erase(0);
   staticlist.insert(5, 0);
   staticlist.insert(4, 0);
   staticlist.insert(3, 0);
   staticlist.insert(2, 0);
   staticlist.insert(1, 0);
   cout << "Input list: " << staticlist << endl;
   staticlist.leftRotation(1);
   cout << "leftRotation(1) output: " << staticlist << endl << endl;
   staticlist.leftRotation(4);
   cout << "Input list:" << staticlist << endl;
   staticlist.leftRotation(2);
   cout << "leftRotation(2) output: " << staticlist << endl;
}