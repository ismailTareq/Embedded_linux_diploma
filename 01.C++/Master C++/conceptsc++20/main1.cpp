#include <iostream>
#include <type_traits>
#include <vector>

// template<typename T>
// concept myshit = std::is_integral_v<T>;

// template<typename T>
// concept multi = requires(T a, T b) {
//     a * b;
// };

// template<typename T>
// requires multi<T>
// void print(T n)
// {
//     std::cout << n << std::endl;
// }
template<typename T>
concept type = requires(T a) {
    sizeof(T) <= 4;
    requires sizeof(T) <= 4;
};
template<typename T>
requires type<T>
void print(T n)
{
    std::cout << n << std::endl;
}


int main()
{
    print(5ll);
    //print(5.5); // error
    return 0;
}