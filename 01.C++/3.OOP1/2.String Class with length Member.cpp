#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <cstring>

class String
{
private:
    char *str;
public:
    String()
    :str(nullptr)
    {

    }
    ~String()
    {
        delete[] str;
    }
    String(const char *s)
    {
        str = new char[strlen(s) + 1];
        std::strcpy(str,s);
    }
    int length() const
    {
        return strlen(str);
    }
    void display() const
    {
        std::cout << "String: " << str << "\nLength: " << length() << std::endl;
    }
};

int main()
{
    String mystring("hi this is ismail");
    mystring.display();
    return 0;
}
