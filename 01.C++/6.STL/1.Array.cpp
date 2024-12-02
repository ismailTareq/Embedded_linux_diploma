#include <bits/stdc++.h>
#include <array>


int main()
{
    std::array<int,5>arr1 = {1,2,3,4,5};
    std::array<int,5>arr2 = {10,20,30,40,50};

    arr1 = arr2;

    //bool status = (arr1 == arr2);

    //std::cout << std::boolalpha << status << std::endl;
    std::cout << *(arr1.begin()) << std::endl;
    std::cout << *(arr1.rbegin()) << std::endl;
    std::cout << *(arr1.end()-1) << std::endl;
    std::cout << *(arr1.rend()-1) << std::endl;

    std::cout << arr1.front() << std::endl;
    std::cout << arr1.back() << std::endl;

    for(int i = 0; i <arr1.size();i++)
        std::cout << arr1.at(i) << std::endl;

    for(int i = 0; i <arr1.size();i++)
        std::cout << arr1[i] << std::endl;

    std::cout << arr1.data() <<"   " << &arr1 << std::endl;

    auto it = arr1.begin();
    std::cout << *it << std::endl;

    arr1.fill(3);

    for(auto &it :arr1)
        std::cout << it << " " ;
}
