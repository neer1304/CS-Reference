/***************************************************************************
*                       STANDARD HEADER FILES
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************************************************************************
*			MACROS
**************************************************************************/
#define SIZE 80
#define MAX 8 /* You may change this to a larger value */

#define IN
#define OUT

#define str_ret int
#define SUCCESS 1
#define FAILURE 0

/****************************************************************************
*
*       Function Name   : display_words
*       Description     : Display words from an array of strings
*       Returns         : Success or Failure
*
****************************************************************************/
static str_ret display_words(
			     IN char *arg_words[MAX], /* Array of words */
			     IN int size /* No of the words in the array */
			    )
{
 int index = 0; /* for loop index */
 if(size <= 0) /* Error handling for argument */
 {
  return FAILURE;
 }
 printf("Total Words is %d\n", size);
 /* Displaying the tokenized words */
 for(index = 0; index < size; index += 1)
 {
  printf("%s\n", arg_words[index]);
 } 
 return SUCCESS;
}

/****************************************************************************
*
*       Function Name   : store_words
*       Description     : Tokenizes the words an stores into an array
*       Returns         : Success or Failure
*
****************************************************************************/
static str_ret store_words(
			   IN char arg_str[50], /* Input string */
			   OUT char *arg_words[MAX], /* Output array */
			   OUT int *word_count /* No of words */
			  )
{
 int index = 0; 
 if(NULL == arg_str) /* Error handling for input argument */
 {
  return FAILURE;
 }

 /* Tokenizing the first word */
 arg_words[index] = strtok(arg_str, " .,");

 /* Tokenizing algorithm. strtok returns NULL at input string end */
 while (NULL != arg_words[index])
 {
   index += 1;

   /* Tokensing the remaining words.*/ 
//    arg_words[index] = strtok(arg_str, " .,");
   
   /* Comment the above line and uncomment the below strtok call after
      observing the first output */
   /* First argument must be NULL for subsequent calls to strtok */
   arg_words[index] = strtok(NULL, " .,");
  
   /* Check for ABW */
   if(MAX == index)
   {
    printf("Array limit reached\n");
    break;
   }
 }
 *word_count = index; /* Updates number of words */
 return SUCCESS; 
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
 /* Initialising an array */
 char str[SIZE] = "Newyork Pasadena Seattle, Gurgaon Bangalore Chennai."; 
 
 /* This mus the done at the end. Uncomment this line and comment the above 
    line. The program crashes because strtok is trying to change a const */

 /* Initializing an pointer to a consant */
 char *words[MAX]; /* Array of pointers to store the tokenized words */
 int no_of_words = 0; /* Stores the total number of words */
 str_ret ret_value = SUCCESS; /* Return value from function */
 
 /* Initializing the array of pointers */ 
 memset(words,0,MAX*sizeof(char *));
 
 printf("Original string before tokenization is %s\n", str); 

 /* Function call to tokenize the words */
 ret_value = store_words(str, words, &no_of_words);
 if(FAILURE == ret_value) /* Error handling */
 {
  printf("Function Failed\n");
  exit(FAILURE);
 }

 /* Displaying the tokenized words */
 ret_value = display_words(words, no_of_words);

 /* Observe the output here. The challenge with strtok is that it modifies
    the input string. It is better to write our own tokenizer */
 printf("Original string after tokenization is %s\n", str); 
 return 0;
}
