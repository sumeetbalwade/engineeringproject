/*
******************************ASSIGNMENT NUMBER B-1 ***********************************

STATEMENT

Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of
Second, third and final year of department can be granted membership on request. Similarly
one may cancel the membership of club. First node is reserved for president of club and last
node is reserved for secretary of club. Write C++ program to maintain club member‘s
information using singly linked list. Store student PRN and Name. 
Write functions to 
1. Add and delete the members as well as president or even secretary.
2. Compute total number of members of club
3. Display members
4. Display list in reverse order using recursion
5. Two linked lists exists for two divisions. Concatenate two lists.

OS - WINDOWS x64
IDE - MICROSOFT VISUAL STUDIO CODE 2019
COMPILER - GNU/MINGW GCC

ASSIGNMENT BY SUMEET BALWADE
GUIDED BY PROF. NIMBALKAR 

*/



#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct member
{
    int prn;
    char name[10];
    struct member *next_member;
}m;

struct member * createmember();
struct member * add_the_member(struct member *president);
void display_the_members(struct member *president);
void display_the_secretory(struct member *president);
void display_the_President(struct member *president);
void total_members(struct member * president);
struct member * concatinate_the_Members(struct member *president,struct member *list);
void print_reverse(struct member * p);
struct member * delete_President(struct member * president);
struct member * delete_Secretary(struct member * president);
struct member * delete_member(struct member * president);
void menu();                                                                    //Main Menu


int main(int argc, char const *argv[])
{
    

    menu();
    
    return 0;
}

struct member * createmember()
{
    struct member *p;
    p=(struct member*)malloc(sizeof(struct member));
    printf("\n Enter the PRN of Member : ");
    scanf("%d",&p->prn);

    printf("\n Enter the Name of the member : ");
    char temp;
    scanf("%c",&temp); // temp statement to clear buffer
	fgets(p->name,10,stdin);

    p->next_member=NULL;

    return p;
}

struct member * add_the_member(struct member *president)
{
    struct member *p;
    p=createmember();

    if (president==NULL)
    {
        president=p;
    }
    else
    {
        p->next_member=president->next_member;
        president->next_member=p;

    }

    return president;    
}

void display_the_members(struct member *president)
{
    if (president==NULL)
    {
        printf("\n Their are no members in the club ");
        return;
    }
    struct member *p;
    p=president;

    printf("\n PRN \t\t\t NAME");
    while (p!=NULL)
    {
        printf("\n %d \t\t\t %s\n",p->prn,p->name);
        p=p->next_member;
    }
    
    
}

void display_the_secretory(struct member *president)
{
    if (president==NULL || president->next_member==NULL)
    {
        printf("\n Their are no secretory in the club ");
        return;
    }
    struct member *p;
    p=president;

    printf("\n The secretory is \n PRN \t\t\t NAME");
    while (p->next_member!=NULL)
    {
        
        p=p->next_member;
    }
    printf("\n %d \t\t\t %s\n",p->prn,p->name);
    
    
}

void display_the_President(struct member *president)
{
    if (president==NULL)
    {
        printf("\n Their are no President in the club ");
        return;
    }
    else
    {
        printf("\n The President is \n PRN \t\t\t NAME");
        printf("\n %d \t\t\t %s\n",president->prn,president->name);
    }

    
    
}

void total_members(struct member * president)
{
    int count=0;
    struct member *q;
    q=president;

    while (q!=NULL)
    {
        count++;
        q=q->next_member;
    }

    printf("\n\n\n The Total number of Members are : %d\n\n",count);
    


}

struct member * concatinate_the_Members(struct member *president,struct member *list)
{
    struct member * p;
    p=president;
    while (p->next_member!=NULL)
    {
        p=p->next_member;
    }
    p->next_member=list;

    return president;
}


void print_reverse(struct member * p)
{
    if (p==NULL)
    {
        printf("The are No Members in Pinnacle Club ");
        return;
    }    
    else if (p->next_member!=NULL)
    {
        print_reverse(p->next_member);
    }

    if (p->next_member==NULL)
    {
        printf("\n PRN \t\t\t NAME");
    }    

    printf("\n %d \t\t\t %s\n",p->prn,p->name);
       
        
}

struct member * delete_President(struct member * president)
{
    struct member * p;
    if (president==NULL)
    {
        printf("Their are no Member in the club");
        
    }
    else
    {
        p=president;
        president=president->next_member;
        free(p);
        printf("\n\n PRESIDENT IS DELETED\n");
    }

    return president;    
    
}

struct member * delete_Secretary(struct member * president)
{
    struct member * p,*q;
    if (president==NULL)
    {
        printf("Their are no Member in the club");
        
    }
    else
    {
        q=president;
        while (q->next_member->next_member!=NULL)
        {
            q=q->next_member;
        }

        p=q->next_member;
        q->next_member=NULL;
        
        free(p);
        printf("\n\n SECRETARY IS DELETED\n");
    }

    return president;    
    
}

struct member * delete_member(struct member * president)
{
    int data;
    struct member * p,*q;
    if (president==NULL)
    {
        printf("\n Their are no members in Pinnacle CLub \n");
    }
    else
    {
        printf("\n\n Secretary and President cannot be deleted here plz use other option \n\n Enter the PRN of The Member for Deletion\n");
        scanf("%d",&data);
        p=president;
        while (p->next_member->prn!=data && p->next_member!=NULL)
        {
            p=p->next_member;
        }

        if (p->next_member!=NULL)
        {
            q=p->next_member;
            p->next_member=q->next_member;
            free(q);
            
            printf("\n\n Deleting the Member %d ",p->prn);


        }
        else
        {
            printf("\n\n The Member is not Found");
        }
        
        
    }

    return president;
    
    
}


void menu()                 //Main Menu
{
    int ch,e;
    struct member *president,*list;
    president=NULL;
    list=NULL;
    do
    {
        printf("\n\t MAIN MENU \t\n");
        printf("\n 1. Insert the node \n 2. Display All the Members");
        printf("\n 3. Display President \n 4. Display the secretory");
        printf("\n 5. Total Members are \n 6. Insert node in Second list ");
        printf("\n 7. Display Second List \n 8. Concatinate list one and two \n 9. Display list in reverse order using recursion");
        printf("\n 10. Delete President \n 11. Delete Secretory \n 12. Delete Members");
        printf("\nEnter the choice\n");
        scanf("%d",&ch);
        


        switch (ch)
        {
        case 1: {
                    president=add_the_member(president);
                    break;
                }
        case 2: {
                    display_the_members(president);
                    break;
                }
        case 3: {
                    display_the_President(president);
                    break;
                }
        case 4: {
                    display_the_secretory(president);
                    break;
                } 
        case 5: {
                    total_members(president);
                    break;
                }
        case 6: {
                    list=add_the_member(list);
                    break;
                }
        case 7: {
                    display_the_members(list);
                    break;
                } 
        case 8: {
                    president=concatinate_the_Members(president,list);
                    break;
                }
        case 9: {
                    print_reverse(president);
                    break;
                }  
        case 10: {
                    president=delete_President(president);
                    break;
                }  
        case 11: {
                    president=delete_Secretary(president);
                    break;
                } 
        case 12: {
                    president=delete_member(president);
                    break;
                } 

        default:{
                    printf("Wrong choice");
                    break;
                }
        }
        
        printf("\n\n\n Do you Want to Continue \n1.yes \n0. No\n");
        scanf("%d",&e);


    } while (e==1);
    

    
}