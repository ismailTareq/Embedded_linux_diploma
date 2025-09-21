#include <iostream>
#include <vector>

class data{
public:
    data()
    {
        std::cout << "Data object created" << std::endl;
    }
    data(const data&)
    {
        std::cout << "Data object copied" << std::endl;
    }
    data(data&&) noexcept
    {
        std::cout << "Data object moved" << std::endl;
    }

    ~data()
    {
        std::cout << "Data object destroyed" << std::endl;
    }
};


int main()
{
    std::vector<data> vec;
    vec.reserve(2);
    vec.emplace_back();
    vec.emplace_back();
    vec.emplace_back();
    return 0;
}