#include<iostream>
using namespace std;

class calculator
{
   private:
    float val;
  public:
  void getdata()
  {
    cin>>val;
 }
void showdata()
{
   cout<<val<<endl;
}

 calculator operator + (calculator a);
 calculator operator - (calculator a);
 calculator operator * (calculator a);
 calculator operator / (calculator a);
};
calculator  calculator :: operator + (calculator a)
{
  calculator temp;
  temp.val=val+a.val;
  return temp;
}


 calculator calculator :: operator - (calculator a)
{
  calculator temp;
  temp.val=val-a.val;
  return temp;
}


 calculator  calculator :: operator * (calculator a)
{
  calculator temp;
  temp.val=val*a.val;
  return temp;
}


 calculator calculator :: operator / (calculator a)
{
  calculator temp;
  temp.val=val/a.val;
  return temp;
}

int main()
{
  calculator ob1,ob2,ob3,ob4;
   int choice;
while(1)
{
 cout<<"enter your choice";
  cin>>choice;
 ob1.getdata();
 cout<<"entered value is";
 ob1.showdata();
 ob2.getdata();
 cout<<"entered value is";
 ob2.showdata();
 
    switch(choice)
  {
     case 1:
                 ob3=ob1+ob2;
                break;
      case 2:
                 ob3=ob1-ob2;
                break;
      case 3:
                 ob3=ob1*ob2;
                break;
      case 4:
                 ob3=ob1/ob2;
                break;
}
     cout<<"result is";
      ob3.showdata();
}

return 0;
}






















































