/***************************************************************************
*                       HEADER FILES
***************************************************************************/
#include "antonym_header.h"
#include "antonym_list.h"

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
ant_ret get_string(
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
ant_ret remove_newline(
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
ant_ret display_string(
                       IN char *str_input /* Input from user */
                      )
{
 int ret = 0;
 /* Displaying the string */
 ret = printf("%s\n", str_input);
 if(0 == ret) /*Error handling for printf */
 {
  return FAILURE;
 }
 return SUCCESS;
}

/****************************************************************************
*
*       Function Name   : search_antonym
*       Description     : Searches for antonym for a given word
*       Returns         : Success or Failure
*
****************************************************************************/
ant_ret search_antonym(
			IN char *word, /*Input string */ 
			OUT char **ptr_ant /* Points to the antonym */
		      )
{
 int index = 0; /* for loop index */
 int word_len = strlen(word); /* Length of the input string */
 int cmp_ret = 0; /* Return value from strcmp */
 if(0 == word_len) /* Checks whether input string is valid or not */
 {
  printf("Wrong Input\n");
  return FAILURE;
 }
 
 /* Searching for the antonym in the array */
 for(index = 0; index < MAX_LIST; index += 1)
 {
  /* Comparing input string with first element of the list */
  cmp_ret = strncmp(word, antonym_list[index][0], word_len);
  if(0 == cmp_ret) /* Checking for a match */
  {
   /* Assigning the antonym of matched string constant to the output variable */
   *ptr_ant = antonym_list[index][1];
   return SUCCESS;
  }
 }
 return FAILURE;
}

