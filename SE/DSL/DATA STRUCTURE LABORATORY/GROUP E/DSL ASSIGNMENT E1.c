

#include<stdio.h>
int selection_sort(float s[],int n);
int bubble_sort(float s[],int n);
int main()
{
	int i,j,min,n,ch,d;
	float s[10];
	printf("\nenter the total no. of students:");
	scanf("%d",&n);
	printf("\nenter the students marks:");
	for(i=0;i<n;i++)
	{
		scanf("%f",&s[i]);
	}
	do
	{
	printf("\n1.selection_sort");
	printf("\n2.bubble_sort");
	printf("\n3.top 5 students");
	printf("\nenter your choice:");
	scanf("%d",&ch);
	switch(ch)
		{
			case 1: selection_sort(s,n);
				printf("\nsorted list:");
				for(i=0;i<n;i++)
				{
					printf("%f\n",s[i]);
				}
				break;

			case 2: bubble_sort(s,n);
				printf("\nsorted list:");
				for(i=0;i<n;i++)
				{
					printf("%f\n",s[i]);
				}
				break;
			case 3: bubble_sort(s,n);
				printf("\ntop 5 students:");
				for(i=n-1;i>n-6;i--)
				{
					printf("%f\n",s[i]);
				}

			break;
			default:("\nenter the valid choice");
		}
		printf("\npress 1 for continue:");
		scanf("%d",&d);
	}while(d==1);

	return 0;
}


int selection_sort(float s[],int n)
{
	int j,i,min;
	float temp;

	for(i=0;i<(n-1);i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(s[j]<s[min])
			{
				min=j;
			}
		}
		if(i!=min)
		{
			temp=s[i];
			s[i]=s[min];
			s[min]=temp;
		}
	}

}


int bubble_sort(float s[],int n)
{
	int i,j;
	float temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(s[j]>s[j+1])
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
}
