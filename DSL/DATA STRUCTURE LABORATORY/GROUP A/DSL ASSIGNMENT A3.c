
#include <stdio.h>
#define clear() printf("\033[H\033[J")     //clear screen
#define MAX 50

int lenstr(char str[])
{   
    int i;
    for(i=0;str[i]!='\0';i++);
    return i;
}

void cpystr(char str[],char a[])
{
    int i;
    for ( i = 0; a[i] !='\0'; i++)
    {
        str[i]=a[i];
    }
    str[i]='\0';

}




void revstr(char arr[])
{
	
    int i=0,j=0;
	char temp;
	int length =lenstr(arr);
	for(i=0,j=length;(i==j)||(i>j);i++,j--)
	{
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
 
	
}

void constr(char str[],char a[])
{
    int i=lenstr(str);
    int j;
    for ( j=0; a[j]!='\0' ; j++)
    {
        str[i]=a[j];
        i++;
    }    

}
void string_pallendrom(char arr[],int length)
{
	int i=0,j=0;
	
	for(i=0,j=length;(i==j)||(i>j);i++,j--)
	{
		if(arr[i]==arr[j])
		{
			
		}
		else
		{
		    break;
		}
	}
	
	if(i<j)
	{
		printf("\nNot a Pallendrom\n");

	}
	else
	{
		printf("\n a Pallendrom\n");
	}

}

void instr(char str[])
{
    char ch1;
    int i=0;
    while ((ch1=getchar())!='\n')
    {
        str[i]=ch1;
        i++;
    }
    str[i]='\0';
    
}
void inpstr(char str[],char a[])
{
    
    printf("Enter First String ");
    char temp;
    scanf("%c",&temp); // temp statement to clear buffer
	fgets(str,50,stdin);
    printf("Enter Second Stirng ");
    fgets(a,50,stdin);
    

}

void display(char str[],char a[])
{
    
    printf("First String \n%s",str);
    printf("\n Second Stirng\n%s",a);//scanf("%c",&temp); // temp statement to clear buffer
   
}


void main()
{
    char str[50],a[50];
    int choice,l,c;
    char k;
    do
    {
       
        printf("\t\t\t MAIN MENU \n 1. Input String \n 2. Display \n 3. Length of String\n ");
        printf("4. Copy String \n 5. Reverse String\n 6. Concat the String\n 7. Pallindrom of String\n");
        printf(" 8. Exit\nEnter Your Choice ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: {
                    inpstr(str,a);
                    break;
                }
            
        case 2: {
                    display(str,a);
                    
                    break;
                }
        case 3: {
                    
                    l=lenstr(str);
                    printf("Length of string one is %d\n",l);
                    l=lenstr(a);
                    printf("Length of string Two is %d\n",l);
                    break;
                }
        case 4: {
                    printf("\n String Before Copy is \n%s",str);
                    cpystr(str,a);                    
                    printf("\n String After Copy is \n%s",str);
                    break;
                }
        case 5: {
                    printf("\n String Before Reversing is \n%s",str);
                    revstr(str);
                    printf("\n String After Reversing is \n%s",str);
                    break;
                }
        case 6: {
                    printf("\n String Before Concatination is \n%s",str);
                    constr(str,a);
                    printf("\n String After Concatination is \n%s",str);
                    break;
                }
        case 7: {
                    l=lenstr(str);
                    string_pallendrom(str,l);
                    break;
                }
        case 8: {
                    return;
                    break;
                }
        
        default: {
                    printf("\nWrong Choice\n");
                    break;
                }
            
        }
        
        

        
        
    } while (1);
    



}
