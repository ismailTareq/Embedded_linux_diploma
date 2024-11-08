#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int num1=0,num2=0,num3=0;
    cout << "Enter 3 numbers using space: ";
    cin >> num1 >> num2 >> num3;
    cout << "max number is: "<< max({num1,num2,num3});
    return 0;
}
