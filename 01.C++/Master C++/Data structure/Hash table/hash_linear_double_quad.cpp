#include "hash_linear_double_quad.hpp"

using namespace std;

HashTable::HashTable() {
    numberOfElements = 0;
    for (int i = 0; i < TableSize; i++) {
        table[i].index = -1;
        table[i].key = "";
        table[i].value = "";
    }
}

int HashTable::hash(string key) {
    int sum = 0;
    for (int i = 0; i < key.length(); i++)
        sum += key[i];
    return sum % TableSize;
}

void HashTable::insertLinear(string studentKey, string studentName) 
{
    int index = hash(studentKey);
    HashTable::Node newnode(index,studentKey,studentName);
    int loc;
    for (int i = 0; i < TableSize; i++)
    {
        loc = (index + i) % TableSize;
        if(table[loc].key == studentKey)
        {
            cout << "Student with key: " << studentKey << " already exists." << endl;
            return;
        }
        else if ((table[loc].index == -1) || (table[loc].index == -2))
        {
            table[loc] = newnode;
            newnode.index = loc;
            numberOfElements++;
            return;
        }
    }
}

void HashTable::removeLinear(string studentKey) 
{
    int index = hash(studentKey);
    int loc;
    for (int i = 0; i < TableSize; i++)
    {
        loc = (index + i) % TableSize;
        if(table[loc].index == -1)
        {
            cout << "Student with key: " << studentKey << " does NOT exist." << endl;
            return;
        }
        else if(table[loc].key == studentKey)
        {
            table[loc].index = -2;
            table[loc].key = "";
            table[loc].value = "";
            numberOfElements--;
            return;
        }
    }
}

int HashTable::searchLinear(string studentKey) 
{
    int index = hash(studentKey);
    int loc;
    for (int i = 0; i < TableSize; i++)
    {
        loc = (index + i) % TableSize;
        if(table[loc].index == -1)
        {
            cout << "Student with key: " << studentKey << " does NOT exist." << endl;
            return -1;
        }

        if(table[loc].key == studentKey)
        {
            cout << "Student with key: " << studentKey << " exists." << endl;
            cout << setw(2) << loc << ": " << table[loc];
            return loc;
        }
    }
    return -1;
}

int HashTable::getQuadLoc(int index, int& base) {
    int loc;
    if (base > 0) {
        loc = (index + (base * base)) % TableSize;
        base *= -1;
    }
    else {
        base *= -1;
        loc = (index - (base * base)) % TableSize;
        base++;
        if (loc < 0)
            loc = TableSize + loc;
    }
    return loc;
}

void HashTable::insertQuadratic(string studentKey, string studentName) {
    int index = hash(studentKey);
    Node newnode(index, studentKey, studentName);
    int loc, base = 0;
    while (true) {
        loc = getQuadLoc(index, base);
        if (abs(base) > ceil(sqrt(TableSize))) {
            cout << "Hash Table is full, can't insert node with key " << studentKey << "." << endl;
            return;
        }
        if (table[loc].key == studentKey) {
            cout << "Student with key: " << studentKey << " already exists." << endl;
            return;
        }
        if (table[loc].index == -1 || table[loc].index == -2) {
            table[loc] = newnode;
            numberOfElements++;
            return;
        }
    }
}

void HashTable::removeQuadratic(string studentKey) {
    int index = hash(studentKey);
    int loc, base = 0;
    while (true) {
        loc = getQuadLoc(index, base);
        if (table[loc].index == -1 || abs(base) > ceil(sqrt(TableSize))) {
            cout << "Student with key: " << studentKey << " does NOT exist." << endl;
            return;
        }
        if (table[loc].key == studentKey) {
            table[loc].index = -2;
            table[loc].key = "";
            table[loc].value = "";
            numberOfElements--;
            return;
        }
    }
}

int HashTable::searchQuadratic(string studentKey) {
    int index = hash(studentKey);
    int loc, base = 0;
    while (true) {
        loc = getQuadLoc(index, base);
        if (table[loc].index == -1 || abs(base) > ceil(sqrt(TableSize))) {
            cout << "Student with key: " << studentKey << " does NOT exist." << endl;
            return -1;
        }
        if (table[loc].key == studentKey) {
            cout << "Student with key: " << studentKey << " exists." << endl;
            cout << setw(2) << loc << ": " << table[loc];
            return loc;
        }
    }
    return -1;
}

int HashTable::hash2(string key, int count) {
    int sum = 0, h1, h2;
    for (int i = 0; i < key.length(); i++) 
        sum += key[i];
    h1 = sum % TableSize;
    h2 = Hash2Constant - (sum % Hash2Constant);
    return ((h1 + (count * h2)) % TableSize);
}

void HashTable::insertDouble(string studentKey, string studentName) {
    int index = hash(studentKey);
    int loc;
    Node newnode(index, studentKey, studentName);
    for (int i = 0; i < TableSize; i++) {
        loc = hash2(studentKey, i);
        if (table[loc].key == studentKey) {
            cout << "Student with key: " << studentKey << " already exists." << endl;
            return;
        }
        if (table[loc].index == -1 || table[loc].index == -2) {
            table[loc] = newnode;
            numberOfElements++;
            return;
        }
    }
    cout << "Hash Table is full, can't insert node with key " << studentKey << "." << endl;
    return;
}

void HashTable::removeDouble(string studentKey) {
    int index = hash(studentKey);
    int loc;
    for (int i = 0; i < TableSize; i++) {
        loc = hash2(studentKey, i);
        if (table[loc].index == -1) {
            cout << "Student with key: " << studentKey << " does NOT exist." << endl;
            return;
        }
        if (table[loc].key == studentKey) {
            table[loc].index = -2;
            table[loc].key = "";
            table[loc].value = "";
            numberOfElements--;
            return;
        }
    }
}

int HashTable::searchDouble(string studentKey) {
    int index = hash(studentKey);
    int loc;
    for (int i = 0; i < TableSize; i++) {
        loc = hash2(studentKey, i);
        if (table[loc].index == -1) {
            cout << "Student with key: " << studentKey << " does NOT exist." << endl;
            return -1;
        }
        if (table[loc].key == studentKey) {
            cout << "Student with key: " << studentKey << " exists." << endl;
            cout << setw(2) << loc << ": " << table[loc];
            return loc;
        }
    }
    return -1;
}

void HashTable::print(ostream& out) {
    for (int i = 0; i < TableSize; i++) {
        out << setw(2) << i << ": " << table[i];
    }
}

ostream& operator<<(ostream& out, HashTable hashTable) {
    hashTable.print(out);
    return out;
}

ostream& operator<<(ostream& out, HashTable::Node node) {
    out << "{" << node.index << ", " << node.key << ", " << node.value << "}";
    return out;
}
