#include <iostream>
#include <vector>
#include <string>

class backtrace
{
private:
public:
    static std::vector<std::string> vec;
    backtrace(std::string func);
    ~backtrace();
};


#define ENTER           std::cout << "Enter to  [" << __FUNCTION__ << ']'  << std::endl;backtrace bc(__FUNCTION__);
#define EXIT            std::cout <<  "Exit from [" << __FUNCTION__ << ']' << std::endl;
#define BACKTRACING     std::cout << "Backtrace as follow : "<<std::endl;for(std::string i: backtrace::vec)std::cout<<i<<std::endl;
