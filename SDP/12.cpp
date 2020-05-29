//Write a program in C++ to display the sum of the series [ 9 + 99 + 999 + 9999 ...].

#include<iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n=3,sum=9,temp=9;
    while(n>1)
    {
        temp=(temp*10)+9;
        sum=sum+temp;
        n--;
    }
    cout<<sum;
    return 0;
}
