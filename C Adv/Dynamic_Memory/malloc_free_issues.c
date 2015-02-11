/*************************************************************************
                        HEADER FILES
**************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*************************************************************************
                        MACROS
**************************************************************************/
#define MAX 50 
#define ROW 2

/******************************************************************************
*       Function Name   : str_cat
*       Description     : Concatenates two strings
*       Returns         : Nothing
*******************************************************************************/
/* This function is used to demonstrate malloc / free issues. The following 
   function is not a good programming example */
static char* str_cat(
			char (*arg_str)[MAX]
		    )
{
 /* Length of the first string */
 int len = strlen(arg_str[1]); 
 /* Allocating memory to temp. This is also going to create memory leak as
    temp is going to get the return value from strncat thus loosing the 
    reference to heap.*/
// char* temp ;

 char* temp = (char *)malloc(MAX * sizeof(char));
 if(NULL == temp)
 {
  printf("malloc Error\n");
  return NULL;
 }
 

 printf("str_cat: first string is : %s  \n", arg_str[0]);
 printf("\nstr_cat: Second string is : %s  \n", arg_str[1]);

 /* Concatenating 2 strings. strncat is used to avoid array overflow. Correct
    size is used in concatenation */
 temp = strncat(arg_str[0],arg_str[1], len - 1);

 /* This would result in array overshooting */
//  temp = strcat(arg_str[0], arg_str[1]);

 printf("\nstr_cat: Concantenated strings is : %s\n", temp);

 /* Returing reference to concatenation result */
 return temp;
}

/******************************************************************************
*       Function Name   : main
*       Description     : Demonstates some malloc / free issues
*       Returns         : Success or Failure
*******************************************************************************/
int main()
{
 char *str1 = NULL,
      *str2 = NULL;
 char mess[ROW][MAX] = {
			"I was not looking at you to enjoy your beauty",
			"Rather I was enjoying my own beauty in your eyes",
		       };
 
 /* Allocating memory for str1 */
 str1 = (char *)malloc(MAX * sizeof(char));
 if(NULL == str1)
 {
   printf("Malloc failed\n");
 }
 /* Initializing the str1 */
 memset(str1, 0, MAX);

 /* Copying some string to str1. strnpcy is used to avoid array overflow */
 strncpy(str1,"Love is absence of hate\n", MAX - 1);
 printf("str1 = %s\n", str1);

 /* Allocating memory for str2 */
 str2 = (char *)malloc(MAX * sizeof(char));
 if(NULL == str2)
 {
   printf("Malloc failed\n");
 }

 /* Initializing the str2 */
 memset(str2, 0, MAX);

 /* Copying some string to str2 */
 strncpy(str2,"Incompleteness in absence\n", MAX - 1);
 printf("str2 = %s\n", str2);
 
 /* This is a commmon bug: If we do this we lost reference to memory pointed by 
    str1, resulting in a memory leak. Both str1, and str2 are pointing to 
    the same memory */
 /* Uncomment this and observe the output */
//  str1 = str2;
//  printf("\nOutput after doing str1=str2..\n");
 // printf("str1 = %s\n", str1);
 // printf("str2 = %s\n", str2);

  /* Freeing the memory allocated to str1 */
//  free(str1);

 /* printf("After free\n");
  printf("str1 = %s\n", str1);
  printf("str2 = %s\n", str2);
*/

 /*  This is another bug. Using the memory which is already been freed. This is
     an example for dangling pointer. str1 is a dangaling pointer after it is 
     freed. Using a freed pointer leads to unwanted results. */
  
 // strncpy(str2, str1, MAX - 1);
 // printf("After strncpy str2 = %s\n", str2);
  
  /*One method to overcome dangling pointer is to make the pointer NULL after
     it is been freed */
 // free(str1);
  // str1 = NULL;
  /* This will lead to a crash as str1 is NULL - NULL pointer dereferencing */
  // strncpy(str2, str1, MAX - 1);
  /* So the better option is */ 
    if(NULL != str1)
    {
      strncpy(str2, str1, MAX - 1);
    }
     printf("str2 = %s\n", str2);

  /* Another bug - Trying to free the memory which is already been freed. This
     double free bug which would lead to a crash. But the practice of making
     a freed pointer as NULL, as explained above, will solve the issue becuase
     freeing a NULL pointer does not do anything */
  /* Uncomment this and observe the error */
  // free(str1);

  /* Or else, a better way of avoiding it */
    if(NULL != str1)
   {
    free(str1);
   }    
  
 /* Getting result returned by str_cat.*/  
 /* This is another common mistake. str2 is allocated a memory. But after the 
    execution of the below line, str2 will point to memory returned by str_cat.
    Thus loosing the reference to heap and resulting memory leak. If you want
    a pointer to point to memory returned by a function, there is no need of 
    memory allocation. */

 str2 = str_cat(mess); 
 
 printf("main: First string is : %s \n", mess[0]);
 printf("main: Second string is : %s \n", mess[1]);
 printf("main : Concantenated strings is : %s\n", str2);


 /* Freeing str2. This will lead to crash as we are not freeing memory from
    heap because str2 is pointing to the memory returned by str_cat */
//  free(str2);
 // str2 = NULL;


 return 0;
}

