/*
******************************ASSIGNMENT NUMBER B-3 ***********************************

STATEMENT

20. Let x = (x1,x2, … , xn) and y = (y 1, y2,…. , ym) be two doubly linked lists. Assume that in
each linked list, the nodes are in non-decreasing order of their data-field values. Write
C/C++ program to merge the two lists to obtain a new linked list z in which the nodes are
also in this order. Following the merge, x and y should represent empty lists because each
node initially in x or y is now in z. No additional nodes may be used

OS - WINDOWS x64
IDE - MICROSOFT VISUAL STUDIO CODE 2019
COMPILER - GNU/MINGW GCC

ASSIGNMENT BY SUMEET BALWADE
GUIDED BY PROF. NIMBALKAR

*/





#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct dlinklist
{
    int data;
    struct dlinklist * next,* previous;
}dlinklist;

dlinklist * create(int x)
{
    dlinklist *p=(dlinklist *)malloc(sizeof(dlinklist));
    p->data=x;
    p->next=NULL;
    p->previous=NULL;
    return p;
}
dlinklist * insert(dlinklist * d,int data)
{
    dlinklist *q,*p;
    p=create(data);

    if (d==NULL)
    {
        d=p;
    }
    else
    {
        q=d;
        while (q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
        p->previous=q;

    }

    return d;

}

dlinklist * merge(dlinklist *d,dlinklist *q)
{
    dlinklist *head;
    head=NULL;
    while (d!=NULL && q!=NULL)
    {
        if (d->data < q->data)
        {
            head=insert(head,d->data);
            d=d->next;
        }
        else
        {
            head=insert(head,q->data);
            q=q->next;
        }
    }
    while (d!=NULL)
    {
        head=insert(head,d->data);
        d=d->next;
    }
    while (q!=NULL)
    {
        head=insert(head,q->data);
        q=q->next;
    }

    return head;

}


void display(dlinklist *d)
{
    while (d!=NULL)
    {
            printf("\n\n THE VALUE IS : %d",d->data);
            d=d->next;
    }

}
int main(int argc, char const *argv[])
{
    dlinklist *vhead,*bhead,*head;
    bhead=vhead=head=NULL;
    int i,x;
    printf("\nENTER the values\n\t ");
    for ( i = 0; i < 5; i++)
    {
        scanf("%d",&x);
        vhead=insert(vhead,x);
    }
    display(vhead);
    for ( i = 0; i < 5; i++)
    {
        scanf("%d",&x);
        bhead=insert(bhead,x);
    }
    display(bhead);
    head=merge(bhead,vhead);

    display(head);



    return 0;
}
