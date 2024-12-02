#include <bits/stdc++.h>
#include <string>



void print(auto& container){
    for (auto i : container)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::string s = "hello";

    std::string s2(s);
    //std::string s3(std::move(s));
    //std::cout << s3 << std::endl;
    std::cout << s << std::endl;

    //std::string s2 = s ;
    std::cout << s2 << std::endl;
    //std::string s2 = std::move(s);
    std::cout << s2 << std::endl;

    auto it = s.begin();
    std::cout << *it << std::endl;

    auto it1 = s.begin().base();  //is equal auto it = s.data();
    std::cout << it1 << std::endl;
    auto it2 = s.end();
    std::cout << *(it2-1) << std::endl;

    std::cout << s.back() << std::endl;
    std::cout << s.size() << std::endl;
    std::cout << s.empty() << std::endl;
    std::cout << s.capacity() << std::endl;
    s.insert(5,"world");
    std::cout<< s << std::endl;
    s.erase(6,1);
    std::cout<< s << std::endl;
    s.clear();
    std::cout << s << std::endl;
    s.append("hi ismail");
    std::cout << s << std::endl;
    s.replace(3,6,"jomana");
    std::cout << s << std::endl;
    s.resize(3);
    std::cout << s << std::endl;
    s.append("ahmed");
    std::cout << s << std::endl;
    s.resize(9,'?');
    std::cout << s << std::endl;
    s.assign("hi mohamed");
    std::cout << s << std::endl;
    char ch = s.at(3);
    std::cout <<ch << std::endl;
    int index = s.find('b');
    std::cout << index << std::endl;
    auto sub_str = s.substr(3,6);
    std::cout << sub_str << std::endl;
    s.insert(0,1,'b');
    std::cout << s << std::endl;
    s.insert(2,"E");
    std::cout << s << std::endl;

}

