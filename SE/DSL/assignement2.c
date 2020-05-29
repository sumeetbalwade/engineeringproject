#include<stdio.h>
#define clear() printf("\033[H\033[J")


int b[50],c[50];
int nc,nb,i,j,e=0,check;

void bdisplay()
{
    printf("\n Student playing Badminton are  \n {");
    for ( i = 0; i < nb; i++)
    {
        printf("%d  ,",b[i]);
    }
    printf("}");
}

void cdisplay()
{
    printf("\n Student playing cricket are  \n {");
    for ( i = 0; i < nc; i++)
    {
        printf("%d  ,",c[i]);
    }
    printf("}");
}

void binput()
{
    printf("\n Enter number of roll no playing badminton \n");
    scanf("%d",&nb);

    printf("Enter their Roll no \n");
    for ( i = 0; i < nb; i++)
    {
        scanf("%d",&b[i]);
    }
}

void cinput()
{
    printf("\n Enter the number of roll no playing cricket\n");
    scanf("%d",&nc);


    printf("Enter their Roll no \n");
    for ( i = 0; i < nc; i++)
    {
        scanf("%d",&c[i]);
    }
}

void bcintersection()
{
    for ( i = 0; i < nb;i++) 
    {
        for ( j = 0; j < nc; j++)
        {
            if (b[i]==c[j])
            {
                printf("%d  ,",b[i]);
            }
            
        }
        
    }
    
}
void bcunion()
{   int u[100],flag;
    int nu=nc;
   
    for ( i = 0; i < nc; i++)
    {
        u[i]=c[i];
    }
    
    for ( i = 0; i < nb; i++)
    {
        flag=0;
        for ( j = 0; j < nc; j++)
        {
            if (u[j]==b[i])
            {
                flag=1;
            }
            
            
        }
        if (flag==0)
        {
            
            u[nu]=b[i];
            nu++;
        }
        
    }

    printf("\n The UNION is {");
    for ( i = 0; i < nu; i++)
    {
        printf("%d  ,",u[i]);
    }
    printf("}");
    
}

void ocicket()
{
    int temp[30];
    
    for ( i = 0; i < nc; i++)
    {
        temp[i]=c[i];
    }
    for ( i = 0; i < nc; i++)
    {
        for ( j = 0; j < nb; j++)
        {
            if(temp[i]==b[j])
            {
                temp[i]=-1;
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



void obadminton()
{
    int temp[30];
    
    for ( i = 0; i < nb; i++)
    {
        temp[i]=b[i];
    }
    for ( i = 0; i < nb; i++)
    {
        for ( j = 0; j < nc; j++)
        {
            if(temp[i]==c[j])
            {
                temp[i]=-1;
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



void negitation()
{
    int flag;
    
    printf("Negiation is  {");
    for ( i = 1; i <= 65; i++)
    {
        flag=0;
        for ( j = 0; j < nc; j++)
        {
            if (i==c[j])
            {
                flag=1;
            }
        
        }
        for ( j = 0; j < nb; j++)
        {
            if (i==b[j])
            {
                flag=1;
            }
            
        }
        if(flag==0)
        {
            printf("%d  ,",i);
        }        
        
    }
    printf("}");

    
    
}

void menu()
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





int main()
{
    
    do
    {
        clear();
        menu();
    } while (e==1);
    


    
    

    return 0;

    
   
}