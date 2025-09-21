#include<iostream>

using namespace std;

int* extractarray(int arr[],int len,int& sub_len)
{
    static int sub_arr[]{arr[0],arr[1],arr[2]};
    sub_len = sizeof(sub_arr)/sizeof(sub_arr[0]);
    return sub_arr;
}

int main()
{   
    int* sub_arr;
    int sub_len;
    int arr[] = {2,10,5,7,4,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << "Original array: ";
    for(int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sub_arr = extractarray(arr,len,sub_len);
    cout << "Extracted sub-array: ";
    for(int i = 0; i < sub_len; i++)
    {
        cout << sub_arr[i] << " ";
        //cout << *(sub_arr + i) << " ";)
    }
    cout << endl;

    return 0;
}