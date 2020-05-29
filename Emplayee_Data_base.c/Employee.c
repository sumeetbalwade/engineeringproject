#include<stdio.h>                                               //for using standard input output
#include<stdlib.h>                                              //for malloc functions
#include<malloc.h>                                              //for malloc functions

typedef struct Employee                                         //structure for employee
{
    int Registration_Number;                                    //variable for storing registration number of employee
    char Name_of_Employee[20];                                  //variable for storing NAME of employee
    double Salary;                                              //variable for storing SALARY of employee
    char Gender;                                                //variable for storing GENDER of employee

    struct Employee * next_employee;                            //self referencial pointer to the struture
}Employee;                                                      //typedefined the employee

int count=0;                                                    //to keep the track of employee



void show_employee(struct Employee * head);                     //to display all employee
void show_one_employee(struct Employee * head);                 //to display the head or single employee
struct Employee * Create_Employee(struct Employee * head);      //to add new employee
struct Employee * delete_by_RN(struct Employee * head);         //to delete employee
void search_rn(struct Employee * head);                         //to search the employee
void main_menu();                                               //main menu



int main(int argc, char const *argv[])                          //main function
{
    main_menu();                                                //a call to main function
    return 0;
}

void show_employee(struct Employee * head)                      //to display all employee
{
    struct Employee * create;                                   //created a temprary pointer for reference
    create=head;

    system("cls");                                              //for clear screen

    //checking the condition of empty linked list
    if (head==NULL)
    {
        printf("\n\n\n\t THEIR ARE NO EMPLOYEE IN THE DATABASE\n\n");
        system("pause");                                        //for pausing the program
        return;
    }
    
    while (create!=NULL)                                        //to travel till the end of the linked list
    {
        
        //displaying employee details
        printf("\n\t\t\t EMPLOYEE DETAILS \n\n\n\n");
        printf("\n\tREGISTRAION NUMBER : %d",create->Registration_Number);
        printf("\n\tNAME OF THE EMPLOYEE : %s",create->Name_of_Employee);
        printf("\n\tSALARY OF EMPLOYEE : %lf",create->Salary);
        printf("\n\tGENDER M/F : %c",create->Gender);

        //moving to next pointer
        create=create->next_employee;
    }
    
}


void show_one_employee(struct Employee * head)                  //to display the head or single employee
{
    struct Employee * create;                                   //created a temprary pointer for reference
    create=head;

    system("cls");                                              //for clear screen
        
    //displaying employee details
    printf("\n\t\t\t EMPLOYEE DETAILS \n\n\n\n");
    printf("\n\tREGISTRAION NUMBER : %d",create->Registration_Number);
    printf("\n\tNAME OF THE EMPLOYEE : %s",create->Name_of_Employee);
    printf("\n\tSALARY OF EMPLOYEE : %lf",create->Salary);
    printf("\n\tGENDER M/F : %c",create->Gender);

}
    

struct Employee * Create_Employee(struct Employee * head)       //to add new employee
{
    struct Employee * create;                                   //created a temprary pointer for reference
    create=(struct Employee * )malloc(sizeof(Employee));        //allocating the memory using malloc function
    create->next_employee=NULL;                                 //assigning employee next to null
    
    system("cls");                                              //for clear screen

    count++;                                                    //incrementing the number of employee count

    //taking input details of employee
    printf("\n\t\t\t EMPLOYEE REGISTRATION \n\n\n\n");
    printf("Registering Employee Count %d \n\n",count);
    printf("\n\tREGISTRAION NUMBER : ");
    scanf("%d",&create->Registration_Number);

    printf("\n\tNAME OF THE EMPLOYEE : ");
    fflush(stdin);                                              //flush the standard input stream
    scanf("%[^\n]s",create->Name_of_Employee);

    printf("\n\tSALARY OF EMPLOYEE : ");
    scanf("%lf",&create->Salary);
    printf("\n\tGENDER M/F : ");
    fflush(stdin);                                              //flush the standard input stream
    char c;
    c=getchar();
    create->Gender=c;
    

