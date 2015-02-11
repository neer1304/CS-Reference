#include"header.h"
void display(int a[],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
printf("\n");
}

void mergesort(int a[],int low,int high)
{
int mid;
  if(low<high)
  {
   mid=(low+high)/2;
   mergesort(a,low,mid);
   mergesort(a,mid+1,high);
   merge(a,low,mid,mid+1,high);
  }
}

void merge(int a[],int lb1,int ub1,int lb2,int ub2)
{
int i=lb1,j=lb2,k=0;
int c[20];
    while((i<=ub1)&&(j<=ub2))  //copy elements into buffer array till one list exhaust
    {
       if(a[i]<=a[j])
       {
        c[k]=a[i];
	k++;
	i++;
       }
       else
       {
       c[k]=a[j];
       k++;
       j++;
       }
    }
       while(i<=ub1)   //if elements left in first list
       {
         c[k]=a[i];
	 k++;
	 i++;
       }
       while(j<=ub2)   //if elements left in second list
       {
         c[k]=a[j];
	 k++;
	 j++;
       }
       k=0;i=lb1;
       while(i<=ub2)
       {
        a[i]=c[k];
	i++;
	k++;
       }
}
