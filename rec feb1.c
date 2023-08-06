#include<stdio.h>

#include<conio.h>

int recursivefibonacci(int);

int main(){

int m, x;

printf("enter the number\n");

scanf("\n%d",&m);

for(x=0;x<m;x++) 
{

printf("%d\n",recursivefibonacci(x));

}

getch();

}

int recursivefibonacci(int x)
{

if(x==0) return 0;

else if(x==1) return 1;

else return (recursivefibonacci(x-1) + recursivefibonacci(x-2));

}