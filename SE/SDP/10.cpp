//Write a program in C++ to find the sum of digits of a given number

#include<iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n=1234,sum=0,r;

    while (n!=0)
    {
        r=n%10;
        sum+=r;
        n/=10;

    }
    cout<<sum;
    return 0;
}
