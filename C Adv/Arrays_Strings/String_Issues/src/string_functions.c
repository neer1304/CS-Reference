/***************************************************************************
*                       HEADER FILES
***************************************************************************/
#include "string_header.h"

/***************************************************************************
*                       LOCAL MACROS
***************************************************************************/
#define IN
#define OUT
#define MODI

/***************************************************************************
*                       FUNCTION DEFINITIONS
***************************************************************************/

/****************************************************************************
*
*       Function Name   : get_string
*       Description     : gets the input string from user
*       Returns         : Success or Failure
*
****************************************************************************/
str_ret get_string(
		   MODI char *str_input /* Input from user */
		  )
{
 char *ret = NULL;
 /* Getting input from user */
 ret = fgets(str_input, MAX, stdin);
 if(NULL == ret) /* Error Handling for fgets */
 {
  return FAILURE;
 }
 return SUCCESS; 
}

/****************************************************************************
*
*       Function Name   : remove_newline
*       Description     : Removes \n, if any, from the array
*       Returns         : Success or Failure
*
****************************************************************************/
str_ret remove_newline(
                           MODI char *arg_input /* input string */
                       )
{
  if(NULL == arg_input) /* Error handling for argument */
  {
   return FAILURE;
  }

  /* Finds out the length of the string */
  size_t str_len = strlen(arg_input);

  /* Checks whether a '\n' is appended at the end */
  if('\n' == arg_input[str_len - 1])
  {
   arg_input[str_len - 1] = '\0'; /* Replaces '\n' with '\0' */
  }
  return SUCCESS;
}

/****************************************************************************
*
*       Function Name   : display_string
*       Description     : Displays a string
*       Returns         : Success or Failure
*
****************************************************************************/
str_ret display_string(
                       IN char *str_input /* Input from user */
                      )
{
 int ret = 0;
 /* Displaying the string */
 ret = printf("The string is: %s\n", str_input);
 if(0 == ret) /*Error handling for printf */ 
 {
  return FAILURE;
 }
 return SUCCESS;
}

/****************************************************************************
*
*       Function Name   : str_cpy
*       Description     : Copies a string
*       Returns         : Success or Failure
*
****************************************************************************/
str_ret str_cpy(
                 IN char *input_str, /* input string */
                 OUT char *copy_str /* output string */
               )
{
 char *ret = NULL;
 /* Error handling for arguments */
 if(NULL == input_str || NULL == copy_str)
 {
  return FAILURE;
 } 

 /* Copying a string to another. Comment this after observing the output.
    Use strncpy instead. */
// ret = strcpy(copy_str, input_str);

 /* There is no array bound check for strcpy. This could lead to ABR/ABW bugs
    So it is better to use strncpy  */
 ret = strncpy(copy_str, input_str, SZ - 1);
 
 /* Execute the following and observe the output. You could see the issue with
    not having a '\0' at the end. It is programmer's responsibility to specify
    the correct size */
  ret = strncpy(copy_str, input_str, SZ);
  copy_str[SZ] = '\0';
 if(NULL == ret) /* Error handling for strcpy */
 {
  return FAILURE;
 }
 return SUCCESS;
}

/****************************************************************************
*
*       Function Name   : str_cat
*       Description     : Concatenates 2 strings
*       Returns         : Success or Failure
*
****************************************************************************/

str_ret str_cat(
                IN char *source, /* Source String */
		MODI char *dest /* Destination String */
	       )
{
 char *ret = NULL;
 size_t source_len = strlen(source);
 /* Error handling for arguments */
 if(NULL == source || NULL == dest)
 {
  return FAILURE;
 }
 /* Concatenating one string to another. Comment this after observring the 
    output. You can see that the arrays are getting overlapped. This is 
    another bug. strcat also does not have array bound check. So use strncat */
// ret = strcat(dest,source);
 
 /* strncat makes sure that the array does not over shoot. It is programmer's
    responsibility to specify the correct size :-) */
  ret = strncat(dest,source, MAX - source_len - 2);
 if(NULL == ret)
 {
  return FAILURE;
 }
 return SUCCESS;
}


