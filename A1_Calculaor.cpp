/*              ASIGNMENT 1
    Write a CPP Program to create a calculator for an areithematic operation (+,-,*,/) .
    The program should take two operands from user and 
    perform the operation on those two operands depends upon operation entered by the user. 
    use a switch statement to select the operation.
    Finally Display the Result. 

 */


#include<iostream>
#include<cstdlib>           //for using system cls and pause


using namespace std;        //including standards

void addition(int a,int b)  //Addition function 
{
    system("cls");
    cout<<"The Addition of "<<a<<" and "<<b<<" is "<<a+b<<endl;

}

void mutiplication(int a,int b) //Multiplication Function
{
    system("cls");
    cout<<"The Multiplication of "<<a<<" and "<<b<<" is "<<a*b<<endl;

}

void substration(int a,int b)   //Substration Function
{
    system("cls");
    cout<<"The Substration of "<<a<<" and "<<b<<" is "<<a-b<<endl;

}

void division(int a,int b)      //Division Function
{
    system("cls");
    cout<<"The Division of "<<a<<" and "<<b<<" is "<<(float)a/b<<endl;

}





int main()
{
    int ch,a,b,t,flag=0;
    do
    {
        system("cls");

        //Taking input of two Numbers
        cout<<"Enter First Number on which you have to perform operation \n";
        cin>>a;

        cout<<"Enter Second Number on which you have to perform operation \n";
        cin>>b;

        system("cls");

        //Menu for Calculator
        cout<<"Calculator\n\n";
        cout<<"1. Addition \n2. Substration \n3. Multiplication \n4. Division \n5. Exit   \n Enter Your Choice \n";
        cin>>ch;

        //Performing operation According to choice of the user using switch case
        switch (ch)
        {
        case 1:     {
                        addition(a,b);
                        break;
                    }
        case 2:     {
                        substration(a,b);
                        break;
                    }            
        case 3:     {
                        mutiplication(a,b);
                        break;
                    }   
        case 4:     {
                        division(a,b);
                        break;
                    }
        case 5:     {
                        cout<<"\nExiting\n";
                        flag=1;
                        break;
                    }                                             
        default:    {
                        cout<<"\nWrong Choice\n";
                        break;
                    }
        }
        system("pause");
     
    } while (flag==0);  //Checking the Exit Condition

    return 0;
    


}