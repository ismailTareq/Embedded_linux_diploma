#include <iostream>
#include <type_traits>
#include <vector>

template<typename T>
using Begin_itr = decltype(std::begin(std::declval<T&>()));

template<typename T>
using End_itr = decltype(std::end(std::declval<T&>()));

template<typename T>
using Inc_itr = decltype(++std::declval<Begin_itr<T&>>());

template<typename T>
using Deref_itr = decltype(*std::declval<Begin_itr<T&>>());

template<typename C, typename = void>
struct is_container : std::false_type {


};
template<typename C>
struct is_container<C, std::void_t<
    Begin_itr<C>,
    End_itr<C>,
    Inc_itr<C>,
    Deref_itr<C>
>> : std::integral_constant<bool, true> {

};

int main()
{
    std::cout << std::boolalpha;
    std::cout << is_container<std::vector<int>>::value << std::endl; // true
    std::cout << is_container<int[5]>::value << std::endl;           // true
    std::cout << is_container<int>::value << std::endl;              // false
    return 0;
}