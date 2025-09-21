#include <iostream>

using namespace std;

void swap(int*a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int minIndex = i; // for the line
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

int main()
{
    int arr[] = {-9, 5, 2, -1, 0, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, len);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}