#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    int start = 10,end = 10000;
    int size = end -start +1;
    std::vector<int>vec(size);
    std::iota(vec.begin(),vec.end(),start);

    for(int i:vec)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
