/*****************************************************************************
*                       Header Files
******************************************************************************/
#include <stdio.h>

/*****************************************************************************
*                       User Defined types
******************************************************************************/
typedef union
{
 int num;
 char ch;
}sample;

/******************************************************************************
*
*       Function Name   : main
*       Description     : Demonstrates union
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 sample dummy;
 printf("size of union - %d\n", sizeof(sample));
 printf("Enter an integer\n");
 scanf("%d", &dummy.num);

 getchar();
 printf("Enter a character\n");
 scanf("%c", &dummy.ch);

 printf("The entered values are\n");
 printf("%d\t%c\n", dummy.num, dummy.ch);

 return 0;
}

