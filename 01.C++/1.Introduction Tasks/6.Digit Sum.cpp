#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int num,sum{0};
    cout << "Enter an integer:\n";
    cin >> num;
    while(num>0)
    {
        sum += num%10;
        num /= 10;
    }
    cout << "The sum of the digits is: " << sum << endl;
    return 0;
}
