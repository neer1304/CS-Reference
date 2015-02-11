/*****************************************************************************
*                       HEADER FILES
******************************************************************************/
#include "var_header.h"

/*************************************************************************
			LOCAL MACROS
*************************************************************************/
#define MSG_SIZE 25
#define NAME_SIZE 33
/* Uncomment the follwing line see a an malloc error. Please ignore the 
   warnings */

 #define NAME_SIZE 33333333333

/*************************************************************************
			GLOBAL VARIABLES
*************************************************************************/
static char error_msg[][MSG_SIZE] = {
                             "File not found",
                             "Memory not available",
                             }; /* Array of error messages */

/**************************************************************************
*
* FUNCTION NAME: main()
*
* DESCRIPTION: main function for variable arguments program
*
* RETURNS: SUCCESS or FAILURE
**************************************************************************/

int main()
{
 FILE *infile = NULL; /* Variable to for file */
 return_type result = FAILURE; /* Variable to store the return value */
 char *filename = NULL; /* Variable get the file name */
 return_type str_ret = FAILURE; /* Variable to get ret value after \n removal */

 /* Dynamic memory allocation for file name */
 filename = (char *) malloc(NAME_SIZE * sizeof(char));

 if( NULL == filename) /* Error handling for malloc */
 {
   /* Function to call display appropriate error message */
   result = error_handler(M_ERR_ARG, error_msg[1], MEMORY_ERROR);

   if(FAILURE == result) /* Comparing the return value of function */
   {
     printf("\nError handler failed\n");
   }
   else
   {
     printf("\nError handler successfull\n");
   }
   exit(EXIT_FAILURE);
 }  

 /* Accepting the file name from the user */
 printf("Enter the file name <size <= 32>\n");
 filename = fgets(filename, NAME_SIZE, stdin);
 /* Removes the '\n', if any */
 str_ret = remove_newline(filename);
 if(FAILURE == str_ret)
 {
  free(filename); /* Freeing memory before exit */
  filename = NULL;
  exit(EXIT_FAILURE);
 }

 /* Opens the file entered by user */
 infile = fopen(filename, "r"); 

 if(NULL == infile) /* Error handling for fopen */
 {
   /* Function to call display appropriate error message */
   result = error_handler(F_ERR_ARG, error_msg[0], FILE_ERROR, filename);

   if(FAILURE == result) /*Comparing the return value of function */
   {
     printf("\nError handler failed\n");
   }
   else
   {
     printf("\nError handler successfull\n");
   }
   free(filename); /* Freeing the memory */
   filename = NULL;
   exit(EXIT_FAILURE);
 }
 
 fclose(infile); /* Closes the file */
 free(filename); /* Freeing the memory */
 filename = NULL;
 exit(EXIT_SUCCESS);
}

