/*NOTE: THIS PROGRAM IS JUST TO DEMONSTRATE FUNCTION POINTERS. ERROR
        HANDLING, FUCTION RETURNS ERROR CODE LIKE GOOD CODING PRACTICES
	ARE NOT TAKEN CARE OF. */

/***************************************************************************
*                       STANDARD HEADER FILES
***************************************************************************/
#include <stdio.h>

/***************************************************************************
*                       MACROS
***************************************************************************/
#define MAX 10

/***************************************************************************
*                       FUNCTION PROTOTYPES
***************************************************************************/
static int compare(int, int);
static void sort(int [], int, int (*)(int, int));


/****************************************************************************
*       Function Name   : compare
*       Description     : compares two integers
*       Returns         : returns 1 if the first number is smaller 
*			  and 0 if the first number is larger
****************************************************************************/
static int compare(
		   int first, /* First number */
		   int second /* Second number */
		  )
{
 if(first <= second) /* first number is less or equal to the second number */
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
static void sort(
		 int arg_array[], /* Array of integers to be sorted */
		 int size, /* Size of the array */
		 int (*ptr_compare)(int, int)
		)
{
 /* for loop indices */
 int index_1 = 0, 
     index_2 = 0;
 int min = 0; /* Current minimum */
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
   if(ptr_compare(arg_array[index_2], min))
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

/****************************************************************************
*       Function Name   : main
*       Description     : Demonstration of function pointers
*       Returns         : Success or Failure
****************************************************************************/
int main()
{
 int index = 0; /* for loop index */
 /*Initializing an array */
 int num[MAX] = {222,33,11,555,44,444,666,77,88,99};
 int ret = 0; 
 int (*f_ptr)(int, int) = NULL; /* Function pointer */

 printf("The original array is\n");
 printf("*********************\n");
 /* Displaying the array elements */
 for(index = 0; index < MAX; index += 1)
 {
  printf("%d\t", num[index]);
 }
 printf("\n");

 f_ptr = compare; /* Assigning address of function to function pointer */ 

 /* Invoking the function using function pointer */
 ret = f_ptr(num[0], num[1]);
 if(ret == 0) /* If the first number is larger */
 {
  printf("*****************************\n");
  printf("%d is greater than %d\n", num[0], num[1]);
  printf("*****************************\n");
 }
 else /* If the first number is smaller */
 {
  printf("*****************************\n");
  printf("%d is smaller than %d\n", num[0], num[1]);
  printf("*****************************\n");
 }

 /* Sorting the array. "compare" is a function which is passed as an argument */
 sort(num, MAX, compare);

 printf("The sorted array is\n");
 printf("*******************\n");
 /* Displaying the array elements */
 for(index = 0; index < MAX; index += 1)
 {
  printf("%d\t", num[index]);
 }
 printf("\n");
 return 0;
}
