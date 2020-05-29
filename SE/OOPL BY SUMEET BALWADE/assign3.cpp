#include<iostream>
using namespace std;
class data
{
	private:
	string name;
	int roll;
	long int contact;
	static int c;

	
	public:
	void getdata();
	void display();
	data();
	static int getcount();
	data(data *obj);
	data(string name ,int roll ,long int contact);
	~data();
};
	int data::c=0;

	data::data(data *obj)
	{
			cout<<" copy constructor is implemented"<<endl;
	}
	
	data::~data()
{
	cout<<"destructor called\n";
}

	
	void data::getdata()
{
	cout<<"enter student name\n";
	cin>>name;
	cout<<"enter student roll\n";
	cin>>roll;
	
		cout<<"enter student contact\n";	
	cin>>contact;
}	
	void data::display()
{
	cout<<"name"<<name<<endl;
	cout<<"roll"<<roll<<endl;
	cout<<"contact"<<contact<<endl;
	
	
}
data::data(string name,int roll,long int contact)
{
	cout<<"parametrised constructor is implememted"<<endl;
	c++;
	this->name=name;
	this->roll=roll;
	this->contact=contact;
}
data::data()
{
	name="name";
	roll=0;
	contact=0;
		
	cout<<"default constructor"<<endl;
	c++;
}
	int data::getcount()
{
	return c;
}
	int main()
	{
		int num;
		data *d1=new data();
		d1->display();
		delete d1;
		data *d2=new data("shilpa",47,8765432109);
		d2->display();
		data *d3=new data(d2);
		d3->display();
		delete d2;
		cout<<"enter the size of database";
		cin>>num;
		data dx[num];
		for(int i=0;i<num;i++)
     {
       dx[i].getdata();
     }
   for(int i=0;i<num;i++)
     {
       dx[i].display();
     }
cout<<"number of constructor calls and total number of object:"<<data::getcount()<<endl;
return 0;
}

	
	

	
