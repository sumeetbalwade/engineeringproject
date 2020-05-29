/*
******************************ASSIGNMENT NUMBER E-2 ***********************************

STATEMENT

32. Write C++ program to store roll numbers of student in array who attended training program
in random order. Write function fora) Searching whether particular student attended training program or not using linear search
and sentinel search. b) Searching whether particular student attended training program or
not using binary search and Fibonacci search. 

OS - WINDOWS x64
IDE - MICROSOFT VISUAL STUDIO CODE 2019
COMPILER - GNU/MINGW GCC

ASSIGNMENT BY SUMEET BALWADE
GUIDED BY PROF. NIMBALKAR
*/


#include<stdio.h>
void lsearch(int a[],int n);
void bsearch(int a[],int n);
int main()
{
    int a[10],i,n,c,d,ch;
    printf("\nenter the no. of elements:");
    scanf("%d",&n);
    printf("\nenter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    do
    {
        printf("\n1.linear search");
        printf("\n2.binary search");
        printf("\nenter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nlinear search");
                   lsearch(a,n);
                   break;
            case 2:printf("\nbinary search");
                   bsearch(a,n);
                   break;
            default:printf("\nwrong choice");
        }
        printf("\npress 1 for continue:");
        scanf("%d",&d);
    }while(d==1);

}
void lsearch(int a[],int n)
{
    int i,c;
    printf("\nenter the elements you want to search:");
    scanf("%d",&c);
    for(i=0;i<n;i++)
    {
        if(a[i]==c)
        printf("\nelement is present at location:%d",i+1);
    }
    if(c==n)
    {
        printf("\nelement is not present:");
    }
}
void bsearch(int a[],int n)
{
    int i,j,f,l,m,c;
	int temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\nsorted list:");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }

    printf("\nenter the elements you want to search:");
    scanf("%d",&c);
    f= 0;
    l=n-1;
    m=(f+l)/2;
    while(f <= l)
    {
        if(a[m]<c)
        {
            f=m+1;
        }
        else if(a[m]==c)
        {
            printf("\nelement is present at location%d.\n",m+1);
         break;
        }
      else
        {
            l=m-1;
        }
      m=(f+l)/2;
   }
    if (f>l)
    {
        printf("Not found! %d is not present in the list.\n",c);
    }

}
