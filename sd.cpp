#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>


using namespace std;


class student
{
public:
  unsigned short int rollno; 
  long long int mobile;
  char name[10];
  char password[10];
  void input();
  void display();

};


class teacher
{
public:
  unsigned short int usercode; 
  long long int mobile;
  char name[10];
  char password[10];
  void input();
  void display();

};


class assignment
{
public:
    unsigned short int rollno;
    char assignment[20];

    void input(unsigned short int roll,char assi[])
    {
        rollno = roll;
        strcpy(assignment,assi);
    }
    void diaplay()
    {
        cout<<"\n\t "<<assignment;
    }
};


void read_assignment(unsigned short int rollno)
{
    ifstream fin;
    assignment obj;
    fin.open("assignment.txt");
    while (fin.read((char*) &obj,sizeof(obj)))
    {
        if(obj.rollno == rollno)
        {
            obj.display();
        }
    }
    fin.close();

}



void teacher::display()
{
    cout<<"\n\n\t\t\t TEACHERS DETAILS ";
    cout<<"\n\n\t Usercode : "<<usercode;
    cout<<"\n\t Name : "<<name;
    cout<<"\n\t Mobile Number : "<<mobile;
}


void teacher::input()
{
    int choice;
    lb7:
    system("cls");
    cout<<"\n\n\t\t\tENTER TEACHERS DETAILS ";
    cout<<"\n\n\t Usercode : ";
    cin>>usercode;

    cout<<"\n\t Name : ";
    cin.ignore();
    cin>>name;

    cout<<"\n\t Mobile Number : ";
    cin>>mobile;

    cout<<"\n\t Password : ";
    cin.ignore();
    cin>>password;

    lb8:
    cout<<"\n\nWARNING : CHECK YOUR DETAILS \n 1. DETAILS ARE OK \n 2. CLEAR DETAILS \nEnter the Choice : ";
    cin>>choice;

    if (choice == 1 || choice == 2)
    {
        if (choice==1)
        {
            return;
        }
        else
        {
            goto lb7;
        }
        
    }
    else
    {
        cout<<"YOU HAVE ENTERED A WRONG CHOICE";
        goto lb8;
    }
}


bool search_teacher(unsigned short int usercode)
{
    ifstream fin;
    teacher obj;
    fin.open("teacher.txt");
    while (fin.read((char*) &obj,sizeof(obj)))
    {
        if(obj.usercode == usercode)
        {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}


void read_teacher(unsigned short int usercode)
{
    ifstream fin;
    teacher obj;
    fin.open("teacher.txt");
    while (fin.read((char*) &obj,sizeof(obj)))
    {
        if(obj.usercode == usercode)
        {
            obj.display();
        }
    }
    fin.close();
}


void register_teacher()
{
    teacher obj;
    lb9:
    obj.input();
    if (!search_teacher(obj.usercode))
    {
        ofstream fout;
        fout.open("teacher.txt",ios::app);
        cout<<"\nWRITING THE DATA ...\n";
        fout.write((char*) &obj,sizeof(obj));
        cout<<"WRITING OF DATA SUCCESSFULL ...\n";
        fout.close();
    }
    else
    {
        cout<<"STUDENT ALREADY EXISTS\n";
        system("pause");
        goto lb9;
    } 
}


void teacher_login()
{
    unsigned short int usercode;
    char password[10];
    ifstream fin;
    teacher obj;

    system("cls");
    cout<<"\n\n\t\t\tTEACHERS LOGIN ";
    cout<<"\n\n\t USERCODE : ";
    cin>>usercode;
    cout<<"\n\t PASSWORD : ";
    cin.ignore();
    cin>>password;

    fin.open("teacher.txt");
    while (fin.read((char*) &obj,sizeof(obj)))
    {
        if(obj.usercode == usercode && !strcmp(password,obj.password))
        {
            cout<<"\n\n\t\t\tLOGIN SUCCESSFULL \n\n";
            obj.display();
            fin.close();
            return;
        }
    }
    fin.close();
    cout<<"\n\n\t\t\tLOGIN UNSUCCESSFULL \n\n\n";
    
}







void student::display()
{
    cout<<"\n\n\t\t\t STUDENTS DETAILS ";
    cout<<"\n\n\t Roll No : "<<rollno;
    cout<<"\n\t Name : "<<name;
    cout<<"\n\t Mobile Number : "<<mobile;
}


void student::input()
{
    int choice;
    lb1:
    system("cls");
    cout<<"\n\n\t\t\tENTER STUDENTS DETAILS ";
    cout<<"\n\n\t Roll No : ";
    cin>>rollno;

    cout<<"\n\t Name : ";
    cin.ignore();
    cin>>name;

    cout<<"\n\t Mobile Number : ";
    cin>>mobile;

    cout<<"\n\t Password : ";
    //cin.ignore();
    cin>>password;

    lb2:
    cout<<"\n\nWARNING : CHECK YOUR DETAILS \n 1. DETAILS ARE OK \n 2. CLEAR DETAILS \nEnter the Choice : ";
    cin>>choice;

    if (choice == 1 || choice == 2)
    {
        if (choice==1)
        {
            return;
        }
        else
        {
            goto lb1;
        }
        
    }
    else
    {
        cout<<"YOU HAVE ENTERED A WRONG CHOICE";
        goto lb2;
    }
}


bool search_student(unsigned short int rollno)
{
    ifstream fin;
    student obj;
    fin.open("student.txt");
    while (fin.read((char*) &obj,sizeof(obj)))
    {
        if(obj.rollno == rollno)
        {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}


void read_student(unsigned short int rollno)
{
    ifstream fin;
    student obj;
    fin.open("student.txt");
    while (fin.read((char*) &obj,sizeof(obj)))
    {
        if(obj.rollno == rollno)
        {
            obj.display();
        }
    }
    fin.close();
}


void register_student()
{
    student obj;
    lb3:
    obj.input();
    if (!search_student(obj.rollno))
    {
        ofstream fout;
        fout.open("student.txt",ios::app);
        cout<<"\nWRITING THE DATA ...\n";
        fout.write((char*) &obj,sizeof(obj));
        cout<<"WRITING OF DATA SUCCESSFULL ...\n";
        fout.close();
    }
    else
    {
        cout<<"STUDENT ALREADY EXISTS\n";
        system("pause");
        goto lb3;
    } 
}


void student_login()
{
    unsigned short int rollno;
    char password[10];
    ifstream fin;
    student obj;

    system("cls");
    cout<<"\n\n\t\t\tSTUDENTS LOGIN ";
    cout<<"\n\n\t ROLL NO : ";
    cin>>rollno;
    cout<<"\n\t PASSWORD : ";
    cin.ignore();
    cin>>password;

    fin.open("student.txt");
    while (fin.read((char*) &obj,sizeof(obj)))
    {
        if(obj.rollno == rollno && !strcmp(password,obj.password))
        {
            cout<<"\n\n\t\t\tLOGIN SUCCESSFULL \n\n";
            obj.display();
            fin.close();
            return;
        }
    }
    fin.close();
    cout<<"\n\n\t\t\tLOGIN UNSUCCESSFULL \n\n\n";
    
}


int main(int argc, char const *argv[])
{
    //register_student();
    //read_student(1);
    //student_login();
    //register_teacher();
    //read_teacher(1);
    //teacher_login();
    return 0;
}
