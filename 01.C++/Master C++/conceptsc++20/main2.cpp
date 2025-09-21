#include <iostream>
#include <type_traits>
#include <vector>

template<typename T>
concept Has_begin = requires(T a)
{
    {std::begin(a)}->std::input_or_output_iterator;
};
template<typename T>
concept Has_end = requires(T a)
{
    {std::end(a)}->std::input_or_output_iterator;
};
template<typename T>
concept Inc = requires(T a)
{
    {std::begin(a)} -> std::same_as<decltype(std::begin(a))>;
};
template<typename T>
concept Deref = requires(T a)
{
    { *std::begin(a) }
};