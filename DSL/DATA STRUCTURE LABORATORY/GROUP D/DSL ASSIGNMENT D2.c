
#include<stdio.h>
#define MAX 20                      //set the size


typedef struct queue                //structure for circular queue
{
    int data[MAX];                  //array for storing data
    int front,rear;                 //keeping track of queue
}queue;

void init(queue * q)                //function for initialising queue
{
    //set front and rear to -1 for initialisation
    q->front=q->rear=-1;            
}

int isempty(queue *q)               //fuction for checking queue empty or not
{
    //checking rear to -1
    if (q->rear==-1)                
    {
        return 1;
    }
    return 0;
}

int isfull(queue *q)                //fuction for checking queue full or not
{
    //checking rear next should to front
    if (q->front==(q->rear+1)%MAX)
    {
        return 1;
    }
    return 0;
    
}

void enqueue_rear(queue *q , int x)         //fuction for inserting in the queue
{
    //check if queue is full if full then not able to insert
    if (!isfull(q))
    {
        //if empty increment front and rear
        if (isempty(q))
        {
            //setting front, rear to 0 i.e. increment from -1 to 0
            q->rear=q->front=0;

            //inserting element at rear
            q->data[q->rear]=x;
        }
        else
        {
            //incrementing the rear in circular way
            q->rear=(q->rear+1)%MAX;
            //inserting element at rear
            q->data[q->rear]=x;
        }        
        
    }
    
}

int dequeue_front(queue *q)                 //function for deleting the element
{
    int x;   //x to store the element      

    //delete possible if queue is not empty     
    if (!isempty(q))
    {
        //checking if rear and front are same i.e. single element is present
        if (q->rear==q->front)
        {
            //taking the value in x
            x=q->data[q->front];

            //deleting the single element from queue i.e. initialising queue
            init(q);
        }
        else
        {
            //taking the value in x
            x=q->data[q->front];
            //incrementing the front for deleting the queue
            q->front=(q->front+1)%MAX;
        }

        return x;    
    }
    
}



void display(queue *q)                  //function for displaying the queue
{
    int i;     //variable for travelling the location
    printf("\n\n\t THE ELEMENTS ARE : ");

    //setting i to front incrementing in a circular way till i is not equal to next to rear
    for ( i = q->front; i != (q->rear+1)%MAX; i=(i+1)%MAX)
    {
        //displaying the data
        printf("%d  ",q->data[i]);
    }
    
}


void menu()                             //function for displaying the menu
{
    queue q;                //creating the object of queue
    int choice,x;           //variable for choice and temprary
    init(&q);               //initally initialising the queue
    while (1)               //running loop infinitly
    {
        system("cls");      //clearing the screen

        //printing menu

        printf("\n\n\t\t MAIN MENU");
        printf("\n\n 1. DELETE AT FRONT");
        printf("\n\n 2. INSERT AT REAR");
        printf("\n\n 3. IS FULL");
        printf("\n\n 4. IS EMPLTY");
        printf("\n\n 5. DISPLAY");
        printf("\n\n 6. EXIT");
        printf("\n\n\n\n\t\t ENTER THE CHOICE : ");
        scanf("%d",&choice);            //taking the choice

        //checking the choice
        switch (choice)
        {   
        case 1: {
                    
                    if (!isempty(&q))
                    {
                        x=dequeue_front(&q);
                        printf("\n\n\t THE NUMBER DELETED IS : %d",x);
                    }
                    else
                    {
                        printf("\n\n\t CANNOT BE DELETED ");
                    }
                    break;
                }
        case 2: {
                    printf("\n\n\t ENTER THE NUMBER TO INSERTED : ");
                    scanf("%d",&x);
                    enqueue_rear(&q,x);
                    break;
                }
        case 3: {
                    if (isfull(&q))
                    {
                        printf("\n\n THE QUEUE IS FULL");
                    }
                    else
                    {
                        printf("\n\n THE QUEUE IS NOT FULL");
                    }
                    break;
                }
        case 4: {
                    if (isempty(&q))
                    {
                        printf("\n\n THE QUEUE IS EMPTY");
                    }
                    else
                    {
                        printf("\n\n THE QUEUE IS NOT EMPTY");
                    }
                    break;
                }
        case 6: {
                    return;     //return from function to exit
                    break;
                }
        case 5: {
                    display(&q);
                    break;

                }
       
        default:
            break;
        }
    }
    
}


int main(int argc, char const *argv[])
{
    menu();     //calling menu function
    return 0;
}

