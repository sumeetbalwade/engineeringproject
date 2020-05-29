/*
******************************ASSIGNMENT NUMBER A-1 ***********************************

STATEMENT

1. In Second year Computer Engineering class of M students, set A of students play cricket and
set B of students play badminton. Write C/C++ program to find and displayi. Set of students who play either cricket or badminton or both
ii. Set of students who play both cricket and badminton
iii. Set of students who play only cricket
iv. Set of students who play only badminton
v. Number of students who play neither cricket nor badminton
(Note- While realizing the set duplicate entries are to avoided)

OS - WINDOWS x64
IDE - MICROSOFT VISUAL STUDIO CODE 2019
COMPILER - GNU/MINGW GCC

ASSIGNMENT BY SUMEET BALWADE
GUIDED BY PROF. NIMBALKAR 

*/


#include<stdio.h>
#define clear() printf("\033[H\033[J")     //clear screen


int b[50],c[50];            //array for storing rollno of students playing
int nc,nb,i,j,e=0,check;    //limit for arrays

void bdisplay();            //Display Badminton students
void cdisplay();            //Display of Cricket Students
void binput();              //Input Students of badminton
void cinput();              //Input student of Cricket
void bcintersection();      //Student playing Badminton and Cricket
void bcunion();             //Student Playing Baminton as well as cricket
void ocicket();             //Student Playing Only Cricket
void obadminton();          //Student playing only Badminton
void negitation();          //Negiation
void menu();                //Main Menu


int main()
{
    
    do
    {
        clear();
        menu();
    } while (e==1);
    return 0;
 
}


void bdisplay()             //Display Badminton students
{
    printf("\n Student playing Badminton are  \n {");
    for ( i = 0; i < nb; i++)
    {
        printf("%d  ,",b[i]);
    }
    printf("}");
}

void cdisplay()             //Display of Cricket Students
{
    printf("\n Student playing cricket are  \n {");
    for ( i = 0; i < nc; i++)
    {
        printf("%d  ,",c[i]);
    }
    printf("}");
}

void binput()               //Input Students of badminton
{
    printf("\n Enter number of roll no playing badminton \n");
    scanf("%d",&nb);

    printf("Enter their Roll no \n");
    for ( i = 0; i < nb; i++)
    {
        scanf("%d",&b[i]);
    }
}

void cinput()               //Input student of Cricket
{
    printf("\n Enter the number of roll no playing cricket\n");
    scanf("%d",&nc);


    printf("Enter their Roll no \n");
    for ( i = 0; i < nc; i++)
    {
        scanf("%d",&c[i]);
    }
}

void bcintersection()       //Student playing Badminton and Cricket
{
    printf("\n Student Playing both Cricket and Badminton \n{ ");
    for ( i = 0; i < nb;i++) 
    {
        for ( j = 0; j < nc; j++)
        {
            if (b[i]==c[j])
            {
                printf("%d  ,",b[i]);       //If the roll number are equal then display
            }
            
        }
        
    }
    printf(" }");1
    
}

void bcunion()              //Student Playing Baminton as well as cricket
{   int u[100],flag;
    int nu=nc;              //storing size of union
   
    for ( i = 0; i < nc; i++)       
    {
        u[i]=c[i];          //Copying cricket array in u
    }
    
    for ( i = 0; i < nb; i++)
    {
        flag=0;            //initillay flag is zero
        
        for ( j = 0; j < nc; j++)
        {
            if (u[j]==b[i]) 
            {
                flag=1;     //if number is equal flag will be one
            }
            
            
        }
        if (flag==0)        //this mean no are not equal
        {
            
            u[nu]=b[i];     //copy the number into temprary array i.e. u 
            nu++;           //incrementing index of u
        }
        
    }

    //Displaying no of element of u which are uncommon in b and c
    printf("\n The UNION is {");
    for ( i = 0; i < nu; i++)
    {
        printf("%d  ,",u[i]);
    }
    printf("}");
    
}

void ocicket()              //Student Playing Only Cricket
{
    int temp[30];
    
    for ( i = 0; i < nc; i++)
    {
        temp[i]=c[i];       //Copying roll of students playing Cricket in temp
    }
    for ( i = 0; i < nc; i++)
    {
        for ( j = 0; j < nb; j++)
        {
            if(temp[i]==b[j])       
            {
                //if the rollno in b is present in temp then that roll in temp will be initialize -1
                temp[i]=-1;
                break;
            }
        }
        
    }

    
    printf("Students playing only cricket are {  ");
    for ( i = 0; i < nc; i++)
    {
        if (temp[i]!= -1)
        {
            printf("%d  ,",temp[i]);
        }
        
    }
    printf("  }");
    
    
}

void obadminton()           //Student playing only Badminton
{
    int temp[30];
    
    for ( i = 0; i < nb; i++)
    {
        temp[i]=b[i];           //Copying roll of students playing Badminton in temp
    }
    for ( i = 0; i < nb; i++)
    {
        for ( j = 0; j < nc; j++)
        {
            if(temp[i]==c[j])
            {
                //if the rollno in b is present in temp then that roll in temp will be initialize -1
                temp[i]=-1;
                break;
            }
        }
        
    }
    printf("Students playing only Badminton are  {  ");
    for ( i = 0; i < nb; i++)
    {
        if (temp[i]!= -1)
        {
            printf("%d  ,",temp[i]);
        }
        
    }
    printf("  }");
    
    
}

void negitation()           //Negiation
{
    int flag;
    
    printf("Negiation is  {");
    for ( i = 1; i <= 65; i++)      //here i is roll no
    {
        flag=0;                     //initialliy flag is zero
        for ( j = 0; j < nc; j++)       
        {
            if (i==c[j])            //if the roll in cricket is same to i 
            {
                flag=1;             //then flag will be one
                break;
            }
        
        }
        for ( j = 0; j < nb; j++)
        {
            if (i==b[j])            //if the roll in Badminton is same to i 
            {
                flag=1;             //then flag will be one
                break;
            }
            
        }
        if(flag==0)                 //if i doesn't found in any array then flag will be zero
        {                           
            printf("%d  ,",i);      //hence we will print the roll no i.e i
        }        
        
    }
    printf("}");

    
    
}

void menu()                 //Main Menu
{
    int ch;

    
    printf("\n\t MAIN MENU \t\n");
    printf("\n 1. Input Student playing Cricket \n 2. Input Student playing Baminton");
    printf("\n 3. Display Student playing Badminton \n 4. Display Student playing Cricket");
    printf("\n 5. Student Playing both Cricket and Badminton \n 6. Student playing Either Baminton or Cricket");
    printf("\n 7. Negiation\n 8. Students only Playing Cricket\n 9. Student only Playing Badminton");
    printf("\nEnter the choice\n");
    scanf("%d",&ch);
    
    system("clear");

    switch (ch)
    {
    case 1: {
                cinput();
                break;
            }
    case 2: {
                binput();
                break;
            }
    case 3: {
                bdisplay();
                break;
            }
    case 4: {
                cdisplay();
                break;
            }    
    case 5: {
                bcintersection();
                break;
            }
    case 6: {
                bcunion();
                break;
            }
    case 7: {
                negitation();
                break;
            }
    case 8: {
                ocicket();
                break;
            }
    case 9: {
                obadminton();
                break;
            }  
    default:{
                printf("Wrong choice");
                break;
            }
    }
    
    printf("\n\n\n Do you Want to Continue \n1.yes \n0. No\n");
    scanf("%d",&e);
    
}