#include<iostream>
using namespace std;
class personal
{
  protected:
 string name;
long int contact;
public:
void disp_p1();
};
void personal::disp_p1()
{
  cout<<"The name of employee is"<<name<<endl;
  cout<<"Contact no of  employee is"<<contact<<endl;
}

class professional
{
  protected:
  string companyname;
  int experen;
 public:
 void disp_p2();
};
void professional::disp_p2()
{
   cout<<"The name of company is"<<companyname<<endl;
   cout<<"The experience of employee is"<<experen<<endl;
 }

class academic
{
   protected:
   float sscmarks;
  float hscmarks;
 public:
  void dispa();
};
void academic::dispa()
{
   cout<<"The ssc marks of employee is"<<sscmarks<<endl;
   cout<<"The hsc marks of employee is"<<hscmarks<<endl;
}

class biodata:public personal,public professional,public academic
{
  public:
  void accept();
  void display();
};
void biodata::accept()
{
  cout<<"enter employee name";
  cin>>name;
cout<<"enter employee contact no";
 cin>>contact;
cout<<"enter company name";
 cin>>companyname;
cout<<"enter experience";
cin>>experen;
cout<<"enter ssc marks";
cin>>sscmarks;
cout<<"enter hsc marks";
cin>>hscmarks;
}
void biodata::display()
{
   disp_p1();
   disp_p2();
   dispa();
}

int main()
{
   biodata b;
   b.accept();
  b.display();
  return 0;
}
  
   













































