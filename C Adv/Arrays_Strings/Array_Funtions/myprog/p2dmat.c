#include<stdio.h>

#define r 2
#define c 3

void print2d(int **arr)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{

//printf("%d\t",(*(int *)((*(int(*)[col])(arr+i))+j)));
//printf("%d",*((int *)((*(int(*)[c](arr+i)))+j)) );
//printf("%d",*(int *)*((*(int(*)[c])(arr+i))+j) );
printf("%d",*((int *)(*(((int(*)[c])arr)+i))+j));
}
}
printf("\n");
}

void print2d_1(int(*arr)[c])
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf("%d\t",arr[i][j]);
}
}
printf("\n");
}

int main()
{
int mat[2][3] = {{1,2,3},{4,5,6}};
print2d(mat);
return 0;
}



