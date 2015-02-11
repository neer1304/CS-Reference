/*************************************************************************
                        HEADER FILES
**************************************************************************/
#include <stdio.h>

/******************************************************************************
*
*       Function Name   : dump_line
*       Description     : Reads from a file till '\n' is reached
*			  The first line of the file would be read 
*       Returns         : Nothing
*
*******************************************************************************/
void dump_line( 
		FILE *fp_arg /* File pointer argument */ 
	      )
{
  int dummy; /* To get the value from fgetc */
  dummy = fgetc(fp_arg); /* Reads the first character from file */

  while(1) /* Infinite loop to read from the file */
  {
   /* Checks whether the file is empty. If this check is not there, there is
     a chance of infinite loop. There is no '\n' or '\r' if the file is empty */

   /* Comment this check and you can see that the 2nd call to dump_line
     leads to an infinite loop */
   if(EOF == dummy)   /* fgetc returns EOF on end of file */
   {
   return;
  }
  
   /* Uncomment this line to see the first line from the file */
 printf("%c", dummy);
   /* Checks for newline */
   if(dummy == '\n')
   {
    break;
   }
   dummy = fgetc(fp_arg); /* Reads the subsequent characters from the file */
  } /* End of while */
  printf("\n");
  return;
}

/******************************************************************************
*
*       Function Name   : main
*       Description     : Demonstrates how to read one line from a file
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 /* Local Variables */
 FILE *file_ptr = NULL;
 char ch = '\0';
 int num = 0; 
 /* Accepts an integer */
 printf("Enter an integer\n");
 scanf("%d", &num);

 /* Accepts a character. Observe that ch gets the '\n' from the stdin which is
    there because of the carriage return pressed while entering integer */
 printf("Enter a character\n");

 /* Uncomment this line after observing the first output. You can see that
    now ch also gets input from user */
 //dump_line(stdin); /* Function call get a line of input from stdin */
 scanf(" %c", &ch);
 printf("Number Entered is: %d , Character Entered is %c\n", num ,ch );

 /* Opens the file 'input' for reading */
 file_ptr = fopen("input", "r");
 if(NULL == file_ptr) /* Error check for fopen */
 {
  printf("'input' can not be open\n");
  return 0;
 }
 /* Tries to read the first line of the file. Since this file is empty,
 
   the control returns immediately from the dump_line function */ 
// dump_line(file_ptr);
 fclose(file_ptr); /* Closes the file */ 

 /* Opens the file 'test' for reading */
 file_ptr = fopen("test", "r");
 if(NULL == file_ptr) /* Error check for fopen */
 {
  printf("'test' can not be open\n");
  return 0;
 }
 
/* Reads the first line of the file. */
 dump_line(file_ptr);
 fclose(file_ptr); 
 
 return 0;
}
