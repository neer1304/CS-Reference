/*************************************************************************
*                       Header Files
**************************************************************************/

#include "pbv_pbr_header.h"

/******************************************************************************
*
*       Function Name  : pbv_swap_int
*       Description    : swaps two int arguments and displays the swapped value
*       Returns        : Nothing
*
*******************************************************************************/
void pbv_swap_int(
		   int arg_1, /* First integer */
		   int arg_2  /* Second integer */
		 )
{
 int temp = 0; /* Temporary variable for swapping */ 
 /* Swapping 2 values using a temporary variable */
 temp = arg_1;
 arg_1 = arg_2;
 arg_2 = temp;
 printf("Inside the pbv_swap_int function\n");
 printf("********************************\n");
 printf("%d %d\n", arg_1, arg_2);
}

/******************************************************************************
*
*       Function Name  : pbv_swap_char
*       Description    : swaps two char arguments and displays the swapped value
*       Returns        : Nothing
*
*******************************************************************************/
void pbv_swap_char(
                   char arg_1, /* First char */
                   char arg_2  /* Second char */
                 )
{
 char temp = '\0'; /* Temporary variable for swapping */
 /* Swapping 2 values using a temporary variable */
 temp = arg_1;
 arg_1 = arg_2;
 arg_2 = temp;
 printf("Inside the pbv_swap_char function\n");
 printf("*********************************\n");
 printf("%c %c\n", arg_1, arg_2);
}

/******************************************************************************
*
*       Function Name  : pbr_swap
*       Description    : swaps two arguments and displays the swapped value
*       Returns        : Nothing
*
*******************************************************************************/
void pbr_swap(
              void * v_arg_1, /* First char */
              void * v_arg_2,  /* Second char */
	      int type /* Determines the type */
             )
{
 int temp = 0; /* Temporary variable for swapping */
 /* Swapping 2 values using a temporary variable */
 printf("Inside the pbr_swap function\n");
 printf("****************************\n");
 if(1 == type)
 {
  temp = *(int *) v_arg_1;
  *(int *)v_arg_1 = *(int *)v_arg_2;
  *(int *)v_arg_2 = temp;
  printf("%d %d\n", * (int *)v_arg_1, * (int *) v_arg_2);
 }
 else if(2 == type)
 {
  temp = *(char *) v_arg_1;
  *(char *)v_arg_1 = *(char *)v_arg_2;
  *(char *)v_arg_2 = temp;
  printf("%c %c\n", * (char *)v_arg_1, * (char *) v_arg_2);
 }
}

