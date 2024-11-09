#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int odd[10];
int even[10];

int even_odd(int arr[])
{
    int e=0,o=0;
    for(int i = 0;i < 10;i++)
    {
        if(arr[i]%2 == 0)
        {
            even[e] = arr[i];
            e++;
        }
        else
        {
            odd[o] = arr[i];
            o++;
        }
    }
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};

    even_odd(arr);

    for(int i=0;i<10;i++)
    {
        if(odd[i]!=0)
        cout<<odd[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<10;i++)
    {
        if(even[i]!=0)
        cout<<even[i]<<" ";

    }

    return 0;
}
