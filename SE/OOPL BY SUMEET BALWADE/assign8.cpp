#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class person
{
char name[20];
int age;
char gender[20];
public:
void getdata();
void putdata();
};


void person::getdata()
{
cout<<"enter name";
cin>>name;
cout<<"enter age";
cin>>age;
cout<<"enter gender";
cin>>gender;
}


void person::putdata()
{
cout<<"\n"<<name<<"\t"<<age<<"\t"<<gender;
}


int main()
{
int i,n;
person human;
ofstream fout;
ifstream fin;
fout.open("sample9.txt", ios::out);

cout<<"how many data of person want to enter";
cin>>n;
for(i=0;i<n;i++)
{
human.getdata();
fout.write((char*)&human,sizeof(human));
}
fout.close();
cout<<"info is as follow";
fin.open("sample9.txt" ,ios::in);
for(i=0;i<n;i++)
{
fin.read((char*)&human,sizeof(human));
human.putdata();
}
fin.close();
return 0;
}
