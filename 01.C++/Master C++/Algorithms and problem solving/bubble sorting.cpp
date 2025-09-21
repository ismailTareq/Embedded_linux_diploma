#include <iostream>

using namespace std;

void bubbleSort(int arr[], int len)
{
    for (int i = 0 ; i< len-1 ; i++)
    {
        int swapped = 0;
        for(int j = 0; j < len-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int main()
{
    int arr[] = {-9, 5, 2, -1, 0, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, len);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}