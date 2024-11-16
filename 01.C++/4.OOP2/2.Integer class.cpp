#include <bits/stdc++.h>

class Integer
{
private:
    int number;

public:
    Integer(int num)
    :number(num)
    {

    }

    Integer &operator+=(const Integer &num)
    {
        //this->number
        number += num.number;
        return *this;
    }

    Integer &operator-=(const Integer &num)
    {
        //this->number
        number -= num.number;
        return *this;
    }

    Integer &operator*=(const Integer &num)
    {
        //this->number
        number *= num.number;
        return *this;
    }

    Integer &operator/=(const Integer &num)
    {
        //this->number
        number /= num.number;
        return *this;
    }

    Integer &operator%=(const Integer &num)
    {
        //this->number
        number %= num.number;
        return *this;
    }

    int operator+(const Integer &num)
    {
        return number + num.number;
    }

    int operator-(const Integer &num)
    {
        return number - num.number;
    }

    Integer &operator=(const Integer &num)
    {
        number = num.number;
        return *this;
    }

    Integer &operator=(const int num)
    {
        number = num ;
        return *this;
    }

    Integer &operator+(const int &num)
    {
        number *= num;
        return *this;
    }

    Integer &operator++()
    {
        number++;
        return *this;
    }

    Integer &operator--()
    {
        number--;
        return *this;
    }

    Integer &operator--(int)
    {
        Integer num = this->number;
        number--;
        return num;
    }

    Integer &operator++(int)
    {
        Integer num = this->number;
        number++;
        return num;
    }

    bool operator>(const Integer &num)
    {
        return number > num.number;
    }

    bool operator<(const Integer &num)
    {
        return number < num.number;
    }

    bool operator>=(const Integer &num)
    {
        return number >= num.number;
    }

    bool operator<=(const Integer &num)
    {
        return number <= num.number;
    }

    bool operator==(const Integer &num)
    {
        return number == num.number;
    }

    bool operator!=(const Integer &num)
    {
        return number != num.number;
    }

    int operator&(const int num)
    {
        return number & num;
    }

    int operator|(const int num)
    {

        return number | num;
    }

    int operator^(const int num)
    {
        return number ^ num;
    }

    void print()
    {
        std::cout << number << std::endl;
    }

};
int main()
{
    Integer num1{10};
    Integer num2{20};
    int x;
/*
    num1 += num2;
    num1.print();

    num1 -= num2;
    num1.print();

    num1 *= num2;
    num1.print();

    num1 /= num2;
    num1.print();

    num1 %= num2;
    num1.print();

    x = num1+num2;
    std::cout<<x<<std::endl;

    x = num1-num2;
    std::cout<<x<<std::endl;

    x = num1+num2;
    std::cout<<x<<std::endl;

    num1 = num2 + x;
    num1.print();
*/
    num2++;
    num2.print();

    ++num2;
    num2.print();

    num2--;
    num2.print();

    --num2;
    num2.print();

}
