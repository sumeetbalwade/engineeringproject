//Write a c++ program to calculate the marks of five subjects and find the average?

#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int x;
    float avg=0;
    cout<<"Enter Marks for subject \n";
    for (int i = 0; i < 5; i++)
    {
        cin>>x;        
        avg=avg+x;
    }
    avg/=5;

    cout<<"\n Average of 5 marks are "<<avg;

    return 0;
}
