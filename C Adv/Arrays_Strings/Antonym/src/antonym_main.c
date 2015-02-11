/***************************************************************************
*                       HEADER FILES
***************************************************************************/
#include "antonym_header.h"

/****************************************************************************
*
*       Function Name   : main
*       Description     : Finds out antonym of a string
*       Returns         : Success or Failure
*
****************************************************************************/
int main()
{
 char input[MAX]; /* Input Variable */
 char *antonym = NULL; /* Output Variable */
 ant_ret ret_val = SUCCESS; /* Function return value */

 /* Initializing local variable */
 memset(input, 0, MAX);

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
 
 /* The following function demonstrates how a pointer can be passed by
    refence. Address of pointer is passed and the function argument is
    a double pointer */ 
 /* Seaching for an antonym for the given string */
 ret_val = search_antonym(input, &antonym);
 if(FAILURE == ret_val)
 {
  printf("No Antonym for\n");
  ret_val = display_string(input);
 }
 else
 {
  printf("Antonym for\n" );
  ret_val = display_string(input);
  ret_val = display_string(antonym);
 }
 return 0;
}
