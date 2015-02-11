/*****************************************************************************
*                       Header Files
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*****************************************************************************
*                       Macros
******************************************************************************/
#define MAX 6

/*****************************************************************************
*                       User Defined types
******************************************************************************/
typedef struct
{
 int id; 
 char name[MAX];
}sample1;

typedef struct
{
 int id; 
 char ch;
}sample2;

typedef struct
{
 float *f;
 char ch;
}sample3;

typedef struct
{
 long double d;
 int i;
 char ch;
}sample4;

typedef struct
{
 char ch1;
 char ch2;
 char ch3;
}sample5;
/******************************************************************************
*
*       Function Name   : main
*       Description     : Displays size of a structure
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 sample4 s;
 printf("Size of int is %d\n",sizeof(int));
 printf("Size of char max is %d\n",sizeof(char[MAX]));
 printf("Size of long double is %d\n", (sizeof(long double)));
 printf("Size of structure is %d\n", sizeof(sample1));
 printf("\nSize of structure is %d\n", sizeof(sample2));
 printf("\nSize of structure is %d\n", sizeof(sample3));
 printf("\nSize of structure is %d\n", sizeof(sample4));
 printf("\nSize of structure is %d\n", sizeof(sample5));
 return 0;
}
