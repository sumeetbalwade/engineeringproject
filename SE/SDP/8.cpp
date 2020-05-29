//WAP by using nested if else statement enter three number and find greatest.


#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a=21,b=80,c=9;

    if (a>b)
    {
        if (a>c)
        {
            cout<<a;
        }
        
    }
    else
    {
        if (b>c)
        {
            cout<<b;
        }
        else
        {
            cout<<c;
        }
        
        
    }
    
    
    return 0;
}
