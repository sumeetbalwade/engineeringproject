#include<iostream>
using namespace std;
class complex
{
 private:
 int real;
 int imag;
public:
float x;
float y;
complex(){}
complex(float real,float imag)
{x=real;y=imag;}
complex operator+(complex);
complex operator*(complex);
friend void operator<<(ostream&output,complex&s);
friend void operator>>(istream&input,complex&q);
void display(void);
};
 complex complex::operator+(complex c)
  {
   complex temp;
   temp.x=x+c.x;
   temp.y=y+c.y;
   return(temp);
  }
  complex complex::operator*(complex c)
   {
    complex temp1;
    temp1.y=(y*c.x)+(x*c.y);
    temp1.x=(y*c.y)-(x*c.x);
    return(temp1);
}
   void complex::display(void)
    {
     cout<<x<<"+i"<<y<<"\n";
    }
    void operator<<(ostream&output,complex&s)
     {
      cout<<s.x<<"+"<<s.y<<"i";
     }
    void operator>>(istream&input,complex&q)
     {
      cin>>q.x>>q.y;
     }
    int main()
   {
    complex c1,c2,c3,c4;
    cout<<"enter first object"<<"\n";
    cin>>c3;
    cout<<"\nenter second object";
    cin>>c4;
   cout<<"object first is:\n"<<c3;
    cout<<"\nobject second is:\n"<<c4;
    c1=c3+c4;
    c2=c3*c4;
    cout<<"\naddition:"<<c1;
     cout<<"\nmultiplication:"<<c2;
    
    return 0;
   }
    

