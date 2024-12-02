#include <bits/stdc++.h>
#include <vector>

template <typename T>
void print(std::vector<T> v){

    for(const auto &elem : v)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int>v {1,2,3,4,5};
    print(v);
    std::vector<int>v2 (std::move(v));
    print(v);
    print(v2);
    std::vector<int>v3;
    v3 = v2;
    print(v3);
    v.assign(4,10);
    v.push_back(15);
    v.emplace_back(11);
    print(v);

    auto it = v.at(5);
    std::cout << it << std::endl;

    std::cout << std::boolalpha << v.empty()<< std::endl;

    v.resize(3);
    print(v);
    v.resize(7,5);
    print(v);

    v.reserve(8);
    print(v);
    std::cout << v.capacity() << std::endl;

    std::cout<<*(v.data()+5)<<std::endl;
    std::cout<<*(v.begin()+5)<<std::endl;

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();

    print(v);

    v.emplace(v.end(),7);

    print(v);

    v.emplace(v.begin(),7);

    print(v);
}
