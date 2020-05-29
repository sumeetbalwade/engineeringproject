#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class telephone
{
   int number;
    char name[20];
   public:
    void accept()
    {
       cout<<"\n enter name and telephone number:";
        cin>>name;
        cin>>number;
       }
     void display()
    {
      cout<<"\n"<<name<<"\n"<<number;
     }
     int search(int num)
   {
     if(number==num)
     {
         cout<<"\nREcord found";
         cout<<"\n"<<name<<"\n"<<number;
           return 1;
         }
      else
    return 0;
 }
   int search(char a[])
   {
      if(!strcmp(name,a))
     {
         cout<<"\nREcord found";
         cout<<"\n"<<name<<"\n"<<number;
           return 1;
         }
      else
    return 0;
 }
};

int main()
{
   int ch,n,i,flag;
   long int number;
    char name[20];
    telephone t;
     fstream file;
   while(1)
{
  cout<<"\n1.Enter information:";
   cout<<"\n2.Display";
   cout<<"\n3.search using number";
   cout<<"\n4.search using name";
   cout<<"\n5.Exit\n";
   cout<<"\nEnter your choice:\n";
   cin>>ch;
   switch(ch)
   {
     case 1:
              file.open("/home/jspm",ios::out);
              cout<<"\n how many number wanted to add:";
              cin>>n;
               for(i=0;i<n;i++)
                 {
                    t.accept();
                     file.write((char*)&t,sizeof(t));
                   }
                file.close();
                   break;
     case 2:
              file.open("/home/jspm/number.txt",ios::out);
              cout<<"\ntelephone information is:\n";
                 while(file)
                      {
                          file.read((char*)&t,sizeof(t));
                           t.display();
                        }
                  file.close();
                   break;

       case 3:
               file.open("/home/jspm/number.txt",ios::out);
               cout<<"\nEnter number you wanted to search:\n";
               cin>>number;
               flag=0;
                while(file)
                  {
                      file.read((char*)&t,sizeof(t));
                       if(t.search(number))
                          {
                               flag=1;
                               break;
                            }
                     }
                if(flag==0)
                  cout<<"\n Record not found\n";
                   file.close();
                   break;
      case 4:
              file.open("/home/jspm/number.txt",ios::out);
               cout<<"\nEnter name you wanted to search:\n";
                cin>>name;
                flag=0;
                while(file)
                {
                     file.read((char*)&t,sizeof(t));
                       if(t.search(name))
                          {
                               flag=1;
                               break;
                            }
                     }
                if(flag==0)
                  cout<<"\n Record not found\n";
                   file.close();
                   break;
      
        }
}
   
 return 0;
}























