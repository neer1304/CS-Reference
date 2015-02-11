/*****************************************************************************
*                       Header Files
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*****************************************************************************
*                       Macros
******************************************************************************/
#define MAX 32

/*****************************************************************************
*                       User Defined types
******************************************************************************/
typedef struct
{
 int id; /* Id of student */
 char *name; /* First name of student */
}sample;
/******************************************************************************
*
*       Function Name   : main
*       Description     : Demonstrates allocation of memory for a structure
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 sample *student = NULL; /* Pointer to the structure */
 
 /* Allocating memory for structure pointer */
 student = (sample *)malloc(sizeof(sample));
 if(NULL == student) /* Error check for malloc */
 {
  printf("Malloc failure\n");
  return 0;
 }
 
 /* Allocating memory for name field of structure. One common mistake here is
    forgetting to allocate memory for structure elements. Comment the
    below allocation and error check and observe the output */
 student->name = (char *)malloc(MAX * sizeof(char));
 if(NULL == student->name)
 {
  printf("Malloc failure\n");
/*  Exit point. So deallocate previously allocated memory */

  free(student);
  student = NULL;
  return 0;
 }
 
 /* Initializing the allocated memory */
 memset(student->name, 0, MAX);
 /* Getting input from user */ 
 printf("Enter the id\n");
 scanf("%d", &student->id);
 printf("Enter the name\n");
 /* Ideally it should have been an fgets :-)*/
 scanf("%s", student->name);

 /* Displaying user input */
 printf("Id is %d\t name is %s\n", student->id, student->name);

 /* Deallocating the memory allocated for structure field. A common mistake here
    is first freeing the memory for structure and then trying to free the memory
    for stucture elements. Comment the below 2 lines and uncomment the lines at
    end. Observe the output with valgrind */
 free(student->name);
 student->name = NULL;

 /* Deallocating memory allocated for structure */
 free(student);
 student = NULL;
 //free(student->name);
 // student->name = NULL;
 return 0;
}



