#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

class Check
{
public:
    int digit(char c)
    {
        return std::isdigit(c);
    }

    int ArrIsEven(int arr[],int size)
    {
        for(int i = 0; i < size ; i++)
        {
            if(arr[i]%2==1)
            {
                return 0;
            }
        }
        return 1;
    }
};

int main()
{
    Check check;
    char c = 'a';
    std::cout<<"is "<< c << " a digit? "<< (check.digit(c) ? "yes":"no")<<std::endl;
    int arr[]={2,2,4,4};
    std::cout<<"all elements even? "<<(check.ArrIsEven(arr,4) ? "yes":"no")<<std::endl;

    return 0;
}
