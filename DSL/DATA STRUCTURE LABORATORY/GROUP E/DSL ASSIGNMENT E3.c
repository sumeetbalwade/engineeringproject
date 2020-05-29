
#include<stdio.h>
int partition(int arr[],int l,int h);
void quicksort(int arr[],int l,int h);
int main()
{
	int arr[10];
	int l,h,n,j,i;
	printf("\nenter the no. of students:");
	scanf("%d",&n);
	printf("\nenter the marks of students:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	quicksort(arr,0,n-1);
	printf("\nsorted marks is:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}

	return 0;
}

int partition(int arr[],int l,int h)
{
	int pivot;
	int i,j,temp;


		pivot=l;
		i=l;
		j=h;
		while(i<j)
		{
			while(arr[i]<=arr[pivot])
			{
				i++;
			}

			while(arr[j]>arr[pivot])
			{
				j--;
			}
			if(i<j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	if(i>=j)
	{
		temp=arr[pivot];
		arr[pivot]=arr[j];
		arr[j]=temp;
	}

	return j;

}

void quicksort(int arr[],int l,int h)
{
	int loc;
	if(l<h)
	{
		loc=partition(arr,l,h);
		quicksort(arr,l,loc-1);
		quicksort(arr,loc+1,h);
	}

}

