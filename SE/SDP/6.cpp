//Write a c program to exchange the value of two variable using third variable?
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x=10,y=20,temp;

    cout<<"value of x is "<<x<<" value of y is "<<y;
    temp=x;
    x=y;
    y=temp;
    cout<<"\n value of x is "<<x<<" value of y is "<<y;
    return 0;
}
