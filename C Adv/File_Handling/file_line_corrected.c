/*************************************************************************
                        HEADER FILES
**************************************************************************/
#include <stdio.h>
#include <string.h>

/*******************************************************************************
*                       MACROS
*******************************************************************************/
#define MAX 10
#define SIZE 3

/******************************************************************************
*
*       Function Name   : main
*       Description     : Demontration of fgets and fputs
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 FILE* infile = NULL; /* File pointer */
 /* String to be written into the file */
 char *input[SIZE] = {"Mumbai\n", "Delhi\n", "Kanpur\n"};
 /* Variable to read from the file*/ 
 char output[MAX];
 char* fgets_ret = NULL; /* Return value from fgets */
 int fputs_ret = 0; /* Return value from fputs */
 int fclose_ret = 0; /* Return value from fclose */
 int index = 0; /* for loop index */
 int str_len = 0; /* length of the line */

 memset(output, 0, MAX); /* Initializing the array */

 /* Opens the file 'sample' for writing */
 infile = fopen("sample", "w"); 
 if(NULL == infile) /* Error check for fopen */
 {
   printf("File can not be opened\n");
   return 0;
 }
 
 /* To write SIZE strings into the file */
 for(index = 0; index < SIZE; index += 1)
 {
  /* Writing one string to the file */
  fputs_ret = fputs(input[index], infile);
  /* fputs returns EOF on error */
  if(EOF == fputs_ret) /* Error check for fputs */
  {
   printf("Error in fputs\n");
   /* This is an exit point on error with fputs. We need to close the file
      before terminating the program */
   fclose_ret = fclose(infile); /* Closing the file */
   if(0 != fclose_ret) /* Error check for fclose */
   {
    printf("Error in fclose\n");
    return 0;
   }
   return 0;
  }
 }

 /* Closing the file */
 fclose_ret = fclose(infile);
 if(0 != fclose_ret) /* Error check for fclose */
 {
  printf("Error in fclose\n");
  return 0;
 }

 /* Opening the file 'sample' for reading */
 infile = fopen("sample", "r");
 if(NULL == infile) /* Error check for fopen */
 {
   printf("File can not be opened\n");
   return 0;
 }

 /* Reading from the file and displays it.*/
 while(0 == feof(infile))
 {
  /* Reads one line at a time */
  fgets_ret = fgets(output, MAX, infile);
  /* fgets returns NULL if EOF is already reached. Note that fgets does 
     not return NULL even if EOF is reached after reading at least one
     character. */
  if(NULL == fgets_ret) /* Checks the return value of fgets and breaks */
  {
   break;
  }
  /* Finding out the length of the string */
  str_len = (int)strlen(output);
  
  /* Removes the '\n' read by fgets, if any */ 
  if('\n' == output[str_len - 1])
  {
    output[str_len - 1] = '\0';
  }
  
  /* Displaying the string. No extra lines this time */
  printf("%s\n", output);

  /* Displaying the length of the string. String length is as expected now */
 // printf("%d\n", (int)strlen(output)); 

 }

 /* Closes the file */
 fclose_ret = fclose(infile);
 if(0 != fclose_ret) 
 {
  printf("Error in fclose\n");
  return 0;
 }
 return 0;
}
