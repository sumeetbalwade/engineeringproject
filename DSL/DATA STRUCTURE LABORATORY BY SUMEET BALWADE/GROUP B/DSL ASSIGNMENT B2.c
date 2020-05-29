/*
******************************ASSIGNMENT NUMBER B-2 ***********************************

STATEMENT

Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B
of students like butterscotch ice-cream. Write C/C++ program to store two sets using linked
list. compute and display-
i. Set of students who like either vanilla or butterscotch or both
ii. Set of students who like both vanilla and butterscotch
iii. Set of students who like only vanilla not butterscotch
iv. Set of students who like only butterscotch not vanilla
v. Number of students who like neither vanilla nor butterscotch

OS - WINDOWS x64
IDE - MICROSOFT VISUAL STUDIO CODE 2019
COMPILER - GNU/MINGW GCC

ASSIGNMENT BY SUMEET BALWADE
GUIDED BY PROF. NIMBALKAR 

*/


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct icecream
{
    int roll_no;
    struct icecream *next;
}icecream;

void display_student(struct icecream * head)
{
    struct icecream * p;
    p=head;
    
    printf("\n\n\t THE ROLL NO ARE \n");
    while (p!=NULL)
    {
        printf("\n\n\t%d",p->roll_no);
        p=p->next;
    }
    
}

struct icecream * new(struct icecream * head,int x)
{
    struct icecream * p;

    p=(struct icecream *)malloc(sizeof(icecream));
    p->roll_no=x;
    p->next=NULL;

    if (head==NULL)
    {
        head=p;
    }
    else
    {
        p->next=head;
        head=p;
    }
    
    return head;
}

void intersection(struct icecream * head,struct icecream * link)
{
    struct icecream * int_result,* temp;
    temp=link;
    
    int_result=NULL;
    while (head!=NULL)
    {
        link=temp;
        while (link!=NULL)
        {
            if (head->roll_no==link->roll_no)
            {
                int_result=new(int_result,link->roll_no);
            }
            link=link->next;
        }
        head=head->next;
    }

    display_student(int_result);
    
}


void union_set(struct icecream * head,struct icecream * link)
{
    struct icecream * union_result,* temp, *q, *p;
    int flag;
    union_result=NULL;
    temp=head;
    while (temp!=NULL)
    {
        union_result=new(union_result,temp->roll_no);
        temp=temp->next;
    }

    q=link;
    p=head;
    while (q!=NULL)
    {
        flag=0;
        p=head;
        while (p!=NULL)
        {
            if (p->roll_no==q->roll_no)
            {
               flag=1;
               break;
            }
            p=p->next;
        }
        if (flag==0)
        {
            union_result=new(union_result,q->roll_no);
        }
        q=q->next;
    }
    
    display_student(union_result);
    
    
}

struct icecream * add_student(struct icecream * head)
{
    struct icecream * p;
    int roll;

    p=(struct icecream *)malloc(sizeof(icecream));
    p->next=NULL;

    printf("\n\n\t Enter the rollno of student : ");
    scanf("%d",&p->roll_no);

    if (head==NULL)
    {
        head=p;
    }
    else
    {
        p->next=head;
        head=p;
    }
    
    return head;
}


void only_one(struct icecream * head,struct icecream * link)
{
    struct icecream * t, * p;
    t=head;
    
    printf("\n\n\t THE ROLL NO ARE \n");
    while (t!=NULL)
    {
        p=link;
        while (p!=NULL && t->roll_no!=p->roll_no)
        {
            p=p->next;
        }
        if (p==NULL)
        {
            printf("\n\n\t%d",t->roll_no);
        }
        
        t=t->next;
    }
    

    

}

void nither_vanilla_nor_butterscotch(struct icecream *head,struct icecream *link)
{
    struct icecream *p,*q;
    int i=1,flag=0;
    printf("\n\n\t THE ROLL NUMBER ARE \n");
    for ( i = 1; i <= 10; i++)
    {
        flag=0;
        p=head;
        while (p!=NULL)
        {
            if (p->roll_no==i)
            {
                flag=1;
                break;
            }
            p=p->next;
        }
        q=link;
        while (q!=NULL)
        {
            if (q->roll_no==i)
            {
                flag=1;
                break;
            }
            q=q->next;
            
        }
        if (flag==0)
        {
            printf("\n %d",i);
        }
        
               
    }
    

}

void menu()
{
    struct icecream * vanilla,* butterscotch;
    vanilla=butterscotch=NULL;

    int choice;

    while (1)
    {
        printf("\n\n\t\t\t MAIN MENU");

        printf("\n\n\t 1. Add student in Vanilla");
        printf("\n\t 2. Add student in Butterscotch");
        printf("\n\t 3. Display student in Vanilla");
        printf("\n\t 4. Display student in Butterscotch");
        printf("\n\t 5. Set of students who like either vanilla or butterscotch or both ");
        printf("\n\t 6. Set of students who like both vanilla and butterscotch");
        printf("\n\t 7. Set of students who like only vanilla not butterscotch");
        printf("\n\t 8. Set of students who like only butterscotch not vanilla");
        printf("\n\t 9. Number of students who like neither vanilla nor butterscotch");
        printf("\n\t 10. EXIT");
        printf("\n\n\t Enter the choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:{
                        vanilla=add_student(vanilla);
                        break;

                    }
            case 2:{
                        butterscotch=add_student(butterscotch);
                        break;

                    }
            case 3:{
                        display_student(vanilla);
                        break;

                    }
            case 4:{
                        display_student(butterscotch);
                        break;

                    }
            case 5:{
                        union_set(vanilla,butterscotch);
                        break;
                    }
            case 6:{
                        intersection(vanilla,butterscotch);
                        break;
                    }
            case 7: {
                        only_one(vanilla,butterscotch);
                        break;
                    }
            case 8: {
                        only_one(butterscotch,vanilla);
                        break;
                    }
            case 9: {
                        nither_vanilla_nor_butterscotch(vanilla,butterscotch);
                        break;
                    }
            case 10:{
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
