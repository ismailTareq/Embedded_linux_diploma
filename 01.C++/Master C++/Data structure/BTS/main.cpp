/*
#include "BST_header.hpp"
#include <iostream>
using namespace std;

// Fancy more exercise? Read below...
template <typename T>
void floorAndCeil(T*& floor, T*& ceil);

int main() {

    boolalpha(cout); // Makes true/false output get cout'd as true/false rather than 1/0

    BST<int> int_bst;

    cout << "Empty?: " << int_bst.empty() << endl;

    int arr[] = { 20, 16, 11, 7, 3, 13, 15, 18, 17, 19, 28, 23, 22, 24, 31, 30, 37 };
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
        cout << "Inserting: " << arr[i] << endl;
        int_bst.insert(arr[i]);
    }

    cout << "Empty?: " << int_bst.empty() << endl;

    int_bst.insert(100);
    int_bst.insert(100); // How will you handle duplicates?
    int_bst.inorder(cout);

#ifdef TA
    int_bst.remove(100);
    int_bst.remove(100); // How will you handle double-remove?
    cout << "\n-----------------------------------\n\n";
    int_bst.graph(cout);
    cout << "\n-----------------------------------\n\n";
    int_bst.remove(7);
    int_bst.graph(cout);
    cout << "\n-----------------------------------\n\n";
    int_bst.remove(13);
    int_bst.graph(cout);
    cout << "\n-----------------------------------\n\n";
    int_bst.remove(37);
    int_bst.graph(cout);
    cout << "\n-----------------------------------\n\n";
    int_bst.remove(16);
    int_bst.graph(cout);
    cout << "\n-----------------------------------\n\n";
#endif
    return 0;

}

// Given a BST, find the floor and ceil of a given key in it.
// If the given key lies in the BST, then both floor and ceil are equal to that key;
// otherwise, the "ceil" is equal to the next greater key (if any) in the BST,
// and the "floor" is equal to the previous greater key (if any) in the BST.
// If either is not found, set input to a null pointer.
template <typename T>
void floorAndCeil(T*& floor, T*& ceil) {}
*/