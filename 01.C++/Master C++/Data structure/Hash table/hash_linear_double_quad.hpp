#ifndef HTableProbingHPP
#define HTableProbingHPP

#include <math.h>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

const int TableSize = 11;
const int Hash2Constant = 7;

class HashTable {
private:
    class Node {
    public:
        int index;
        string key;
        string value;
        Node(int K = -1, string k = "", string val = "") : index(K), key(k), value(val) {}
        void print(ostream& out) {
            cout << "   Index: " << setw(2) << index
                << "    Key: " << setw(3) << key
                << "    Name: " << setw(10) << value
                << endl;
        }
    };

    int numberOfElements;
    Node table[TableSize];
    int hash(string key);
    int hash2(string key, int count);
    int getQuadLoc(int index, int& base);
    friend ostream& operator<<(ostream&, Node);

public:
    HashTable();

    void insertLinear(string studentKey, string studentName);
    void removeLinear(string studentKey);
    int searchLinear(string studentKey);

    void insertQuadratic(string studentKey, string studentName);
    void removeQuadratic(string studentKey);
    int searchQuadratic(string studentKey);

    void insertDouble(string studentKey, string studentName);
    void removeDouble(string studentKey);
    int searchDouble(string studentKey);

    void print(ostream& out);
};

ostream& operator<<(ostream& out, HashTable hashTable);
ostream& operator<<(ostream& out, HashTable::Node node);

#endif /* HTableProbingHPP */
