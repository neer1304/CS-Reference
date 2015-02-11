#include<stdio.h>
#include"header.h"


int main()
{
int row,col,arr[MAX][MAX];
get_input(&row,&col,(int(*)[])arr);


if(check_square_matrix(row,col))
{
if(check_magic((int(*)[MAX])arr,row,col))
{
printf("\nThe Input Matrix is Magic Matrix\n");
display_matrix((int(*)[MAX])arr,row,col);
}
else
printf("\nNot a Magic Matrix\n");
}
else
printf("\nNot a square matrix.\n");

return 0;
}
