#include "BST_header.hpp"

template <typename DataType>
inline BST<DataType>::BST() : myRoot(0) {}

template <typename DataType>
inline bool BST<DataType>::empty() const { return myRoot == 0; }

template <typename DataType>
bool BST<DataType>::search(const DataType& item) const {
    BST<DataType>::BinNodePointer ptr = myRoot;
    bool found = false;
    while (!found && ptr != 0) 
    {
        if(item < ptr->data) ptr=ptr->left;
        else if(item > ptr->data) ptr=ptr->right;
        else found = true;
    }
    return found;
}

template <typename DataType>
inline void BST<DataType>::insert(const DataType& item) {

    BST<DataType>::BinNodePointer locptr = myRoot, parent = 0;
    bool found = false;
    while (!found && locptr != 0) {
        // point at current location in BST
        parent = locptr;
        // descend left
        if (item < locptr->data) locptr = locptr->left;
        // descend right
        else if (locptr->data < item) locptr = locptr->right;
        // item found
        else found = true;
    }
    if (!found) {
        // construct node containing item
        locptr = new BST<DataType>::BinNode(item);
        // empty tree
        if (parent == 0) myRoot = locptr;
        // insert to left of parent
        else if (item < parent->data) parent->left = locptr;
        // insert to right of parent
        else parent->right = locptr;
    }
    else cout << "Item already in the tree\n";

}

template <typename DataType>
void BST<DataType>::remove(const DataType& item) {

    bool found;
    BST<DataType>::BinNodePointer x, parent; // "x" points to node to be deleted
    search2(item, found, x, parent);

    if (!found) {
        cout << "Item not in the BST\n";
        return;
    }

    if (x->left != 0 && x->right != 0) { // node has 2 children

        // Find x's successor and its parent
        // The successor will be the leftmost child in the right subtree
        BST<DataType>::BinNodePointer xSucc = x->right;
        parent = x;
        while (xSucc->left != 0) { // descend left
            parent = xSucc;
            xSucc = xSucc->left;
        }

        // Move contents of xSucc to x and change x
        // to point to successor, which will be removed.
        x->data = xSucc->data;
        x = xSucc;
    }

    // Now proceed with case where node has 0 or 1 child
    // Create pointer to whichever subtree of x exists
    BST<DataType>::BinNodePointer subtree = x->left;
    if (subtree == 0) subtree = x->right;

    // if there is no parent, then it is the root being removed
    if (parent == 0) myRoot = subtree;
    // if the node to be removed is the parent's left child, skip over to the subtree
    else if (parent->left == x) parent->left = subtree;
    // if the node to be removed is the parent's right child, skip over to the subtree
    else parent->right = subtree;
    delete x;
}

template <typename DataType>
void BST<DataType>::search2(
    const DataType& item,
    bool& found,
    BST<DataType>::BinNodePointer& locptr,
    BST<DataType>::BinNodePointer& parent
) const {
    locptr = myRoot;
    parent = 0;
    found = false;
    while (!found && locptr != 0)
    {
        if (item < locptr->data)       
        {
            parent = locptr;
            locptr = locptr->left;
        }
        else if (locptr->data < item)  
        {
            parent = locptr;
            locptr = locptr->right;
        }
        else                           
            found = true;
    }
}

template <typename DataType>
inline void BST<DataType>::inorder(ostream& out) const {
    inorderAux(out, myRoot);
    out << endl;
}

template <typename DataType>
inline void BST<DataType>::graph(ostream& out) const {
    graphAux(out, 0, myRoot);
}

template <typename DataType>
void BST<DataType>::inorderAux(ostream& out,
    BST<DataType>::BinNodePointer subtreeRoot) const {
    if (subtreeRoot != 0) {
        inorderAux(out, subtreeRoot->left);    // L operation
        out << subtreeRoot->data << "  ";      // V operation
        inorderAux(out, subtreeRoot->right);   // R operation
    }
}

template <typename DataType>
void BST<DataType>::graphAux(ostream& out, int indent,
    BST<DataType>::BinNodePointer subtreeRoot) const {
    if (subtreeRoot != 0) {
        graphAux(out, indent + 8, subtreeRoot->right);
        out << setw(indent) << " " << subtreeRoot->data << endl;
        graphAux(out, indent + 8, subtreeRoot->left);
    }
}

// #endif 

