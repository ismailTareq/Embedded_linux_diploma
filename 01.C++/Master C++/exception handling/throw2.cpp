#include <iostream>

void func()
{
    long *arr = (long*)malloc(5 * sizeof(long));
    if (arr == nullptr)
        throw std::runtime_error("Memory allocation failed");
    for (int i = 0;i < 5;i++)
        arr[i] = i;
    free(arr);
}

int main()
{
    try
    {
        func();
    }
    catch (std::runtime_error &e)
    {
        std::cerr << "error: " << e.what() << std::endl;
    }

    return 0;
}