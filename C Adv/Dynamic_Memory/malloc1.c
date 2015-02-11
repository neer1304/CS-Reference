/*************************************************************************
			HEADER FILES
**************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*************************************************************************
			MACROS
**************************************************************************/
#define MAX 32

int main()
{
 char *str = NULL; /* Local Pointer Variable */

 /* Allocating memory using malloc.*/
 /* Inappropriate use. Dont take assumption on data type size.*/
 //str = (char *)malloc(MAX);
 str = (char *)malloc(MAX * sizeof(char));
 
 /* calloc also can be used. memory is set to 0 in calloc where as memory
    is not cleared in case of malloc */
 //str = (char *)calloc(MAX , sizeof(char));
   if(NULL == str) /* Error handling for malloc. It is mandatory */
   {
      printf("Malloc failed\n");
      exit(0);
   }
 
 /* Initializing memory. This is needed if we use malloc */
   memset(str, 0, MAX);

  /*A common mistake. After allocating memory to pointer, it is made point to
    a different memory. The reference to heap is lost and thus leading to 
    memory leak as well */
 /* Note : Comment these lines after observing the crash at free */
 str = "PRISM";
 printf("The string is %s\n", str);
 
 /*If the intention is to get an input from the user, there is no need of
    dynamic memory. An array is better. Allocate memory only if it leads
    to exact allocation of memory. Here the exact size is not known. So 
    better to use an array. It also reduces the time taken for calling
    dynamic memory allocation functions */
 // printf("Enter a string\n");
 // scanf("%s", str);
 // printf("The string is %s\n", str);

/*  Trying to change the string with strcpy. This will lead to crash as str
    is made point to constant string "PRISM".  */
 /* Note: Uncomment this to observe the crash. If you comment the above 2
          lines and uncomment these 2 lines, then the code works */
    //strcpy(str, "Nalanda");
   // printf("The string is %s\n", str);

 /* Freeing the memory to avoid memory leak. This will also lead to crash
    because as str is not pointing to heap. We can free memory only from
    heap. */
// free(str);
 str=NULL;
 return 0;
}
