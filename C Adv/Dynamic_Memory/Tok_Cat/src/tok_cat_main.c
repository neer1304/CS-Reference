/*****************************************************************************
*                       Header Files
******************************************************************************/

#include "tok_cat_header.h"

/******************************************************************************
*
*       Function Name   : main
*       Description     : tokenizes a string, finds out the reverse of them and
*			  concatenates them
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
  /* Initializing the input array */
  char input[] = "The gigantic ice berg that hit the Titanic in the Atlantic";
  /* Variable store the result */
  char *result = NULL;
  /* Return value from function */
  tok_ret ret_val = SUCCESS;

  /* Funtion call to tokenize, reverse and concatenate */
  ret_val = tok_rev_concat(input,&result);
  if(SUCCESS == ret_val)
  {
   printf("Operation Successfull\n");
   printf("The Final string is %s\n", result);
  }
  else
  {
   printf("Operation Failed\n");
   printf("The Final string is %s\n", result);
  }
  
  /* Free the memory allocated to result */
  free(result);
  result = NULL;

  return 0;
}
