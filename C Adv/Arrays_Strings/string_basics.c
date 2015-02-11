/***************************************************************************
*                       STANDARD HEADER FILES
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************************************************
*                       MACROS
***************************************************************************/
#define IN
#define OUT
#define MODI

#define NAMESZ 32

/****************************************************************************
*
*       Function Name   : remove_newline
*       Description     : Removes \n, if any, from the array
*       Returns         : Nothing
*
****************************************************************************/
static void remove_newline(
			   MODI char arg_input[] /* input string */
		          )
{
  /* Finds out the length of the string */
  size_t str_len = strlen(arg_input);
  
  /* Checks whether a '\n' is appended at the end */
  if('\n' == arg_input[str_len - 1])
  {
   arg_input[str_len - 1] = '\0'; /* Replaces '\n' with '\0' */
  }
}

/****************************************************************************
*
*       Function Name   : str_rev
*       Description     : Reverses the string
*       Returns         : Nothing
*
****************************************************************************/
static void str_rev(
                    IN char arg_input[], /* input string */
                    OUT char arg_rev[]  /* output string */
                   )
{
  /* Finds out the length of the string */
  size_t str_len = strlen(arg_input);
  
  
  /* Move the pointer to the last character */
  arg_input = arg_input + str_len - 1;

  /* 
   * This loop reverses the string by copying from the last to first 
   */
  while(str_len > 0) /* As far as string lenght is > 0 */
  {
   *arg_rev = *arg_input; /* Copying char by char from input to reverse */
   arg_rev += 1; /* Incrementing reverse pointer */
   arg_input -= 1; /* Decrementing input pointer */ 
   str_len--; /* Decrementing string length */
  }
  
  /* Forgetting append a '\0' at the end of a string is most common bug.*/
  *arg_rev = '\0'; /* Appending '\0' at the end */
}

/****************************************************************************
*
*       Function Name   : Palindrome_check
*       Description     : Checks whether a string is a palindrome
*       Returns         : Nothing
*
****************************************************************************/
static void palindrome_check(
			     IN char *arg_input, /* input string */
			     IN char *rev_input /* reverse of the input */
			    )
{
 int cmp_ret = 0; /* Stores the return value of strcmp */
 /* Compares 2 strings using strcmp. A better option is strncmp which has 
   array bound check, reverse. In this example it is not a problem as both
   the strings will be of same length. */
 cmp_ret = strcmp(arg_input, rev_input);
 // cmp_ret = strncmp(arg_input, rev_input, strlen(arg_input));
 if(0 == cmp_ret)
 {
  printf("%s is a palindrome\n", arg_input);
 }
 else
 {
  printf("%s is not a palindrome\n", arg_input);
 }
}

/****************************************************************************
*
*       Function Name   : main
*       Description     : Demonstration basic string concepts
*       Returns         : Success or Failure
*
****************************************************************************/
int main()
{
 char input[NAMESZ]; /* Variable to get input from user */
 char reverse[NAMESZ]; /* Variable to store reverse of string */
 char *fgets_ret = NULL; /* Return Value from fgets */


 /* Initializing the local variables */
 memset(input, 0, NAMESZ);
 memset(reverse, 0, NAMESZ);

 printf("Enter a string (Size < 32)\n");
 /* Observe the waring given by compiler for the following line.
    Compiler gives the warning since there is no array bound check for gets */
 /* Same issue is there with scanf also */
//  gets(input);
 
 /* fgets has an option to specify the array bound */ 
 fgets_ret = fgets(input, NAMESZ,stdin); 
 
 if(NULL != fgets_ret)
 { 
  /* fgets reads a maximum of NAMESZ-1 characters. Last position is reserved for
    '\0'. But there could be a '\n' before '\0' if the number of characters
    were less than NAMESZ-1. So we need to remove it */ 
  remove_newline(input);

  /* reversing the string */
  str_rev(input, reverse);
  printf("Original string is %s\n", input);
  printf("Reverse  string is %s\n", reverse);
 
  /* Checking for palindrome */
  palindrome_check(input,reverse);
 // printf("%d\n",sizeof(size_t));
 }
 else
 {
  printf("fgets failed\n");
 }
 return 0;
}
