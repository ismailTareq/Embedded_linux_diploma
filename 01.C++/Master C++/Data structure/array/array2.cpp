#include<iostream>

using namespace std;

int* filter_no(int arr[], int len, int& evenno_count)
{
    static int even_arr[10];
    for(int i = 0; i < len; i++)
    {
        if(arr[i] % 2 == 0)
        {
            even_arr[evenno_count++] = arr[i];

        }
    }
    return even_arr;
}

int main()
{
    int* even_no;
    int num[] = {1,2,4,5,7,9,11,12,13,14};
    int len = sizeof(num)/sizeof(num[0]);
    int evenno_count = 0;

    even_no = filter_no(num, len, evenno_count);
    cout << "Even numbers in the array: ";
    for (int i = 0 ; i < evenno_count ; i++)
    {
        cout << even_no[i] << " ";
    }
    return 0;
}