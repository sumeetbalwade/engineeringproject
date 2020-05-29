#include<stdio.h>


void bubble_sort(int a[],int size)
{
    int temp,i,j;


    for ( i = 0; i < size-1; i++)
    {
        for ( j = 0; j < size-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;   
            }
            
        }
        
    }
    
}

void selectionsort(int a[],int size)
{
    int i,j,min;
    int temp;

    for ( i = 0; i < size-1; i++)
    {
        min=i;

        for ( j = i+1; j < size; j++)
        {
            if (a[j]<a[min])
            {
                min=j;
            }
            
        }
        if (i!=min)
        {
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
        
        
    }
    

}


int partition(int a[],int l,int h)
{
    int p,i,j,temp;
    p=l;
    i=l;
    j=h;


    while (i<j)
    {
        while (a[i]<=a[p])
        {
            i++;
        }

        while (a[j]>a[p])
        {
            j--;
        }

        if (i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }        
    }
    if (i>=j)
    {
        temp=a[p];
        a[p]=a[j];
        a[j]=temp;
    }

    return j;
}

void quicksort(int a[],int l,int h)
{
    int loc;
    if (l<h)
    {
        loc=partition(a,l,h);
        quicksort(a,l,loc-1);
        quicksort(a,loc+1,h);
    }
    
}

int main(int argc, char const *argv[])
{
    int a[10];
    int i;
    for ( i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }
    
    bubble_sort(a,5);

    for ( i = 0; i < 5; i++)
    {
        printf("%d ",a[i]);
    }


    for ( i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }
    
    selectionsort(a,5);

    for ( i = 0; i < 5; i++)
    {
        printf("%d ",a[i]);
    }

    for ( i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }
    
    quicksort(a,0,5);

    for ( i = 0; i < 5; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
