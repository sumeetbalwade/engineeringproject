#include<iostream>
#include<string>
using namespace std;
class data
{
     int age,i;
    double income;
     string city;
     char fw;
      int cnt;
   public:
       void getage()
      {
		try
	{
            cout<<"Enter the age"<<endl;
             cin>>age;
               if(age<18 || age>55)
                   throw(age);
                 else
                       cnt++;
             }
            catch(int i)
           {
               cout<<"exception caught:the age should be between 18 and 55"<<endl;
               }
           }
	void getincome()
	  {
		try
	{
            cout<<"Enter the income"<<endl;
             cin>>income;
               if(income<50000 || income>100000)
                   throw(income);
	
         else
                       cnt++;
             }
            catch(double d)
           {
               cout<<"exception caught:the income should be between 50000 and 100000"<<endl;
               }
           }    
              
	void getcity()
{
	try
{
	cout<<"Enter the city"<<endl;
	cin>>city;
	if(city=="pune" || city=="mumbai" || city=="banglore" || city=="chennai")
	cnt++;
	 else 
	throw(city);
}
	catch(string s)
  {
               cout<<"exception caught:the city should be either pune,mumbai,banglore or chennai"<<endl;
               }
           }    
  
	void getfw()
{
	try
{
	cout<<"do you have the fw?"<<endl;
	cin>>fw;
	if(fw=='y' || fw=='Y')
	cnt++;
	 else 
	throw(fw);
}
	catch(char w)
  {
               cout<<"exception caught:the fw is not present"<<endl;
               }
           }    
  void print()
{
	if(cnt==4)
	cout<<"No incorrect data provided, thanks";
}
};
	int main()
{
	data obj;
	obj.getage();
	obj.getincome();
	obj.getcity();
	obj.getfw();
	obj.print();
	return 0;
}

     
