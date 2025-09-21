#include "hash_linear_double_quad.hpp"

void testLinear(HashTable);
void testQuadratic(HashTable);
void testDoubleHashing(HashTable);

int main() {

    HashTable students1;
    testLinear(students1);

    HashTable students2;
    testQuadratic(students2);

    HashTable students3;
    testDoubleHashing(students3);

    return 0;

}

void testLinear(HashTable students) {
    std::cout << " ------- LINEAR PROBING -------- " << endl;
    students.insertLinear("9", "AAAAAA");     // 57 % 11 = 2
    students.insertLinear("86", "BBBBBB");    // 56 + 54 = 110, 110 % 11 = 0
    students.insertLinear("5", "CCCCCC");     // 53 % 11 = 9
    students.insertLinear("29", "DDDDDD");    // 50 + 57 = 107, 107 % 11 = 8
    students.insertLinear("2", "EEEEEE");     // 50 % 11 = 6
    students.insertLinear("65", "FFFFFF");    // 54 + 53 = 107, 107 % 11 = 8 (collision!)
    students.insertLinear("9", "GGGGGG");     // 57 % 11 = 2 (duplicate ID!)
    std::cout << "After Insertion:\n" << students << endl << endl;
    int id = students.searchLinear("65");
    cout << "Returned location:  " << id << endl << endl;
    students.removeLinear("29");
    students.removeLinear("5");
    students.removeLinear("86");
    std::cout << "After deletion of 29, 5, and 86:\n" << students << endl << endl;
    students.removeLinear("65");
    std::cout << "After deletion of 65:\n" << students << endl << endl;

}

void testQuadratic(HashTable students) {
    std::cout << " ------- QUADRATIC PROBING -------- " << endl;
    students.insertQuadratic("9", "AAAAAA");     // 57 % 11 = 2
    students.insertQuadratic("86", "BBBBBB");    // 56 + 54 = 110, 110 % 11 = 0
    students.insertQuadratic("5", "CCCCCC");     // 53 % 11 = 9
    students.insertQuadratic("29", "DDDDDD");    // 50 + 57 = 107, 107 % 11 = 8
    students.insertQuadratic("2", "EEEEEE");     // 50 % 11 = 6
    students.insertQuadratic("65", "FFFFFF");    // 54 + 53 = 107, 107 % 11 = 8 (collision!)
    students.insertQuadratic("9", "GGGGGG");     // 57 % 11 = 2 (duplicate ID!)
    students.insertQuadratic("41", "HHHHHH");    // 52 + 49 = 101, 101 % 11 = 2 (collision!)
    students.insertQuadratic("97", "IIIIII");    // 57 + 55 = 112, 112 % 11 = 2 (collision!)
    students.insertQuadratic("79", "JJJJJJ");    // 55 + 57 = 112, 112 % 11 = 2 (collision!)
    students.insertQuadratic("14", "KKKKKK");    // 49 + 52 = 101, 101 % 11 = 2 (collision!)
    std::cout << "After Insertion:\n" << students << endl << endl;
    int id = students.searchQuadratic("79");
    cout << "Returned location:  " << id << endl << endl;
    students.removeQuadratic("29");
    students.removeQuadratic("5");
    students.removeQuadratic("86");
    std::cout << "After deletion of 29, 5, and 86:\n" << students << endl << endl;
    students.removeQuadratic("79");
    std::cout << "After deletion of 79:\n" << students << endl << endl;
}

void testDoubleHashing(HashTable students) {
    std::cout << " ------- DOUBLE HASH PROBING -------- " << endl;
    students.insertDouble("9", "AAAAAA");     // 57 % 11 = 2
    students.insertDouble("86", "BBBBBB");    // 56 + 54 = 110, 110 % 11 = 0
    students.insertDouble("5", "CCCCCC");     // 53 % 11 = 9
    students.insertDouble("29", "DDDDDD");    // 50 + 57 = 107, 107 % 11 = 8
    students.insertDouble("2", "EEEEEE");     // 50 % 11 = 6
    students.insertDouble("65", "FFFFFF");    // 54 + 53 = 107, 107 % 11 = 8 (collision!);
    //                             (doublehash) h2 = 7 - (107 % 7) = 5
    // P.S. What if h2 is incompatible? e.g., i*h2+h1 goes into a cycle
    students.insertDouble("9", "GGGGGG");     // 57 % 11 = 2 (duplicate ID!)
    std::cout << "After Insertion:\n" << students << endl << endl;
    std::cout << "Search on ID 65:\n";
    int id = students.searchDouble("65");
    cout << "Returned location:  " << id << endl << endl;
    students.removeDouble("29");
    students.removeDouble("5");
    students.removeDouble("86");
    std::cout << "After deletion of 29, 5, and 86:\n" << students << endl << endl;
    students.removeDouble("65");
    std::cout << "After deletion of 65:\n" << students << endl << endl;
}
