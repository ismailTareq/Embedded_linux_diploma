#include <iostream>

int& func()
{
    static int x = 5;
    std::cout<< x <<std::endl;
    return x;
}

int main()
{
    func() = 10;
    func();
    return 0;
}
