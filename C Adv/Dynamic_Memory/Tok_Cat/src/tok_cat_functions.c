
/* NOTE: PLEAE OBSERVE HOW POINTERS ARE PASSED BY REFERENCE SO THAT ALL
         FUNCTIONS RETURNS SUCCESS OR FAILURE. THIS IS DONE WITH THE HELP
         OF PASS BY REFERENCE AND DYNAMIC MEMORY ALLOCATION 
*/

/*************************************************************************
*                       Header Files
**************************************************************************/
#include "tok_cat_header.h"

/*************************************************************************
*                       LOCAL MACROS
**************************************************************************/
#define IN
#define OUT

/*************************************************************************
*                       LOCAL FUNCTIONS
**************************************************************************/
static tok_ret str_rev(const char *, char **);

/******************************************************************************
*
*       Function Name  : str_rev
*       Description    : Reverses a string
*       Returns        : SUCCESS or FAILURE
*
*******************************************************************************/
static tok_ret str_rev(
			IN const char *input, /* Input string */
			OUT char **arg_rev /* Revesed String */
		      )
{
  int index = 0; /* Index for reversing */
  int len = strlen(input); /* Length of the input string */
  /* Allocating memory for reverse. "+1" is for '\0' */
  *arg_rev = (char *) malloc((len + 1) * sizeof(char));
  if(NULL == *arg_rev) /* Error handling for malloc */
  {
   printf("Error in malloc\n");
   return FAILURE;
  }
  len -= 1; /* Making 'len' points to the last char  */
  /* Reversing the string */
  while(len >= 0)
  {
    (*arg_rev)[index] = input[len]; /*Copy the last char as first char of rev*/
   index += 1;
   len -= 1;
  }
  (*arg_rev)[index] = '\0'; /* Appending '\0' at the end of reverse */
  return SUCCESS;
}

/******************************************************************************
*
*       Function Name  : tok_rev_concat
*       Description    : Tokenizes the input string and concatenate the reverse
*			 of each token
*       Returns        : SUCCESS or FAILURE
*
*******************************************************************************/
tok_ret tok_rev_concat(
			IN char input[], /* Input Array */	
			OUT char **arg_result /* Program output */
		      )
{
 char *word = NULL, /* Tokenized words */
      *rev_word = NULL, /* Reverse of each word */
      *temp = NULL; /* temporary variable for realloc */
 int len = 0, /* string length of each word */
     total_len = 1; /* Sum of lengths of all tokenized words. Initialized to 1
                       for '\0' */
 tok_ret ret_val = SUCCESS;
 word = strtok(input, " ,."); /* Tokenizing the first word */

 printf("Word is %s\n",word);

 if(NULL != word) /* Checking whether any word is there */
 {
    len = strlen(word); /* Length of the first word */
    total_len = total_len + len; /* Adding to total length */
   printf("The length of word is %d\n",total_len);
  
     /*Allocating memory for result variable */ 
    *arg_result = (char *)malloc(total_len * sizeof(char));
    if(NULL == *arg_result) /* Error handling for malloc */
    {
        printf("Malloc failed\n");
        return FAILURE;
    }
    /* Finding out the reverse of the first word */
    ret_val = str_rev(word, &rev_word);
    if(FAILURE == ret_val) /* Error handling for str_rev */
    {
        printf("Reversing failed\n");
        return FAILURE;
    }
    printf("Value in rev_word now is %s\n",rev_word);
    /*Copying the first string to result. strcpy is used because we allocated 
    enough memory. */ 
    strcpy(*arg_result, rev_word);
    printf("Value in arg_result is %s\n",*arg_result);

    /* Freeing the memory allocated to reverse after copying its value to result*/
    free(rev_word);
    rev_word = NULL;
 }
 // Loop to perform the taks on all words 
 while(NULL != word)
 { 
    printf("Inside while loop till word!=NULL..\n");
    word = strtok(NULL, " ,.");  // Tokenizing subsequent words 
    printf("Value of word in while loop is %s\n",word);
    if(NULL == word)
    {
       break;
    }
    len = strlen(word);  // String length of the word 
    printf("length of word in while loop is %d\n",len);
    if(len > 0) // Checking for a empty string 
    {
       total_len = total_len + len; // Adding string length to total length 
       printf("The value of total_len in while loop is %d\n",total_len);
 
        // Extending memory to contain the new string also 
      temp = (char *)realloc(*arg_result, total_len * sizeof(char));
       if(NULL == temp) // Error handling for realloc 
       {
          printf("realloc failed\n");
          return FAILURE;
       }
       *arg_result = temp; // Get rid of realloc issue 
   
        // Reversing the word 
       ret_val = str_rev(word, &rev_word);
       if(FAILURE == ret_val) // Error handling for str_rev 
       {
           printf("Reversing failed\n");
           return FAILURE;
       }

       // Concatenating the reverse of the new token to result. strcat is used
        //  because enough memory is allocated 
      strcat(*arg_result, rev_word);
      printf("Value of *arg_result in while loop is %s\n",*arg_result);
   // Freeing the memory of reverse after concatenating it to result 
      free(rev_word);
      rev_word = NULL;
  }
 }
 return SUCCESS;
}
