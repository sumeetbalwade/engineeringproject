#include<stdio.h>
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

void complete_parantisise()
{
    int i;
    char expression[30];
    stack p;
    initialaise(&p);
    printf("\n\n\t ENTER THE EXPRESSION : ");
    fflush(stdin);
    scanf("%[^\n]s",expression);

    for ( i = 0; expression[i]!='\0'; i++)
    {
        if (expression[i]=='(')
        {
            push(&p,'(');
        }
        else if (expression[i]==')')
        {
            if (!isempty(&p))
            {
                pop(&p);
            }
            else
            {
                printf("\n\n\t MISSMATCH \n\n");
                return;
            }
            
        }     
        
    }
    if (isempty(&p))
    {
        printf("\n\n\t COMPLETE PARANTANSISED \n");

    }
    else
    {
        printf("\n\n\t MISSMATCHED");
    }
    
    
    
}

int main(int argc, char const *argv[])
{
    

    complete_parantisise();    
    return 0;
}
