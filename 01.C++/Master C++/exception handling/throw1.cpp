#include <iostream>

int main()
{
    try
    {
        int x = 5;
        int y = 0;
        if (y == 0)
            throw std::runtime_error("Division by zero error");
        int z = x / y;
    }
    catch (std::runtime_error &e)
    {
       std::cerr << "error: " << e.what() << std::endl;
    }

    return 0;
}