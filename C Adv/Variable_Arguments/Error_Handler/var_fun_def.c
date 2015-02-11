/*****************************************************************************
*                       HEADER FILES
******************************************************************************/
#include "var_header.h"


/**************************************************************************
*
* 	FUNCTION NAME: error_handler
*
* 	DESCRIPTION: Prints error messages
*
* 	RETURNS: SUCCESS or FAILURE
**************************************************************************/
return_type error_handler(
			  int n_args, /* Number of arguments */
			  ... /* Designates variable number of arguments */
			 )
{
 va_list var_list; /* Variable to handle variable arguments */
 int err_code = 0; /* Variable to get the error code */
 char *err_msg = NULL; /* Variable to get the error message */
 char *file_name = NULL; /* Variable to get the file name */

 /* In this program we pass the number of non-fixed arguments as the fixed
    argument. Another way to determine how many arguments are to be retrieved */

 va_start(var_list,n_args); /* Macro call to initialise optional argument list*/
 err_msg = va_arg(var_list, char *); /* Reads the first optional argument */
 
 err_code = va_arg(var_list, int); /* Reads the second optional argument */

 /* Checks for the number of optional arguments */
 if(F_ERR_ARG == n_args) /* Checks for the number of optional arguments */
 { 			/* True for file related errors */
  file_name = va_arg(var_list, char *);   /* Reads the third argument */
  printf("%s %d  %s\n", err_msg, err_code, file_name); /* Displays error message, 
				error code and file name */
  va_end(var_list); /* Closes the variable argument list */
  return SUCCESS;
 }
 else if(M_ERR_ARG == n_args) /* True for memory related errors */
 {
  printf("%s %d", err_msg, err_code); /*Displays error message and error code */
  va_end(var_list); /* Closes the variable argument list */
  return SUCCESS;
 }
 return FAILURE;
}

/**************************************************************************
*
*       FUNCTION NAME: remove_newline
*
*       DESCRIPTION: Removes the '\n' at the end, if any
*
*       RETURNS: SUCCESS or FAILURE
**************************************************************************/
return_type remove_newline(
			    char *arg_str /* Input string */
			  )
{
 /* Finding out the lenght of the input string */
 int str_len = strlen(arg_str);
 
 /* Checks whether a '\n' is there or not. If yes, replaces that with '\0' */
 if('\n' == arg_str[str_len - 1])
 {
    arg_str[str_len - 1] = '\0';
 }
 return SUCCESS;
}
