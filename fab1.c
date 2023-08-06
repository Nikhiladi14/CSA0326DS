#include<stdio.h>
int main()
{
	int a=0,b=1,c,n,i;
	printf("enter the number to be printe upto:");
	scanf("%d",&n);
	printf("%d\n%d\n",a,b);
	for(i=2;i<n;i++)
	{
		c=a+b;
		printf("%d\n",c);
		a=b;
		b=c;
	}
	return 0;
}