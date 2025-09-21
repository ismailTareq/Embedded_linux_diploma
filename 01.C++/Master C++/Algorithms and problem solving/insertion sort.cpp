#include <iostream>

using namespace std;

void insertionSort(int array[],int size)
{
    for(int i = 1; i < size; i++)
    {
        int j = i-1;
        int x = array[i];
        while (j>=0 && array[j] > x)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = x;
    }
}


int main()
{
    int arr[] = {-9, 5, 2, -1, 0, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, len);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}