#include <iostream>
#include <algorithm>
#include <array>

using namespace std;
/*
template <typename T>
bool search_number(const std::vector<T>& vec, T num)
{
    return find(vec.begin(),vec.end(),num) != vec.end();
}*/

int main()
{
    /*float num;
    cout << "Enter the number : ";
    cin >> num;

    cout <<search_number({1,2,3,4,5.5f,9},num) << endl;*/

    array<int,5>arr{1,2,3,4,5};
    for_each(arr.begin(),arr.end(),[](int i){cout<<i<<" ";});

    int num;
    cout << "Enter the number : ";
    cin >> num;

    auto it = find(arr.begin(),arr.end(),num);
    if(it!=arr.end())
    {
        int index = distance(arr.begin(),it);
        cout << "The number you chose is at index: " << index << endl;
    }
    else
    {
        cout << "Number is not found" << endl;
    }

    return 0;
}
