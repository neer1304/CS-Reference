/*************************************************************************
                        HEADER FILES
**************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*************************************************************************
                        MACROS
**************************************************************************/
#define MAX 10

/******************************************************************************
*       Function Name   : main
*       Description     : Demonstates realloc
*       Returns         : Success or Failure
*******************************************************************************/
int main()
{
 /* Initializing a pointer to string */
 char *mess = "If you dont think about yourself at least once in your life time, you are going to miss the best comedy in life";

 char *str = NULL; /* Variable of dynamic memory allocation */
 int str_len = 0;  /* String length */
 
 /* Allocating memory to str. realloc on NULL pointer is equivalent to malloc */
 str = (char *)realloc(str, MAX * sizeof(char));
 if(NULL == str) /* Error handling for realloc */
 {
  printf("Memory Allocation Error\n");
  exit(EXIT_FAILURE);
 }

 /* Initializing the memory */
 memset(str, 0, MAX);

 /* Copying some string to str */
 strncpy(str, "Message", strlen("message"));
 /* Finding out the length of the string */
 str_len = strlen(mess);
 
 /* Checking whether enough memory is allocated */
 if(MAX - 1 >= str_len) /* Enough memory is allocated */
 {
  /* Copying the string. strncpy is used to avoid array over flow */ 
  strncpy(str, mess, MAX -1);
 }
 else /* Enough memory is not allocated */
 {
  /* Allocating more memory to str. It also demonstrates the need for 
     allocating memory for '\0'. So we have to allocate "str_len + 1" */

 /*  Comment the following line to observe another error. ABW occurs in
     strncpy below. This does not give an error. But at free, it leads to
     a crash because of it trying free unallocated memory */
  str = (char *)realloc(str, (str_len + 1) * sizeof(char));

  if(str == NULL) /* Error handling for realloc */
  {
   printf("Memory Allocation Error\n");
  }
  /* Initialising the newly allocated memory */
   memset(str, 0, str_len + 1);
  /* Copying the string. strncpy is used to avoid array overflow */ 
  strncpy(str, mess, str_len);
 }
 printf("The string is %s\n", str); 

 /* Freeing the memory */
 free(str);
 
 /* Getting rid of dangling pointer */
 str = NULL;
 return 0;

 /* There is another issue with realloc. What if relloc fails? str becomes 
    NULL and thus loses reference to the string it contained. So there is a
    loss of data. So better way to realloc is as follows. 
 char *temp = NULL;
 temp = (char *)realloc(str, (str_len + 1) * sizeof(char));
 if(temp == NULL) 
 {
  printf("Memory Allocation Error\n");
 }
 else
 {
  str = temp; // Making str point to new memory
 }
 */
 
}
