#include <iostream>
#include "checker.hpp"

using namespace std;

int main()
{
    Checker<int, 10> checker(5, 7);
    if (checker.compare()) {
        cout << "The sum is greater than the threshold." << endl;
    } else {
        cout << "The sum is not greater than the threshold." << endl;
    }
    return 0;
}
