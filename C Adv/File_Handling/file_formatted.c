/*************************************************************************
                        HEADER FILES
**************************************************************************/
#include <stdio.h>
#include <string.h>

/*******************************************************************************
*                       MACROS
*******************************************************************************/
#define MAX 20

/******************************************************************************
*
*       Function Name   : main
*       Description     : Demontration of fscanf and fprintf 
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 FILE *infile = NULL; /* file pointer */
 char str[MAX]; /* Array to read from the file */
 int num = 0; /* Reads an integer from file */
 int ret = 0; /* Return value from fclose */

 memset(str, 0, MAX); /* Initializing the array */

 /* Opens the file for writing */
 infile = fopen("data", "w");
 if(NULL == infile) /* Error check for fopen */
 {
  printf("File can not be opened\n");
  return 0;
 }

 /* Formatted writing using fprintf */
 /* Conversion specifiers are used same as scanf */
 fprintf(infile, "%s", "ABC 123 XY");
 fprintf(infile, "\n%s", "PQR 345 LM");

 /* Closing the stream.*/
 /* Uncomment this line to observe what happens if the file is not closed
    between two different operations on files */
 ret = fclose(infile);
 if(0 != ret)
 {
  printf("fclose failed\n");
  return 0;
 }

 /* Opens the file for reading */
 infile = fopen("data", "r");
 if(NULL == infile)
 {
  printf("File can not be opened\n");
  return 0;
 }

 /* Reads from the file using "%s" - a word at a time. We get only the first
    word as fscanf stops at any white space character - space, tab or new line. */
 fscanf(infile, "%s", str);
 fprintf(stdout,"%s\n", str);  //print on the screen using fprintf

 /* Reads an integer from the file */
 fscanf(infile, "%d", &num);
 fprintf(stdout,"%d\n", num);
fscanf(infile,"%s", str);
fprintf(stdout,"%s\n" , str);
 /* Closes the stream */
 ret = fclose(infile);
 if(0 != ret)
 {
  printf("fclose failed\n");
  return 0;
 }
 return 0;
}
