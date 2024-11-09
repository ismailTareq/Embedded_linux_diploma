#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

/*void deleteNumber(std::vector<int>& arr, int number) {
    arr.erase(std::remove(arr.begin(), arr.end(), number), arr.end());
}*/


int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int New_arr[4];
    int number,j=0;

    cout<<"Enter the number that u want to delete: ";
    cin >> number;

    for(int i = 0; i < 5;i++)
    {
        if(arr[i] == number)
        {
            j--;
        }
        else
        {
            New_arr[j] = arr[i];
        }
        j++;
    }
    for(int k : New_arr)
    {
        cout << k;
    }

    return 0;
}
