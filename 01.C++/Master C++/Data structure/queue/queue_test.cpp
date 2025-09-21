#include "Queue_header.hpp"

#include <iostream>
using namespace std;

int main() {

   Queue q1;
   for (int i = 0; i < 10; i++) q1.enqueue(i);
   cout << "Initially: " << q1 << "Front: " << q1.front() << endl;
   // Initially: 0 1 2 3 4 5 6 7 8 9 Front: 0
   q1.dequeue();
   cout << "After dequeue: " << q1 << "Front: " << q1.front() << endl;
   // After dequeue: 1 2 3 4 5 6 7 8 9 Front: 1

   Queue q2 = q1;
   Queue q3(q1);
   Queue q4(2);
   q4 = q1;
   cout << "q2: " << q2;
   cout << "q3: " << q3;
   cout << "q4: " << q4;
   /*
   q2: 1 2 3 4 5 6 7 8 9
   q3: 1 2 3 4 5 6 7 8 9
   q4: 1 2 3 4 5 6 7 8 9
   */

   while (!q1.empty()) q1.dequeue();
   q1.dequeue(); // Shouldn't crash
   q2.dequeue();
   q3.dequeue();
   q3.dequeue();
   q4.dequeue();
   q4.dequeue();
   q4.dequeue();
   cout << "q1: " << q1 << "Front: " << q1.front() << endl; // Shouldn't crash
   cout << "q2: " << q2 << "Front: " << q2.front() << endl;
   cout << "q3: " << q3 << "Front: " << q3.front() << endl;
   cout << "q4: " << q4 << "Front: " << q4.front() << endl;

   /*
   q1:  Front: garbage
   q2:  Front: garbage
   q3:  Front: garbage
   q4:  Front: garbage
   line indicates that the program is designed to handle the case when the queue is empty.
   */
   return 0;

}
