/*****************************************************************************
*                       Header Files
******************************************************************************/

#include "array_header.h"

/******************************************************************************
*
*       Function Name   : update_1d_array
*       Description     : Increment array elements with index
*       Returns         : Nothing
*
*******************************************************************************/
void update_1d_array(
		     MODI int arg_array[], /* Argument - array notation  */
		     IN int size /* size of the array */
	      	    )
{
 int index; /* for loop index */
 /* Displays the size of the argument. Size is pointer size */
printf("Size of arg_array[] = %d\n", sizeof(arg_array));
 for(index = 0; index < size; index += 1)
 {
  arg_array[index] = arg_array[index] + index;
 }
} 

/******************************************************************************
*
*       Function Name   : update_1d_ptr
*       Description     : Increment array elements with index
*       Returns         : Nothing
*
*******************************************************************************/
void update_1d_ptr(
                   MODI int *arg_ptr, /* Argument - pointer notation  */
                   IN int size /* size of the array */
                  )
{
 int index; /* for loop index */
 /* Displays the size of the argument. Size is pointer size */
 printf("Size of arg_array[] = %d \n", sizeof(arg_ptr));
 for(index = 0; index < size; index += 1)
 {
  arg_ptr[index] = arg_ptr[index] + index;
 }
}


/******************************************************************************
*
*       Function Name   : reverse_1d_ptr
*       Description     : Reverses the array
*       Returns         : Nothing
*
*******************************************************************************/
void reverse_1d_ptr(
                    MODI int *arg_ptr, /* Argument - pointer notation  */
                    IN int size /* size of the array */
              	   )
{
 int temp; /* temporary variable for swapping */
 int *base_ptr = arg_ptr; /* Points to the begining of the array */
 int *end_ptr = arg_ptr + size - 1; /* Points to the end of array */

 /* Displays the size of the argument. Size is pointer size */
 printf("Size of arg_array[] = %d\n", sizeof(arg_ptr));

 /*
  * Reverses the array 
  */
 for(; base_ptr < end_ptr; base_ptr += 1, end_ptr -= 1)
 {
  /* Swapping the elements */
  temp = *base_ptr;
  *base_ptr = *end_ptr;
  *end_ptr = temp;
 }
}

/******************************************************************************
*
*       Function Name   : display_1d
*       Description     : Displays array elements using array notation argument
*       Returns         : Nothing
*
*******************************************************************************/
void display_1d(
		IN int arg_array[], /* Argument to array */
		IN int size /* Size of the array */
	       )
{
 int index; /* for loop index */
 for(index = 0; index < size; index += 1)
 {
  printf("%d\t", arg_array[index]);
 }
 printf("\n");
}

/******************************************************************************
*
*       Function Name   : display_2d_array
*       Description     : Displays array elements using array notation argument
*       Returns         : Nothing
*
*******************************************************************************/
void display_2d_array(
                        IN int arg_array[][COL] /* Argument - Array notation */
                     )
{
 int index_1, index_2; /* for loop index */
 /* Displays the size of the argument */
 printf("Size of arg_array[] = %d\n", sizeof(arg_array[COL]));
 for(index_1 = 0; index_1 < ROW; index_1 += 1)
 {
  for(index_2 = 0; index_2 < COL; index_2 += 1)
  {
   printf("%d\t", arg_array[index_1][index_2]);
  }
 }
 printf("\n");
}

/******************************************************************************
*
*       Function Name   : display_2d_array
*       Description     : Displays array elements using ptr notation argument
*       Returns         : Nothing
*
*******************************************************************************/
void display_2d_ptr(
                        IN int (*arg_ptr)[COL] /* pointer to an array */
                   )
{
 int index_1, index_2; /* for loop index */
/* Displays the size of the argument */
 printf("Size of arg_array[] = %d\n", sizeof(arg_ptr[COL]));
 for(index_1 = 0; index_1 < ROW; index_1 += 1)
 {
  for(index_2 = 0; index_2 < COL; index_2 += 1)
  {
   printf("Value %d\t", arg_ptr[index_1][index_2]);
  }
 }
 printf("\n");
 
}

/* Following function crashes the program. Observe the compiler warning*/

/******************************************************************************
*
*       Function Name   : display_2d_dbl
*       Description     : Displays array elements using dbl ptr arg
*       Returns         : Nothing
*
*******************************************************************************/
void display_2d_dbl_ptr(
                        IN int **arg_dbl_ptr /* pointer to an array */
                       )
{
 int index_1, index_2; /* for loop index */
 /* Displays the size of the argument */
 printf("Size of arg_array[] = %d\n", sizeof(arg_dbl_ptr));
 for(index_1 = 0; index_1 < ROW; index_1 += 1)
 {
  for(index_2 = 0; index_2 < COL; index_2 += 1)
  {
  printf("%d\t", arg_dbl_ptr[index_1][index_2]);
   // printf("%d\t",(*(*(arg_db1_ptr+index_1)+index_2)));
  }
 }
 printf("\n");
}

