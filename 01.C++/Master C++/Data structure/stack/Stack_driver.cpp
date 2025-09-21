//#include "Stack_header.hpp"
//
//#include <iostream>
//using namespace std;
//
//int main() {
//
//    Stack s1;
//    for (int i = 0; i < 10; i++) s1.push(i);
//    cout << "Initially: " << s1 << "Top: " << s1.top() << endl;
//    // Initially: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] Top: 9
//    s1.pop();
//    cout << "After pop: " << s1 << "Top: " << s1.top() << endl;
//    // After pop: [0, 1, 2, 3, 4, 5, 6, 7, 8] Top: 8
//
//    Stack s2 = s1;
//    Stack s3(s1);
//    Stack s4(2);
//    s4 = s1;
//    cout << "s2: " << s2;
//    cout << "s3: " << s3;
//    cout << "s4: " << s4;
//    /*
//    s2: [0, 1, 2, 3, 4, 5, 6, 7, 8]
//    s3: [0, 1, 2, 3, 4, 5, 6, 7, 8]
//    s4: [0, 1, 2, 3, 4, 5, 6, 7, 8]
//    */
//
//    while (!s1.empty()) s1.pop();
//    s1.pop(); // Shouldn't crash
//    s2.pop();
//    s3.pop();
//    s3.pop();
//    s4.pop();
//    s4.pop();
//    s4.pop();
//    cout << "s1: " << s1 << "Top: " << s1.top() << endl; // Shouldn't crash
//    cout << "s2: " << s2 << "Top: " << s2.top() << endl;
//    cout << "s3: " << s3 << "Top: " << s3.top() << endl;
//    cout << "s4: " << s4 << "Top: " << s4.top() << endl;
//    /*
//    s1: [] Top: garbage_value
//    s2: [] Top: garbage_value
//    s3: [] Top: garbage_value
//    s4: [] Top: garbage_value
//    line indicates that the program is designed to handle the case when the queue is empty.
//    */
//    return 0;
//
//}
