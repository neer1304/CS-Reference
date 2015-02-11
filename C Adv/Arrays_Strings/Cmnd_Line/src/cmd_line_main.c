**************************************************************************/
/*************************************************************************
*                       Header Files
**************************************************************************/
#include "cmd_line_header.h"

/**************************************************************************
*                       LOCAL MACROS
**************************************************************************/
#define ARG_MIN 3
#define ARG_MAX 4

/****************************************************************************
*
*       Function Name   : main
*       Description     : Accepts a number and strings as command line
*			  arguments. If the number is 1, then it copies
*			  the 1st string. 
*			  If the number is 2, then it concatenates the 
*			  2nd string to the 1st one.
*       Returns         : Success or Failure
*
****************************************************************************/
int main(
	 int no_of_arg, /* Number of command line arguments */
	 char *arg_values[] /* Command line arguments */
        )
{
 char result[MAX]; /* Array to store the result */
 cmd_ret ret_val = SUCCESS; /* Return value from function */

 /* Check for correct number of command line arguments */ 
 if(no_of_arg < ARG_MIN || no_of_arg > ARG_MAX)
 {
   printf("Invalid number of arguments\n");
   /* The first argument is executable name itself */
   printf("<%s> <1> <string> - for copy\n", arg_values[0]);
   printf("<%s> <2> <string1> <string-2> - for concat\n", arg_values[0]);
   exit(EXIT_FAILURE);
 }
 
 /* Initializing the array */
 memset(result, 0, MAX);

 /* Function call to get the operation done */
 ret_val = process_args(arg_values, result);
 if(FAILURE == ret_val) /* Error check for process_args */
 {
  printf("Operation failed\n");
  exit(EXIT_FAILURE);
 }
 
 /* Displaying the result of operations */
 printf("Result is %s\n", result);

 return 0; 
}
