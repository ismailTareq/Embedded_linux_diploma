#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "ASCII Table:\n";

    cout << "----------------" <<endl;
    cout << "|" << setw(5) << "Char" << setw(2) << "|" << setw(6) << "ASCII" << setw(2) << "|" <<endl;
    cout << "----------------" <<endl;

    for(int i {33};i<127;i++)
            cout << "|" << setw(5) << (char)i << setw(2) << "|" << setw(6) << i << setw(2) << "|" <<endl;
    cout << "----------------" <<endl;
    return 0;
}
