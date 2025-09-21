#include <iostream>
#include <type_traits>

void maythrow()
{
    throw std::runtime_error("Error occurred");
}
void nothrow() noexcept
{
    // does not throw
}

template<typename T>
void process(T func) noexcept(noexcept(func()))
{
    func();
}

int main()
{
    try
    {
        process(maythrow);
        process(nothrow);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
