#ifndef __checker_hpp__
#define __checker_hpp__
#include <iostream>

template <typename T ,size_t threshold>
class Checker {
public:
    Checker<T,threshold>(T x, T y);
    ~Checker<T,threshold>() = default;
    bool compare();
private:
    T m_x;
    T m_y;
};
template <typename T ,size_t threshold>
Checker<T,threshold>::Checker(T x, T y):m_x(x), m_y(y)
{
}
template <typename T ,size_t threshold>
bool Checker<T,threshold>::compare()
{
    bool res = (((m_x + m_y) > threshold) ? 1 : 0);
    return res;
}
#endif // !__checker_hpp__
