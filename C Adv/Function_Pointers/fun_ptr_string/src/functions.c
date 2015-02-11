#include"header.h"


/****************************************************************************
*       Function Name   : compare
*       Description     : compares two integers
*       Returns         : returns 1 if the first number is smaller 
*			  and 0 if the first number is larger
****************************************************************************/
 int compare(
		   char *first, /* First number */
		   char *second /* Second number */
		  )
{
 if(strcmp(first,second)<=0) /* first number is less or equal to the second number */
 {
  return 1;
 }
 else /* first number is greater than the first number */
 {
  return 0;
 }
}



/****************************************************************************
*       Function Name   : sort
*       Description     : sorting an array of numbers using insertion sort
*       Returns         : Nothing
****************************************************************************/
 void sort(
		 char **arg_array, /* Array of integers to be sorted */
		 int size, /* Size of the array */
		 int (*ptr_compare)(char*, char*)
		)
{
 /* for loop indices */
 int index_1 = 0, 
     index_2 = 0;
char *min =NULL; /* Current minimum */
 int min_index = 0; /* Index of current minimum */
 
 /* Iterates over the all the elements in the array */
 for(index_1 = 0; index_1 < size; index_1 += 1)
 {
  /* min_index is initialized with the current index */
  min_index =  index_1; 

  /* min initialized with the current value */
  min =  arg_array[index_1];

  /* Iterates over the remaining elements in the array */
  for(index_2 = index_1 + 1; index_2 < size; index_2 += 1)
  {
   /* Call the function which is passed as an argument */ 
   if(ptr_compare(arg_array[index_2], min))  //if found less than min than update the min,compare returns 1 if less tan equal to
   {
    /* Replacing min and min_index values based on comparison result */
    min = arg_array[index_2];
    min_index = index_2;
   }
  }
  /* Inserting the min at the correct position */
  arg_array[min_index] = arg_array[index_1];
  arg_array[index_1] = min;
 } 
}
