#include <bits/stdc++.h>

class String
{
private:
    char *str;
    unsigned int length;

public:
    String()
    :str(nullptr),length(0)
    {

    }

    String(const char *data)
    {
        std::cout << "constructor" << std::endl;
        length =  std::strlen(data);
        str = new char[length + 1];// the +1 is for the termination
         std::strcpy(str,data);
    }
    //copy
    String(const String &data)
    {
        std::cout << "copy constructor" << std::endl;
        length = data.length;
        str = new char[length + 1];// the +1 is for the termination
        std::strcpy(str,data.str);
    }

    //move
    String(String &&data)
    {
        std::cout << "move constructor" << std::endl;
        //this->str
        str = data.str;
        length = data.length;
        data.str = nullptr;
        data.length = 0;
    }

    //copy assignment
    String& operator=(const String &data)
    {
        std::cout << "copy constructor ass" << std::endl;
        if(this == &data)
            return *this;
        delete [] str;

        length = data.length;
        str = new char[length+1];
        strcpy(str,data.str);

        return *this;
    }

    String& operator=(String &&data)
    {
        std::cout << "move constructor ass" << std::endl;
        if(this == &data)
            return *this;
        delete [] str;

        str = data.str;
        length = data.length;
        data.str = nullptr;
        data.length = 0;

        return *this;
    }

    String operator+(const String &data)
    {
        unsigned int newlength = length + data.length;
        char *newstr = new char[newlength+1];
        strcpy(newstr,str);
        strcat(newstr,data.str);

        String newstring;
        newstring.length = newlength;
        newstring.str = newstr;

        //delete [] newstr;

        return newstring;
    }

    void print()
    {
        if(str)
        {
            std::cout << str << std::endl;
        }
    }

    ~String()
    {
        delete [] str;
    }

};
int main()
{
    String s1("hello ");
    String s2("ismail ");
    //String s3(std::move(s2));//move
    //String s3(s2);//copy
    String s3 = s1 + s2;
    s3.print();
}
