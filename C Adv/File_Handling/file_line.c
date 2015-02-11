/*************************************************************************
                        HEADER FILES
**************************************************************************/
#include <stdio.h>
#include <string.h>

/*******************************************************************************
*                       MACROS
*******************************************************************************/
#define MAX  10
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
 char *input[SIZE] = {"PRISM\n", "Nalanda\n", "Aricent\n"};
 /* Variable to read from the file*/ 
 char output[MAX];
 int fputs_ret = 0; /* Return value from fputs */
 int fclose_ret = 0; /* Return value from fclose */
 int index = 0; /* for loop index */
 char *temp;
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
 while(!feof(infile))
 {
  /* Reads one line at a time. fgets stops after getting a maximum of MAX-1
     characters or encountering a '\n' or EOF. The last position is 
     reserved for '\0'. If fgets stops because of '\n' before getting MAX-1
     character then '\n' is also appended at the end. '\0' is appended
     after '\n'.*/ 
  temp = fgets(output, MAX, infile);

  /* Displaying the read string. Observe that an extra new line comes with
     the output. You may use gdb also to observe it. */
//if(temp!=NULL)
//{
  printf("%s\n", output);

  /* Printing the length of the string. Observe that the length is 1 more
     than expected in few cases. This is because of '\n'. strlen counts
     till '\0'. */
//  printf("%d\n", strlen(output));
//}
 }

 /* Following issues can be observed here. The issue of fgets reading and
    having an '\n' at the end, in some cases. The issue of the last line
    getting printed twice. The last line is getting printed twice because
    how feof works. feof checks whether EOF indicator is set by any file
    reading functions (here fgets). EOF indicator is set by file reading
    functions once they encounter an EOF.
    For e.g. fgets reads 'nt\n" in the 2nd last iteration. Now fgets
    stopped because of '\n'. EOF is yet to be encountered. So feof returns
    false. Next time, fgets stops because of EOF and returns NULL. No
    modification happened to the array passed to fgets. So the current
    content of the array ("nt\n") gets printed. Now feof returns true and
    the loop comes to an end. You may oberve this using gdb as well. */

  /* Note: The issue of last read data gets printed twice happens with
           other file reading functions as well. */

 /* Closes the file */
 fclose_ret = fclose(infile);
 if(0 != fclose_ret) /* Error check for fclose */
 {
  printf("Error in fclose\n");
  return 0;
 }
 return 0;
}
