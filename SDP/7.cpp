//Write a c program to exchange the value of two variable without using third variable?
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x=10,y=20;

    cout<<"value of x is "<<x<<" value of y is "<<y;
    
    x=x+y;
    y=x-y;
    x=x-y;
    cout<<"\n value of x is "<<x<<" value of y is "<<y;
    return 0;
}
