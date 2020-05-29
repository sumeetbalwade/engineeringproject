#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct book
{
    int b_no;
    char b_name[20];
    float b_price;
    int b_quantity;
    struct book * next;
}book;



struct book * insert_book(struct book * head)
{
    struct book *p;
    p=(struct book *) malloc(sizeof(book));
    p->next=NULL;
    printf("\n\t\t\t BOOK REGISTRATION \n\n\n\n");
    printf("\n\tBOOK NUMBER : ");
    scanf("%d",&p->b_no);

    printf("\n\tNAME OF THE BOOK : ");
    fflush(stdin);                                              //flush the standard input stream
    scanf("%[^\n]s",p->b_name);

    printf("\n\tPRICE OF THE BOOK : ");
    scanf("%f",&p->b_price);

    printf("\n\tQUANTITY OF BOOKS : ");
    scanf("%d",&p->b_quantity);


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

void display_books(struct book * head)
{
    while (head!=NULL)
    {
        printf("\n\tBOOK NUMBER : %d",head->b_no);
        printf("\n\tNAME OF THE BOOK : %s",head->b_name);
        printf("\n\tPRICE OF THE BOOK : %f",head->b_price);
        printf("\n\tQUANTITY OF BOOKS : %d",head->b_quantity);
    
        head=head->next;      
    }
    
}

void display_one_book(struct book * head)
{
    printf("\n\tBOOK NUMBER : %d",head->b_no);
    printf("\n\tNAME OF THE BOOK : %s",head->b_name);
    printf("\n\tPRICE OF THE BOOK : %f",head->b_price);
    printf("\n\tQUANTITY OF BOOKS : %d",head->b_quantity);
    
}

struct book * delete_book(struct book * head)
{
    int choice,rn;
    int flag=0;
    struct book * temp,* q;
    temp=head;
    if(head==NULL)
    {
        printf("\n\tCANNOT DELETE EMPLOYEE \n");
        system("pause");
        return head;
    }
    else
    {
        printf("\n\t\t\t DELETING BY BOOK NUMBER\n\n\tENTER BOOK NUMBER TO BE DELETED : ");
        
        scanf("%d",&rn);
        
        while (temp!=NULL)
        {
            if (head->b_no==rn)
            {
                wc2:
                display_one_book(head);
                printf("\n\n\tEnter \n\t1. DELETE \n\t2. BACK\n\t");
                scanf("%d",&choice);
                if (choice==1)
                {
                    q=head;
                    head=head->next;
                    free(q);
                    return head;
                }
                else if (choice==2)
                {
                    return head;
                }
                else
                {
                    scanf("\n\n Wrong Choice");
                    goto wc2;
                } 
            }
            if ((temp->next)->b_no==rn)
            {
                flag=1;
                break;
            }            
            temp=temp->next;
        }

        if (flag==1)
        {
            wc1:
            display_one_book(temp->next);
            printf("\n\n\tEnter \n\t1. DELETE \n\t2. BACK\n\t");
            scanf("%d",&choice);
            if (choice==1)
            {
                q=temp->next;
                temp->next=q->next;
                free(q);
                return head;
            }
            else if (choice==2)
            {
                return head;
            }
            else
            {
                scanf("\n\n Wrong Choice");
                goto wc1;
            }            
        }
        else
        {
            printf("\n\n BOOK WITH REGISTRATION NUMBER %d WAS NOT FOUND !!!",rn);
            system("pause");
            return head;
        }
               
    }
    return head;
}


void search_bn(struct book * head)                          //to search the employee
{
    int rn; //temporary registration no for search

    system("cls");                                              //for clear screen

    printf("\n\n\t\t\t SEARCHING BY USING BOOK NUMBER");
    printf("\n\n ENTER THE BOOK NUMBER : ");
    scanf("%d",&rn);
    
    //travelling till the last of the linked list
    while (head!=NULL)
    {
        if (head->b_no==rn)                      //finding the match with database registration number
        {
            printf("\n\n DETAILS OF BOOK \n\n");
            display_one_book(head);                           //print the details of employee
            printf("\n\n");
            system("pause");                                    //for pausing the system
            return;
        }
        
        head=head->next;                               //assingning head to next employee 
    }
    
    printf("\n\n THE BOOK WITH GIVEN DETAILS IS NOT PRESENT\n");
    system("pause");
}

void menu()
{
    struct book * head;
    head=NULL;
    int choice; 
    while (1)
    {
        system("cls");
        printf("\n\t\t\t MAIN MENU \n");
        printf(" 1 ADD NEW BOOK \n 2 DELETE THE BOOK \n");
        printf(" 3 SEARCH THE BOOK DETAILS \n 4 DISPLAY ALL BOOK IN THE DATABASE \n 5 EXIT \n");
        
        printf("\n\n\t ENTER THE CHOICE : ");
        scanf("%d",&choice);

        //switch for comparing the choice
        switch (choice)
        {
        case 1 : {
                        head=insert_book(head);
                        break;
                 }
        case 2 : {
                        head=delete_book(head);
                        break;
                 }
        case 3 : {      search_bn(head);
                        break;
                 }
        case 4 : {
                        display_books(head);
                        printf("\n\n\n\n\n");
                        system("pause");
                        break;
                 }
        case 5 : {
                        return;
                        break;
                 }
        
        default: {
                        printf("\n\n WRONG CHOICE \n\n");
                        system("pause");
                        break;
                }
            
        }
        
    }
    
}


int main(int argc, char const *argv[])
{
    menu();
    return 0;
}
