#include<stdio.h>
#include<math.h>
int main()
{
float root1,root2;
int a,b,c;
float d;
printf("enter the coefficients :\n");
//scanf("%d%d%d ",&a,&b,&c);
scanf("%d%d%d",&a,&b,&c);
d=(b*b)-(4*a*c);

if(d==0.00)
{
  root1=-b/2;
  root2=root1;
  printf("root1 and root2:%f",root1,root2);

}
else if(d>0)
{
    root1=(-b+sqrt(d))/(2*a);
    root2=(-b-sqrt(d))/(2*a);
    printf("root1 and root2:%f     %f",root1,root2);
}
else
{
    printf("root1:%f + %f *i\n",-b/2*a,sqrt(d)/2*a);
    printf("root2:%f + %f *i",-b/2*a,sqrt(d)/2*a);

}
}
