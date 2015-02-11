#include"header.h"

void get_input(int *r,int *c,int a[][MAX])
{
int i,j;
printf("Enter the number of row:-\n");
scanf("%d",r);
printf("Enter the number of column:-\n");
scanf("%d",c);
printf("Enter the matrix elements:-\n");
for(i=0;i<*r;i++)
{
for(j=0;j<*c;j++)
{
scanf("%d",&a[i][j]);
}
}
}

int check_square_matrix(int r,int c)
{
if(r==c)
return 1;
else
return 0;
}

void display_matrix(int (*arr)[MAX],int r,int c)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf(" %d ",arr[i][j]);
}
}
printf("\n");
}

int check_magic(int (*arr)[MAX],int row,int col)
{
int i,j;
int r_sum[MAX],c_sum[MAX],d_sum1=0,d_sum2=0;

for(i=0;i<MAX;i++)
{
r_sum[i]=0;
c_sum[i]=0;
}

for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
r_sum[i]+=arr[i][j];
//printf(" %d ",r_sum[i]);
}
printf("\n");
}
for(i=0;i<col;i++)
{
for(j=0;j<row;j++)
{
c_sum[i]+=arr[i][j];
//printf(" %d ",c_sum[i]);
}
printf("\n");
}
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
if(i==j)
{
d_sum1+=arr[i][j];
printf("\n %d \n",d_sum1);
}
if((i+j)==(col-1))
{
d_sum2+=arr[i][j];
printf("\n %d\n",d_sum2);
}
}
}
for(i=0;i<row;i++)
{
printf("%d %d %d %d \n",r_sum[i],c_sum[i],d_sum1,d_sum2);
if((r_sum[i]== c_sum[i]) && (d_sum1==d_sum2) && (d_sum1==r_sum[i]) )
continue;
else
return 0;
}
return 1;
}


