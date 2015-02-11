/*****************************************************************************
*                       STANDARD HEADER FILES
******************************************************************************/
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/*****************************************************************************
*                       MACROS
******************************************************************************/
#define MAX 10
#define END -1

/*****************************************************************************
*                       FUNCTION PROTOTYPES
******************************************************************************/
static int args_maximum(int, ...);

/**************************************************************************
* 	FUNCTION NAME: args_maximu
*
* 	DESCRIPTION: Finds out the maximum of arguments
*
* 	RETURNS: Maximum from the arguments
**************************************************************************/
int args_maximum(
	  	 int first_val, /* first argument - fixed */
	  	 ... /* Designates multiple arguments */
	 	)
{
 va_list arg_list; /* List to point to the non-fixed arguments */
 char str[MAX]; /* This array is used to retrieve an char array using va_array */
 int temp = 0,  /* temporary variable to store the value returned from va_arg */
     maximum = -1;  /*Stores the maximum of arguments */  

 /* Initializes maximum to the fixed argument */
 temp = first_val;
 maximum = first_val;
 memset(str, 0, MAX); /* Initializing the array */

 /* Initializing arg_list to the list of non-fixed arguments */
 va_start(arg_list, first_val); /* Note that the last fixed argument is passed
				   to va_start */

 /* This loop retrieves all non-fixed arguments. Note that we are */
 while(END != temp)
 {
  /* Retrieving the subsequent non-fixed arguments */ 
  temp = va_arg(arg_list, int);

  /* The following statement is to demonstrate what would happen if there 
     is a mismatch in the 'type' specified and the data in the list  */
 //  str = va_arg(arg_list, char[MAX]);
 //  printf("%s\n", str);

  /* If the retrieved value is greater than current value of maximum */ 
  if(temp > maximum)
  {
   maximum = temp;
  } /* End of if */
 } /* End of while */

 /* The following statement is to demonstrate what would happen
    if there is a call for va_arg when the list is emplty */
 printf("Value is %d\n", va_arg(arg_list, int));
 
 /* undefining the list arg_list */
 va_end(arg_list);
 
 /* Returing the maximum of the arguments */
 return maximum;
}

/******************************************************************************
*       FUNCTION NAME   : main
*
*       DESCRIPTION     : Calls the max function and displays the result 
*
*       RETURNS         : Success or Failure
*******************************************************************************/
int main()
{
 int result = 0;
 /* Calling the function different number of arguments. Note that each call is
    ended with END. */
 result = args_maximum(5, -10, 45, 687, -193, END); 
 if(END != result)
 {
  printf("The maximum is %d\n", result);
 }
 result = args_maximum(1000,END); 
 if(END != result)
 {
  printf("The maximum is %d\n", result);
 }
 result = args_maximum(END); 
 if(END != result)
 {
  printf("The maximum is %d\n", result);
 }
 /* Here END is not mentioned. So the result is undefined.*/
 result = args_maximum(11,22,33,55,44,END);
 if(END != result)
 {
  printf("The maximum is %d\n", result);
 }
 /* Here -1 is an argument. This is the challenge here. -1 can not be there as
    an argument because it denotes the end of the arguments */
 result = args_maximum(11,-1,33,55,44,END);
 if(END != result)
 {
  printf("The maximum is %d\n", result);
 }
 return 0;
}

