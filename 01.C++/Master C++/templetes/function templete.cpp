#include <iostream>

using namespace std;

// template <typename T , typename U>
// auto add(T a, U b) -> decltype(a + b)
// {
//     return a + b;
// }

// template <typename Ret , typename T , typename U>
// Ret add(T a, U b)
// {
//     return a + b;
// }

// template <typename T>
// void print(T value)
// {
//     static_assert(std::is_integral_v<T>);
// }

template <typename ...Args>
void print(Args... args)
{
    //print(args...);
    (cout << ... << args) << endl;
}

int main()
{
    print(1,2,3,4,5,6); 
    // double a{5.4};
    // print(a);
    // int a{5};
    // double b{4.5};
    // cout << "Sum of integers: " << add<int>(a, b) << endl;
    // cout << "Sum of doubles: " << add<double>(b, a) << endl;
    // auto sum = [] <typename T, typename U>(T a, U b) {
    //     return (a + b);
    // };
    // cout << "Sum of integers: " << sum(5, 5.5) << endl;

}

