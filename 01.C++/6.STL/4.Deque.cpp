#include <bits/stdc++.h>
#include <deque>



void print(auto& container){
    for (auto i : container)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::deque<int>q {1,2,3,4,5};
    std::deque<int>q2 ;
    q2.assign({6,4,8,9});

    for (int i = 0; i < q.size(); i++)
    {
        std::cout<<q[i]<<' '<<q.at(i)<<std::endl;
    }

    std::cout<<q.front()<<' '<<q.back()<<std::endl;

    q.insert(q.end(),6);
    q.insert(q.end(),10);
    q.emplace(q.end(),100);
    print(q);
    q.insert(q.begin(),6);
    q.insert(q.begin(),10);
    q.emplace(q.begin(),100);
    print(q);

    q.push_back(200);
    q.emplace_back(300);
    q.push_front(200);
    q.push_front(300);
    print(q);

    q.swap(q2);
    print(q);

    q.clear();
    print(q);
    print(q2);

}

