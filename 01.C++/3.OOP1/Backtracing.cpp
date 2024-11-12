#include "Backtracing.hpp"

backtrace::backtrace(std::string func)
{
    vec.push_back(func);
}

backtrace::~backtrace()
{
    vec.pop_back();
}

std::vector<std::string> backtrace::vec;

void func1();
void func2();
void func3();

void func1()
{
    ENTER
    func2();
    EXIT
}
void func2()
{
    ENTER
    func3();
    EXIT
}
void func3()
{
    ENTER
    BACKTRACING
    EXIT
}


int main()
{
    ENTER
    func1();
    EXIT
}
