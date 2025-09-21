#include<iostream>

using namespace std;

int* filter_no(int arr[], int len, int& evenno_count)
{
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        if(arr[i] % 2 == 0)
        {
            count++;
        }
    }
    evenno_count = count;

    int* even_arr = new int[count];
    count = 0;
    for(int i = 0; i < len; i++)
    {
        if(arr[i] % 2 == 0)
        {
            even_arr[count++] = arr[i];
        }
    }
    return even_arr;
}

int main()
{
    int* evenno1, *evenno2;
    int number1[] = {1, 2, 4, 5,7,9,11,13,10};
    int number2[] = {1,3,5,6,8,9,12,13,14};
    int len1 = sizeof(number1)/sizeof(number1[0]);
    int len2 = sizeof(number2)/sizeof(number2[0]);
    int evenno_count1 = 0, evenno_count2 = 0;
    evenno1 = filter_no(number1, len1, evenno_count1);
    evenno2 = filter_no(number2, len2, evenno_count2);

    for (int i = 0 ; i < evenno_count1 ; i++)
    {
        cout << evenno1[i] << " ";
    }
    cout << endl;

    for (int i = 0 ; i < evenno_count2 ; i++)
    {
        cout << evenno2[i] << " ";
    }
    cout << endl;

    return 0;
}