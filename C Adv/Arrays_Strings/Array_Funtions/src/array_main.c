/*****************************************************************************
*                       Header Files
******************************************************************************/

#include "array_header.h"

/******************************************************************************
*
*       Function Name   : main
*       Description     : Contains function calls to demonstrate how arrays are
*			  passed to functions
*       Returns         : Success or Failure
*
*******************************************************************************/int main()
{
 /* 1-D array initialized */
 int numbers[MAX] = {11,22,33,44,55};
 /* 2-D array initialized */
 int matrix[ROW][COL] = {{111,222,333},{444,555,666}};
 
 printf("Initial Array\n");
 printf("*************\n");
 /* Displays the 1-D array */
 display_1d(numbers, MAX);

 /* Updates the array using array notation */
 update_1d_array(numbers, MAX);

 printf("After call to update - array notation\n");
 printf("**************************************\n");
 /* Displays the 1-D array. Changes are reflected. Pass by pointer */
 display_1d(numbers, MAX);

 /* Updates the array using pointer notation */
 update_1d_ptr(numbers, MAX);

 printf("After call to update - ptr notation\n");
 printf("***********************************\n");
 /* Displays the 1-D array. Changes are reflected. Pass by pointer */
 display_1d(numbers, MAX);

 /* Reverses the array */
 reverse_1d_ptr(numbers, MAX);

 printf("After call to reverse\n");
 printf("*********************\n");
 /* Displays the 1-D array after reversing */
 display_1d(numbers, MAX);

 printf("Initial 2D Array - Array Notation\n");
 printf("*********************************\n");
 /* Displays the 2-D array using array notation */
 display_2d_array((int (*)[])matrix);

 printf("Initial 2D Array - pointer to array Notation\n");
 printf("********************************************\n");
 /* Displays the 2-D array using pointer to array notation */
 display_2d_ptr(matrix);

/*
 printf("Initial 2D Array - double pointer Notation\n");
 printf("******************************************\n");
*/
 /* Displays the 2-D array using double pointer notation */
 display_2d_dbl_ptr(matrix);

 return 0;
}
