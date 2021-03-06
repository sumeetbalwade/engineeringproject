#include<stdio.h>
#include<ctype.h>
#define MAX 20

typedef struct stack
{
    char data[MAX];
    int top;
}stack;

void initialaise(stack * p)
{
    p->top=-1;
}

int isempty(stack * p)
{
    if (p->top==-1)
    {
        return 1;
    }
    return 0;

}

int isfull(stack * p)
{
    if (p->top==MAX-1)
    {
        return 1;
    }
    return 0;

}

void push(stack * p,char x)
{
    if (!isfull(p))
    {
        p->data[++p->top]=x;
    }

}

char pop(stack * p)
{
    char x;
    if (!isempty(p))
    {
        x=p->data[p->top];
        p->top--;
        //printf("%d",x);
        return x;
    }


}
void print(char str[])
{
    int i;
    for ( i = 0; str[i] != '\0'; i++)
    {
        printf("%c",str[i]);  
        
    }
}


void pallendrome(char str[])
{
    stack s;
    initialaise(&s);
    char temp[MAX],x;
    int i=0;
    
    while ((x=str[i])!='\0')
    {
        push(&s,x);
        i++;
    }

    
    for ( i = 0; str[i] != '\0'; i++)
    {
        x=pop(&s);
        if (str[i]!=x)
        {
            printf("\n\n THE STRING IS NOT A PALLENDROME \n\n");
            return;
        }       
        
    }
    
    printf("\n\n THE STRING IS A PALLENDROME \n\n"); 
    
}

void convert(char str[])
{
    char temp[MAX];
    int i,j=0;
    char x;
    
    for ( i = 0; str[i] != '\0'; i++)
    {
        x=str[i];
        
        if (isalpha(x))
        {
            if (isupper(x))
            {
                x=tolower(x);
                temp[j]=x;
                j++;
            }
            else
            {
                temp[j]=x;
                j++;
            }
  
        }
    } 
    temp[j]='\0';

    pallendrome(temp);
       
}

void print_reverse(char str[])
{
    stack s;
    initialaise(&s);
    int i;
    for ( i = 0; str[i] !='\0'; i++)
    {
        push(&s,str[i]);
    }

    printf("\n\n THE REVERSE STRING IS : ");
    while (!isempty(&s))
    {
        printf("%c",pop(&s));
    }
    
}

void menu()
{
    char str[MAX];
    char x;
    int i,choice;    

    while (1)
    {
        printf("\n\n\n\t\t\t MAIN MENU");
        printf("\n\n\t 1. ENTER THE STRING");
        printf("\n\t 2. CHECK THE PALLENDROME OF STRING");
        printf("\n\t 3. REVERSE PRINT THE STRING");
        printf("\n\t 4. EXIT");
        printf("\n\n\t ENTER YOUR CHOICE : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: {
                    i=0;
                    
                    printf("\n\n enter the string\n");
                    fflush(stdin);
                    while ((x=getchar())!='\n')
                    {
                        str[i]=x;
                        i++;
                    }
                    str[i]='\0';
                    break;
                }

        case 2: {
                    convert(str);
                    break;
                }
        case 3: {
                    print_reverse(str);
                    break;
                }
        case 4: {
                    return;
                    break;
                }
        default:
            break;
        }

    }
}

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}
