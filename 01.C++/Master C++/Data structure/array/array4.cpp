#include<iostream>

using namespace std;

void filter_no(int* arr, int len)
{
    int* temparr = new int[len];
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        if(arr[i] >= 0 ) temparr[count++] = arr[i];
    }
    for(int i = 0; i < len; i++)
    {
        if(arr[i] < 0 ) temparr[count++] = arr[i];
    }
    for(int i = 0; i < len; i++)
    {
        arr[i] = temparr[i];
    }
    delete[] temparr;
}


int main()
{
    int num[] = {1, -2, 4, -5, 7, -9, 11, 12, -13, 14};
    int len = sizeof(num) / sizeof(num[0]);
    filter_no(num, len);
    for(int i = 0; i < len; i++)
    {
        cout << num[i] << " ";
    }
    return 0;
}