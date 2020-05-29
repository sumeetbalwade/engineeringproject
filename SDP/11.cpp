//Write a program in C++ to find the sum of the series 1 +11 + 111 + 1111 + .. n terms


#include<iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n=3,sum=1,temp=1;
    while(n>1)
    {
        temp=(temp*10)+1;
        sum=sum+temp;
        n--;
    }
    cout<<sum;
    return 0;
}
