#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;



int main()
{
    vector<int> numbers = {5, 3, 8, 1, 9, 2, 7};

    sort(numbers.begin(), numbers.end(), [](int a, int b){return a < b;});

    cout << "Sorted in ascending order: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }

    cout << endl;

    sort(numbers.begin(), numbers.end(), [](int a, int b){return a > b;});

    cout << "Sorted in descending order: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }

    cout << endl;
    return 0;
}
