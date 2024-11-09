#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*template<typename T>
T max_num(const vector<T>&vec)
{
    if(!vec.empty())
        return *max_element(vec.begin(),vec.end());
    else
        return 0;
}*/

int max_num(int arr[],int length)
{
    sort(arr,arr+length);
    return arr[length-1];
}

int main()
{
    //cout << "max = " << max<float>({1.1,-5.8,8.2,9.5}) << endl;
    //cout << "max = " << max<int>({1,-5,14,8,9}) << endl;
    int arr[]={2,5,6,37,85,22};

    int n=sizeof(arr)/sizeof(arr[0]);

    int result=max_num(arr, n);

    cout<<result<<endl;
    return 0;
}
