#include <iostream>

using namespace std;

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {9, 7, 5, 11, 12, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}