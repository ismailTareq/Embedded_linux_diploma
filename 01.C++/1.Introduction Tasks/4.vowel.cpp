#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    char ch;
    cout << "Enter a letter:\n";
    cin >> ch;

    ch = tolower(ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        cout << ch << " is a vowel.\n";
    } else {
        cout << ch << " is not a vowel.\n";
    }
    return 0;
}
