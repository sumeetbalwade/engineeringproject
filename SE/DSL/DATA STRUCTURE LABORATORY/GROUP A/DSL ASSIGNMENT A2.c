
#include<stdio.h>
#include<stdlib.h>                                                  //for System cls and pause


int count=0;                            //to count absent students
int i,n,tem;                            //n is index of last element use in all function
int marks[60];                          //Array used to store Marks 

int menu();                             //function for printing main menu
void abse();                            //function for counting absent students
void max();                             //function for calculating maximum marks scored in class
void min();                             //function for minimum marks scored in class
void avg();                             //function for calculating average
void input();                           //function for taking input in array
void display();                         //function for displaying the data
void mocc();                            //function for calculating maximum occurance marks of students 
void entry();


int main()                              //main function
{
    int f=1;                            //flag for termination on loop
    entry();
    system("cls");                      //clear screen function
      
    
    //taking no of Students input
    printf("Enter the Number of student ");
    scanf("%d",&n);

    //assigning all elements of array to -1 initally all are absent
    for ( i = 0; i < n; i++)
    {
        marks[i]=-1;
    }
    
    system("cls");
    
    do
    {
        f=menu();                       //Calling the menu function for the start of the applicaion
    } while (f==1);
    
    return 0;
}

void abse()                             //function for counting absent students
{
    
    system("cls");
    printf("\tABSENT STUDENTS\nROLL NO\n");

    //tavelling the array and checking if any element is -1 if yes the counting it so we can find absentess
    for ( i = 0; i < n; i++)
    {
        if (marks[i]==-1)
        {
            printf("%d\n",i+1);
            count++;
        }
        
    }

    printf("\n Total Absent Students are %d",count);
    system("pause");                                                        //function for pausing the execution
    
}

void max()                              //function for calculating maximum marks scored in class
{
    int m=marks[0];                     //initially concedering the first element as max marks
    system("cls");
    int r=0;                            //to store the roll number of Topper
    for ( i = 1; i < n; i++)             
    {
        if(m<marks[i])                  //checking if our assumption of max marks is wrong
        {
            m=marks[i];
            r++;
        }
    }

    printf("\n the Maximum marks are %d and Scored by Roll No %d",m,r+1);
    system("pause");
        
}

void min()                              //function for minimum marks scored in class
{
    int m=marks[0];                     //initially concedering the first element as min marks
    system("cls");
    int r=0;                            //to store the roll number of student who scored low
    for ( i = 1; i < n; i++)
    {
        if(m>marks[i])                  //checking if our assumption of min marks is wrong
        {
            m=marks[i];
            r++;
        }
    }

    printf("\n the Minimum marks are %d and Scored by Roll No %d",m,r+1);
    system("pause");
        
}
void avg()                              //function for calculating average
{
    int a=0,d;
    system("cls");
    for ( i = 0; i < n; i++)
    {
        if (marks[i]!=-1)               //this statement neglect the absent students
        {
            a=a+marks[i];
        }
               
    }
    d=n-count;                          //substracting absent student from total
    printf("Average is %f\n\n",(float)a/d); //float typecasted because average is float
    system("pause");
    
}

void input()                            //function for taking input in array
{
    
    
    for ( i = 0; i < n; i++)
    {
        system("cls");
        printf("\n Entry Window\n");
        printf("Enter -1 for absent\n");
        printf("\n Enter the marks of Roll no = %d \n",i+1);
        scanf("%d",&marks[i]);
        
    }
    
}
void display()                          //function for displaying the data
{
    
    system("cls");
    printf("\n \tDisplay Window\n");
    printf("Rollno\t\t\tMARKS\n\n");
    for ( i = 0; i < n; i++)
    {
        if (marks[i]==-1)
        {
            printf("%d\t\t\tABSENT\n",i+1);
        }
        else
        {
            printf("%d\t\t\t%d\n",i+1,marks[i]);
        }
        
       
        
    }
    system("pause");
    
}

int menu()                              //function for printing main menu
{
    int ch;
    system("cls");

    //printing the menu
    printf("\n\t MAIN MENU\n1. Input the Marks \n2. Display the Marks \n3. Average Of Class \n4. Maximum Marks \n5. Minimum Marks");
    printf("\n6. Absent Students \n7. Most Occurence \n8. Exit");
    printf("\n Enter the Choice \n");
    scanf("%d",&ch);

    switch (ch)
    {
        case 1: {
                    input();
                    break;
                }

        case 2: {
                    display();
                    break;
                }
        case 3:{
                    avg();
                    break;
                }

        case 4: {
                    max();
                    break;
                }
        case 5: {
                    min();
                    break;
                }
        case 6: {
                    abse();
                    break;
                }
        case 7: {
                    mocc();
                    break;
                }
        case 8: {
                    return 0;
                    break;
                }
        default:{   
                    printf("Wrong Choice");
                    break;
                }
        
    }
    return 1;
}

void entry()
{
    printf("\t\t\tASSIGNMENT NO 1 \n\nWrite a C Program to store marks scored for first test of subject 'Data Structure and Algorithm ' for N students. Compute\n");
    printf("1.The Average Score of Class.\n2. Highest Score and lowest Score of class.\n3. Marks score by most of the student.\n4. list of student who where absent for test.\n");
    printf("Assignment by SUMEET BALWADE\nGuided by NIMBALKAR SIR\n");

    system("pause");
}

//IMPORTANT
void mocc()                 //function for calculating maximum occurance marks of students
{
    int occurance[100];             //the index denotes marks & the elements in the array store the count of marks of that index 
    int track;                      //a temperory variable to store the index of occurance

    system("cls");

    for ( i = 0; i < 100; i++)      //Making array elements zero
    {
        occurance[i]=0;
    }
    
    for ( i = 0; i < n; i++)           //storing count in index i.e. marks
    {
        
        track=marks[i];
        occurance[track]++;             //incrementing occurance count
    }

    //finding the maximum occurance 
    int m=occurance[0],ind=0;
    for ( i = 1; i < 100; i++)
    {
        if(m<occurance[i])
        {
            m=occurance[i];         //here m stores the count of the individual marks
            ind=i;                  //ind remembers the marks value
        }
    }

    printf("\n Marks Scored by Most Students are %d and %d Student Scored it.\n",ind,m);
    system("pause");
}