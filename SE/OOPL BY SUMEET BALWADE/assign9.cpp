#include<iostream>
using namespace std;
template<class T>
void selection(T a[], int n)
{
int i,j,temp,k;
	for(i=0;i<n-1;i++)
{
  k=i;
 for(j=i+1;j<n;j++)
{
  if(a[j]<a[k])
  {
    k=j;
  }
}

  temp=a[i];
  a[i]=a[k];
  a[k]=temp;
}
}

int main()
{
int a[7]={16,19,11,15,10,12,14};
char b[4]={'s','b','d','e'};
float c[6]={10.2,5.0,6.3,5.2,1.5,1.56};
selection(a,6);
cout<<"\nSorted Order Integers: ";
for(int i=0;i<6;i++)
cout<<"\n"<<a[i]<<"\t";
selection(b,4);
cout<<"\nSorted Order Characters: ";
for(int j=0;j<4;j++)
    cout<<"\n"<<b[j]<<"\t";
cout<<"\nSorted Order float: ";
selection(c,6);
for(int j=0;j<6;j++)
cout<<"\n"<<c[j]<<"\t";
return 0;
}