    wc:                                                         //label to be return for wrong choice
    show_employee(create);                                      //displying a single employee
    printf("\n\n\tEnter \n\t1. SAVE \n\t2. BACK\n\t");
    int choice;
    scanf("%d",&choice);

    if (choice==1)                                              //if choice is true delete
    {
        create->next_employee=head;                             //attaching a node at the front end
        head=create;                                            //reassign the head to the first node
        return head;                                            //returning the new address of head
    }
    else if (choice==2)                                         //if choice is 2 it will go back
    {
        free(create);                                           //it free the created node
        return head;                                            //returns the original head
    }
    else
    {
        scanf("\n\n Wrong Choice");
        goto wc;                                                //for wrong choice it will go back to wc lable
    }
    
}


struct Employee * delete_by_RN(struct Employee * head)
{
    int choice,rn;
    int flag=0;
    struct Employee * temp,* q;
    temp=head;
    system("cls");
    if(head==NULL)
    {
        printf("\n\tCANNOT DELETE EMPLOYEE \n");
        system("pause");
        return head;
    }
    else
    {
        printf("\n\t\t\t DELETING BY REGISTRATION NUMBER\n\n\tENTER REGISTRATION NUMBER TO BE DELETED : ");
        
        scanf("%d",&rn);
        
        while (temp!=NULL)
        {
            if (head->Registration_Number==rn)
            {
                wc2:
                show_one_employee(head);
                printf("\n\n\tEnter \n\t1. DELETE \n\t2. BACK\n\t");
                scanf("%d",&choice);
                if (choice==1)
                {
                    q=head;
                    head=head->next_employee;
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
            if ((temp->next_employee)->Registration_Number==rn)
            {
                flag=1;
                break;
            }            
            temp=temp->next_employee;
        }

        if (flag==1)
        {
            wc1:
            show_one_employee(temp->next_employee);
            printf("\n\n\tEnter \n\t1. DELETE \n\t2. BACK\n\t");
            scanf("%d",&choice);
            if (choice==1)
            {
                q=temp->next_employee;
                temp->next_employee=q->next_employee;
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
            printf("\n\n EMPLOYEE WITH REGISTRATION NUMBER %d WAS NOT FOUND !!!",rn);
            system("pause");
            return head;
        }
               
    }
    return head;
    
}

void search_rn(struct Employee * head)                          //to search the employee
{
    int rn; //temporary registration no for search

    system("cls");                                              //for clear screen

    printf("\n\n\t\t\t SEARCHING BY USING REGISTRATION NUMBER");
    printf("\n\n ENTER THE REGISTRATION NUMBER : ");
    scanf("%d",&rn);
    
    //travelling till the last of the linked list
    while (head!=NULL)
    {
        if (head->Registration_Number==rn)                      //finding the match with database registration number
        {
            printf("\n\n DETAILS OF EMPLOYEE \n\n");
            show_one_employee(head);                            //print the details of employee
            printf("\n\n");
            system("pause");                                    //for pausing the system
            return;
        }
        
        head=head->next_employee;                               //assingning head to next employee 
    }
    
    printf("\n\n THE EMPLOYEE WITH GIVEN DETAILS IS NOT PRESENT\n");
    system("pause");
}

void main_menu()
{
    int choice;                                                 //choice variable
    struct Employee * head;                                     //creating herad variable
    head=NULL;                                                  //initalising head 

    while (1)
    {
        system("cls");                                          //for clearing screen

        printf("\n\t\t\t MAIN MENU \n");
        printf(" 1 ADD NEW EMPLOYEE \n 2 DELETE THE EMPLOYEE \n");
        printf(" 3 SEARCH THE EMPLOYEE DETAILS \n 4 DISPLAY ALL EMPLOYEE IN THE DATABASE \n 5 EXIT \n");
        
        printf("\n\n\t ENTER THE CHOICE : ");
        scanf("%d",&choice);

        //switch for comparing the choice
        switch (choice)
        {
        case 1 : {
                        head=Create_Employee(head);
                        break;
                 }
        case 2 : {
                        head=delete_by_RN(head);
                        break;
                 }
        case 3 : {      search_rn(head);
                        break;
                 }
        case 4 : {
                        show_employee(head);
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