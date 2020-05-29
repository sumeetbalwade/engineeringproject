//Write a program in C++ to find the factorial of a number

#include<iostream>

using namespace std;



int main(int argc, char const *argv[])
{
    int fact=1,n=5;

    for (int i = n; i >0; i--)
    {
        fact=fact*i;
    }
    cout<<fact;
    return 0;
}
