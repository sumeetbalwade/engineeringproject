#include<stdio.h>

void display_cricket(int[],int);
void display_badminton(int[],int);
void display_cricket_or_badminton(int[],int[],int,int);
void display_cricket_and_badminton(int[],int[],int,int);
void onlycri(int[],int[],int,int);

int main()
{
	int ex=0,choise=0;
	//int set[65];
	int cri[65];
	int bad[65];
	int total=0,i=0,cricket=0,badmintan=0;

	printf("Enter the total Number of student : ");
	scanf("%d",&total);

	printf("Enter the Number students How play cricket :");
	scanf("%d",&cricket);


	for(i=0;i<cricket;i++)
	{
		printf("\nEnter the number %d = ",i+1);

		scanf("%d",&cri[i]);
	}

	printf("Enter the Number students How play Badmintan :");
	scanf("%d",&badmintan);

	for(i=0;i<badmintan;i++)
	{
		printf("\nEnter the number %d = ",i+1);

		scanf("%d",&bad[i]);
	}
	
	do{
		printf("\n");
		printf("*****MENU*****");
		printf("\n");
		printf("\n1 : Display Cricket\n2 : Display Badminton");
		printf("\n3 : Display Cricket or Badminton");
		printf("\n4 : Display Cricket and Badminton");
		printf("\n5 : Only play Cricket");
		printf("\n6 : Exit");
		printf("\n");
		printf("Enter Your Choise : ");
		printf("\n");
		scanf("%d",&choise);
		switch(choise)
		{			
			case 1:
					display_cricket(cri,cricket);
			break;
			
			case 2:
					display_badminton(bad,badmintan);
			break;
			
			case 3:
					display_cricket_or_badminton(cri,bad,cricket,badmintan);
			break;
			
			case 4:
					display_cricket_and_badminton(cri,bad,cricket,badmintan);
			break;
			
			case 5: 
					onlycri(cri,bad,cricket,badmintan);
			break;
					
			//default :
				
				//printf("******You Entered Invalid Input******");
		}
			printf("\n");
		printf("**IF**");
		printf("\n");
		printf("DO YOU WANT TO CONTINUE******\nPRESS...1...!!!");
		printf("\n");
		printf("**ELSE**");
		printf("\n");
		printf("ENTER ANY VALUE.....");
		scanf("%d",&ex);
		if(ex!=1)
		printf("\nTERMINATING..............");
	}while(ex == 1);
	
	return 0;
}

void display_cricket(int arr[],int value)
{
	int i;
	printf("student who play cricket = {");

	for(i=0;i<value;i++)
	{
		printf("\t%d\t",arr[i]);
	}
	printf("\t}\n");
}
  	
void display_badminton(int arr[],int value)
{
	int i;
	printf("student who play Badmintan = {");

	for(i=0;i<value;i++)
	{
		printf("\t%d\t",arr[i]);
	}
	printf("\t}\n");
	
}

void display_cricket_or_badminton(int arr[],int brr[], int value1,int value2)
{

	int i=0,j=0,k=0,dis=0;
	int uni[65];
	int n=0;

		for(i=0;i<value1;i++)
		{
		  uni[i]=arr[i];
		}
		n=value1;

		for(j=0;j<value2;j++)
		{
			for(k=0;k<value1;k++)
			{
				if(brr[j]==uni[k])
				{
					
					//n++;
					break;
				}

			}

				if(k==i)
				{
				   uni[n]=brr[j];
				   n++;
				}

		}

		printf("Who play cricket or Badminton :");
		printf("{");
		for(dis=0;dis<n;dis++)
		{
			printf("\t%d",uni[dis]);
		}
		printf("\t}");
	
	
}

void display_cricket_and_badminton(int arr[],int brr[], int value1,int value2)
{
	int inter[65];
	int count=0;
	int i=0,j=0;
	int dis=0,n=0;

	for(i=0;i<value1;i++)
	{
	
		for(j=0;j<value2;j++)
		{
			if(arr[i]==brr[j])
			{	
				inter[count]=arr[i];
				count++;
				n++;
				break;
			}
		}

	}


	printf("Who play cricket and Badminton : ");
	printf("{");
	for(dis=0;dis<n;dis++)
	{
		printf("\t%d",inter[dis]);
	}
	printf("\t}");

}


void onlycri(int arr[],int brr[], int value1,int value2)
{
	int i=0,j=0,dis=0;
	int count=0;
	int cr[30];
	
	for(i = 0;i<value1;i++)
	{
		for(j=0;j<value2;j++)
		{
			if(arr[i]!=brr[j])
			{
				cr[count]=arr[i];
				count++;
				break;
			}
		}
	}
	
	printf("Who play only cricket : ");
	printf("{");
	for(dis=0;dis<count;dis++)
	{
		printf("\t%d",cr[dis]);
	}
	printf("\t}");
	
	
}

























