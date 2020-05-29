

#include<stdio.h>
#define MAX 20


typedef struct queue
{
    int data[MAX];
    int front,rear;
}queue;

void init(queue * q)
{
    q->front=q->rear=-1;
}

int isempty(queue *q)
{
    if (q->rear==-1)
    {
        return 1;
    }
    return 0;
}

int isfull(queue *q)
{
    if (q->rear==MAX-1)
    {
        return 1;
    }
    return 0;
    
}

void enqueue_rear(queue *q , int x)
{
    if (!isfull(q))
    {
        if (isempty(q))
        {
            q->rear=q->front=0;
            q->data[q->rear]=x;
        }
        else
        {
            q->data[++q->rear]=x;
        }        
        
    }
    
}

int dequeue_front(queue *q)
{
    int x;
    if (!isempty(q))
    {
        if (q->rear==q->front)
        {
            x=q->data[q->front];
            init(q);
        }
        else
        {
            x=q->data[q->front++];
        }

        return x;    
    }
    
}

void enqueue_front(queue *q,int x)
{
    if (q->front>0)
    {
        q->data[--q->front]=x;
    }else if (isempty(q))
    {
        enqueue_rear(q,x);
    }    
    else
    {
        printf("\n\n\n\t CANNOT INSERT AT FRONT \n");
    }
    
    
}

int dequeue_rear(queue *q)
{
    int x;
    if (!isempty(q))
    {
        if (q->rear==q->front)
        {
            x=q->data[q->front];
            init(q);
        }
        else
        {
            x=q->data[q->rear--];
        }

        return x;    
    }
    

}

void display(queue *q)
{
    int i;
    printf("\n\n\t THE ELEMENTS ARE : ");
    for ( i = q->front; i <= q->rear; i++)
    {
        printf("%d  ",q->data[i]);
    }
    
}


void menu()
{
    queue q;
    int choice,x;
    init(&q);
    while (1)
    {
        
        printf("\n\n\t\t MAIN MENU");
        printf("\n\n 1. DELETE AT FRONT");
        printf("\n\n 2. INSERT AT REAR");
        printf("\n\n 3. IS FULL");
        printf("\n\n 4. IS EMPLTY");
        printf("\n\n 5. DISPLAY");
        printf("\n\n 6. INSERT AT FRONT");
        printf("\n\n 7. DELETE AT REAR");
        printf("\n\n 8. EXIT");
        printf("\n\n\n\n\t\t ENTER THE CHOICE : ");
        scanf("%d",&choice);

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
        case 9: {
                    return;
                    break;
                }
        case 5: {
                    display(&q);
                    break;

                }
        case 6: {
                    
                    printf("\n\n\t ENTER THE NUMBER TO INSERTED : ");
                    scanf("%d",&x);
                    enqueue_front(&q,x);
                    break;
                }
        case 7: {
                    if (!isempty(&q))
                    {
                        x=dequeue_rear(&q);
                        printf("\n\n\t THE NUMBER DELETED IS : %d",x);
                    }
                    else
                    {
                        printf("\n\n\t CANNOT BE DELETED ");
                    }
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

