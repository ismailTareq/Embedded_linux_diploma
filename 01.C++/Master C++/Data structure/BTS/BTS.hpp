#define BST_H

#include <iostream>
#include <iomanip>
using namespace std;

template <typename DataType>
class BST {
public:
    BST();
    bool empty() const;
    bool search(const DataType& item) const;
    void insert(const DataType& item);
    void remove(const DataType& item);
    void inorder(ostream& out) const; 
    void graph(ostream& out) const; 

private:
    class BinNode {
    public:
        DataType data;
        BinNode* left;
        BinNode* right;
        BinNode() : left(0), right(0) {}
        BinNode(DataType item) : data(item), left(0), right(0) {}

    };
    typedef BinNode* BinNodePointer;
    BinNodePointer myRoot;
    void search2(const DataType& item, bool& found, BinNodePointer& locptr, BinNodePointer& parent) const;
    void inorderAux(ostream& out, BST<DataType>::BinNodePointer subtreePtr) const;
    void graphAux(ostream& out, int indent, BST<DataType>::BinNodePointer subtreeRoot) const;

};

