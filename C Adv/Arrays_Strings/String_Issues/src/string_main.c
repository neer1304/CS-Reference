/***************************************************************************
*                       HEADER FILES
***************************************************************************/
#include "string_header.h"

/****************************************************************************
*
*       Function Name   : main
*       Description     : Demonstration some string issues
*       Returns         : Success or Failure
*
****************************************************************************/
int main()
{
 char input[MAX]; /* Input variable */
 char cpy_str[SZ]; /* To get the copy */ 

 str_ret ret_val = SUCCESS;
 /* An array of strings initialised */
 char msg[][MAX] = {"Don't walk in front of me", "I am not going to follow"};
 memset(input,0,MAX); /* Initializing the array */
 memset(cpy_str,0,SZ); /* Initializing the array */

 /* Getting the input from user */
 printf("Enter a string\n");
 ret_val = get_string(input);
 if(FAILURE == ret_val)
 {
  printf("Function Failure\n");
  exit(EXIT_FAILURE); 
 }
 
 /* Removes the '\n', if any */
 ret_val = remove_newline(input);
 if(FAILURE == ret_val)
 {
  printf("Function Failure\n");
  exit(EXIT_FAILURE);
 }

 /* Displaying the string */
 printf("\nDisplay String before copy\n");
 ret_val = display_string(input);
 if(FAILURE == ret_val)
 {
  printf("Function Failure\n");
  exit(EXIT_FAILURE);
 }

 ret_val = str_cpy(input, cpy_str);
 if(FAILURE == ret_val)
 {
  printf("Function Failure\n");
  exit(EXIT_FAILURE);
 }

 /* Displaying the string after copy */ 
 printf("\nDisplay String after  copy\n");
 ret_val = display_string(input);
 if(FAILURE == ret_val)
 {
  printf("Function Failure\n");
  exit(EXIT_FAILURE);
 }
 
 /* Displaying the copied string */
 printf("\nCopied  String \n");
 ret_val = display_string(cpy_str);
 if(FAILURE == ret_val)
 {
  printf("Function Failure\n");
  exit(EXIT_FAILURE);
 }

 
 /* Displaying the string */
 ret_val = display_string(msg[0]);
 if(FAILURE == ret_val)
 {
  printf("Function Failure\n");
  exit(EXIT_FAILURE);
 }
 
 ret_val = display_string(msg[1]);
 if(FAILURE == ret_val)
 {
  printf("Function Failure\n");
  exit(EXIT_FAILURE);
 }

 ret_val = str_cat(msg[1],msg[0]); 
 if(FAILURE == ret_val)
 {
  printf("Function Failure\n");
  exit(EXIT_FAILURE);
 }

 /* Displaying the string */
 ret_val = display_string(msg[0]);
 if(FAILURE == ret_val)
 {
  printf("Function Failure\n");
  exit(EXIT_FAILURE);
 }

 ret_val = display_string(msg[1]);
 if(FAILURE == ret_val)
 {
  printf("Function Failure\n");
  exit(EXIT_FAILURE);
 }
 return 0;
}
