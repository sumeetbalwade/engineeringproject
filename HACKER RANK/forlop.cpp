#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,a,b;
    cin >> a >> b;

    for ( n = a; n <= b; n++)
    {
         if(n>=1 && n<=9)
        {
            switch(n)
            {
                case 1: cout<<"one\n";
                    break;
                case 2: cout<<"two\n";
                    break;
                case 3: cout<<"three\n";
                    break;
                case 4: cout<<"four\n";
                    break;
                case 5: cout<<"five\n";
                    break;
                case 6: cout<<"six\n";
                    break;
                case 7: cout<<"seven\n";
                    break;
                case 8: cout<<"eight\n";
                    break;
                case 9: cout<<"nine\n";
                    break;
                
            }
        }
        else if (n>9)
        {
            if (n%2==0)
            {
                cout<<"even\n";
            }
            else
            {
                cout<<"odd\n";
            }
            
            
        }
        
    }
    



   

    return 0;
}
