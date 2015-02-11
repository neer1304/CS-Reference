
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

static int compare(char*, char*);
static void sort(char **, int, int (*)(char*, char*));


/****************************************************************************
*       Function Name   : compare
*       Description     : compares two integers
*       Returns         : returns 1 if the first number is smaller 
*			  and 0 if the first number is larger
****************************************************************************/
static int compare(
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
static void sort(
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

/****************************************************************************
*       Function Name   : main
*       Description     : Demonstration of function pointers
*       Returns         : Success or Failure
****************************************************************************/
int main()
{
 int index = 0; /* for loop index */
 /*Initializing an array */
// int num[MAX] = {222,33,11,555,44,444,666,77,88,99};
 char *input[MAX];

 int ret = 0; 
 int (*f_ptr)(char*, char*) = NULL; /* Function pointer */

 for(index=0;index<MAX;index++)
 input[index]=(char*)malloc(20*sizeof(char));

 for(index=0;index<MAX;index++)
 { 
  printf("Please enter the String %d\n",index);
  scanf("%s",input[index]);
 }
 printf("The original string array before sorting is :-\n");
 for(index=0;index<MAX;index++)
 {
 printf("%s ",input[index]);
 }
 printf("\n");

 f_ptr = compare; /* Assigning address of function to function pointer */ 

 /* Invoking the function using function pointer */
 ret = f_ptr(input[0], input[1]);
 if(ret == 0) /* If the first number is larger */
 {
  printf("*****************************\n");
  printf("%s is greater than %s\n", input[0], input[1]);
  printf("*****************************\n");
 }
 else /* If the first number is smaller */
 {
  printf("*****************************\n");
  printf("%s is smaller than %s\n", input[0], input[1]);
  printf("*****************************\n");
 }

 /* Sorting the array. "compare" is a function which is passed as an argument */
 sort(input, MAX, compare);

 printf("The sorted array is\n");
 printf("*******************\n");
 /* Displaying the array elements */
 for(index = 0; index < MAX; index += 1)
 {
  printf("%s ", input[index]);
 }
 printf("\n");
 return 0;
}
