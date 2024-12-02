#include <bits/stdc++.h>
#include <set>
#include <unordered_set>

#define ORDERED

void print(auto& container){
    for (auto i : container)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

#ifdef ORDERED
int main()
{
    std::set<int>s{1,2,3,4,5};
    std::set<int>ss{10,20,30,40,50};
    print(s);

    std::cout << s.size() << ' ' << s.max_size() << std::endl;

    s.insert(13);
    s.insert(20);
    s.insert(8);
    print(s);

    s.erase(15);
    print(s);

    s.swap(ss);
    print(s);
    print(ss);

    ss.clear();

    s.emplace_hint(s.begin(),50);
    print(s);

    auto it = s.find(11);
    std::cout << std::boolalpha << *it << std::endl;

    std::cout << s.count(30) << ' ' << s.count(20) << std::endl;

    auto it1 = s.lower_bound(30);
    auto it2 = s.upper_bound(30);

    std::cout << *it1 << ' ' << *it2 << std::endl;
    print(s);

    auto it3 = s.lower_bound(41);
    auto it4 = s.upper_bound(44);

    std::cout << *it3 << ' ' << *it4 << std::endl;
    print(s);

    auto it5 = s.equal_range(10);
    it5.swap(it5);
    print(s);
}
#else


#endif
