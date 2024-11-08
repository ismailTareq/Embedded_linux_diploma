#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

void decimaltobinary(int dec_num)
{
    int arr[11],i=0;
    while(dec_num)
    {
        arr[i] = dec_num%2;
        i++;
        dec_num = dec_num / 2;
    }
    cout<< "Binary representation : ";
    for(int j = i-1;j>=0;j--)
    {
        cout<<arr[j];
    }
    cout<<endl;
}

int binarytodecimal(int bin_num)
{
    int base = 1,dec_num = 0,x;
    while(bin_num)
    {
        x = bin_num % 10;
        dec_num += x*base;
        base *= 2;
        bin_num = bin_num / 10;
    }
    return dec_num;
}

int main()
{
    /*
    int dec_num,bin_num,dec_value;

    cout << "input a decimal number: ";
    cin >> dec_num ;

    decimaltobinary(dec_num);

    cout << "input a binary number: ";
    cin >> bin_num ;


    cout << "decimal value: "<<binarytodecimal(bin_num)<<endl;
    */
    string binary_string;
    int deciaml;
    int choice;

    cout << "Enter 1 for binary to decimal or Enter 2 for decimal or binary : ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter a binary number: ";
        cin >> binary_string;

        bitset<8> binary(binary_string);


        cout << "The decimal value is : "<< binary.to_ulong() << endl;
    }
    else if (choice == 2)
    {
        cout << "Enter a decimal number: ";
        cin >> deciaml;

        bitset<8> binaryNumber(deciaml);

        cout << "The binary value is : "<< binaryNumber << endl;
    }
    else
    {
        cout << "Enter Valid Choice " << endl;
    }
    return 0;
}
