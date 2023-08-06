#include<stdio.h>
void quicksort(int[ ],int,int);
int main()
{
int low, high, pivot, t, n, i, j, a[10];
int clrscr();
printf("\nHow many elements you want to sort ? ");
scanf("%d",&n);
printf("\Enter elements for an array:");
for(i=0; i<n; i++)
 scanf("%d",&a[i]);
low=0;
high=n-1;
quicksort(a,low,high);
printf("\After Sorting the elements are:");
for(i=0;i<n;i++)
 printf("%d ",a[i]);
}
void quicksort(int a[ ],int low,int high)
{
 int pivot,t,i,j;
 if(low<high)
 {
 pivot=a[low];
 i=low+1;
 j=high;
 while(1)
 {
while(pivot>a[i]&&i<=high)
 i++;
 while(pivot<a[j]&&j>=low)
 j--;
 if(i<j)
 {
 t=a[i];
 a[i]=a[j];
 a[j]=t;
 }
 else
 break;
 }
 a[low]=a[j];
 a[j]=pivot;
 quicksort(a,low,j-1);
 quicksort(a,j+1,high);
}
}