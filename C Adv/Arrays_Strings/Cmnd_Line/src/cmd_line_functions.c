/*************************************************************************
*                       Header Files
**************************************************************************/
#include "cmd_line_header.h"

/*************************************************************************
*                       LOCAL MACROS
**************************************************************************/
#define IN
#define OUT

/*************************************************************************
*                       LOCAL FUNCTIONS
**************************************************************************/
static cmd_ret str_copy(const char *, char *);
static cmd_ret str_cat(const char *, const char *, char *);

/******************************************************************************
*
*       Function Name  : process_args
*       Description    : processes the command line arguments and invokes
*			 appropriate functions
*       Returns        : SUCCESS or FAILURE
*
*******************************************************************************/
cmd_ret process_args(
		      IN char *arg_val[], /* Command line arguments */
		      OUT char *arg_res /* The result string */
		    )
{
 int option = 0; /* Command line option */
 cmd_ret ret_val = SUCCESS; /* Return value from function */

 /* Coverting the string to number. This is needed because the command line
    argument is an array of character pointer. */
 option = atoi(arg_val[1]);

 /* To invoke the appropriate function depends on the option */
 switch(option)
 {
   case 1: /* Option to copy the string */

        /* Function call to copy the string */
	ret_val = str_copy(arg_val[2], arg_res);
	if(FAILURE == ret_val)
	{
	 printf("Copy Failed\n");
	}
	break;
   case 2: /* Option to concatenate */

	/* Checks whether the 3rd argument is there or not */
	if(NULL == arg_val[3]) /* 3rd argument missing */
 	{
	 printf("There is no second string for concatenation \n");
	 ret_val = FAILURE;
	}
	else /*Both the arguments are there */
	{
	 /* Function call to concatenate two strings */
	 ret_val = str_cat(arg_val[2], arg_val[3], arg_res);
	 if(FAILURE == ret_val) /* Error check for str_cat */
	 {
	  printf("Concatenation Failed\n");
	 }
	}
	break;
   default: /* Invalid options */
	printf("Invalid option provided\n");
	ret_val = FAILURE;
	break;
 }
 return ret_val;
}

/******************************************************************************
*
*       Function Name  : str_copy
*       Description    : copies the string to another
*       Returns        : SUCCESS or FAILURE
*
*******************************************************************************/
static cmd_ret str_copy(
			IN const char *arg_str, /* String to be copied */
			OUT char *arg_copy /* Result of Copy */
		       )
{
 char *ret = NULL; /* return value from strncpy */
 cmd_ret ret_val = SUCCESS; /* Return value from function */
 int len = strlen(arg_str); /* Length of the input string */

 if(len > MAX) /* Checking whether array is large enough */
 {
  printf("Large string, copying not possible\n");
  ret_val = FAILURE;
 }
 else /* Array is large enough */
 {
  /* Copying the string */
  ret = strncpy(arg_copy, arg_str, len);
  if(NULL == ret) /* Error handling for strncpy */
  {
    printf("strncpy failed\n");
    ret_val = FAILURE;
  }
 }
 return ret_val; 
}

/******************************************************************************
*
*       Function Name  : str_cat
*       Description    : Concatenates two strings 
*       Returns        : SUCCESS or FAILURE
*
*******************************************************************************/
static cmd_ret str_cat(
			IN const char *first_str, /* First string */
			IN const char *second_str, /* Second string */
			OUT char *arg_res /* Result of Concatenation */
		      )
{
 int len_first = 0, /* Stores the length of first string */ 
     len_second = 0, /* Stores the length of second string */ 
     total_len = 0; /* Sum of lengths of strings */
 cmd_ret ret_val = SUCCESS; /* Return value from function */
 char *ret = NULL; /* Return value from strncat */

 len_first = strlen(first_str); /*Length of the first string */

 /* Copying the first string to result */
 ret_val = str_copy(first_str, arg_res);
 if(FAILURE == ret_val) /* Error handling for str_copy */
 {
  printf("Larger Strings, concatenation not possible\n");
 }
 else /* str_copy is successfull */
 {
  len_second = strlen(second_str); /* Length of the second string */
 
  /* Finding total length of the strings. 1 is added for '\0' */ 
  total_len = len_first + len_second + 1;

  if(total_len > MAX) /* Checking whether array is large enough */
  {
   printf("Larger Strings, concatenation not possible\n");
   ret_val = FAILURE;
  }
  else /* Array is large enough */
  {
   /* Concatenating the strings */
   ret = strncat(arg_res, second_str, len_second);
   if(NULL == ret) /* Error check for strncat */
   {
     printf("strncat failed\n");
     ret_val = FAILURE;
   }
  }
 }
 return ret_val;
}

