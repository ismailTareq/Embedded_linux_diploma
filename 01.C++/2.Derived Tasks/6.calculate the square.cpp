#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;



int main()
{
    int number = 0;


    cout<<"Enter a number: ";
    cin >> number;

    auto square = [](int num){return num*num;};


    cout << square(number) << endl;
    return 0;
}
