#include<stdio.h>


int main(int argc, char const *argv[])
{
    int a[10];
    int i,j,temp,size=5;
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
    }

    for ( i = 0; i < size; i++)
    {
        temp=a[i];

        for ( j = i-1; j>=0 && a[j]>temp; j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }


    for ( i = 0; i < size; i++)
    {
        printf("%d\t",a[i]);
    }
    
    return 0;
}
