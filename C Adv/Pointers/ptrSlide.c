#include<stdio.h>
int main()
{
int i = 5, j = 10;
int *ptr;    
int **pptr;  
ptr = &i;    
pptr = &ptr; 
*ptr = 3;
printf("\nValue of i after *ptr=3 %d\n",i);
**pptr = 7;
printf("\nValue of i after **pptr=7 %d\n",i);
ptr = &j;
**pptr = 9;
printf("\nValue of i and j after ptr=&j and **pptr=9 %d %d\n",i,j);
*pptr = &i;
printf("\nValue of i and j after *pptr=&i %d %d\n",i,j);
*ptr = -2;
printf("\nValue of i and j after *pptr=&i and *ptr=-2 %d %d\n",i,j);
return 0;
}
