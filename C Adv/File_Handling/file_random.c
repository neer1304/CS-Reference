/*************************************************************************
                        HEADER FILES
**************************************************************************/
#include <stdio.h>
#include <string.h>

/*******************************************************************************
*                       MACROS
*******************************************************************************/
#define SIZE 32
#define MAX 4

/******************************************************************************
*
*       Function Name   : main
*       Description     : Demontration of fseek, ftell and rewind
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 FILE *file_ptr = NULL; /* File pointer */
 /* Strings to be written into the file */
 char *strings[MAX] = {"This", "is", "a", "test"};
 int index = 0; /* for loop index */
 long int skipback = 0L; /* Return value from ftell */
 int ret_val = 0; /* Return value from functions */
 char data[SIZE]; /* Array to read from the file */
 
 /* Opening the file for writing */
 file_ptr = fopen("myfile", "w");
 if(NULL == file_ptr)
 {
  printf("Error in opening the file\n");
  return 0;
 }
 
 /* Writing the strings into the file */
 for(index = 0; index < MAX; index += 1)
 {
  /* Note the space after %s. This is added so that fscanf reads word by word */
  ret_val = fprintf(file_ptr,"%s ",strings[index]);
  if(0 == ret_val) /* Error check for fprintf */
  {
   printf("Writing failed\n");
  }
 }
 /* Closing the file */
 ret_val = fclose(file_ptr);
 if(0 != ret_val)
 {
  printf("Closing the file failed\n");
  return 0;
 }
 
 /* Opening the file for reading */ 
 file_ptr = fopen("myfile", "r");
 if(NULL == file_ptr)
 {
  printf("Error in opening the file\n");
  return 0;
 }

 /* Demonstrating fseek, ftell and rewind */ 
 while(1)
 {
  memset(data,0,SIZE); /* Initializing the array */
  
  /* Getting the current offset.*/
  skipback = ftell(file_ptr);
  printf("Current position is %ld\n", skipback);

  /* Reads one word from the file */
  ret_val = fscanf(file_ptr, "%s", data);
  /* Checks whether EOF is reched or not . If yes, fscanf returns EOF */
  if(EOF == ret_val) /* EOF reached */
  {
   printf("No more strings\n");
   break;
  }

  /* Prints the word read from file */
  printf("Data is %s\n", data);
 
  /* Moves the position indicator by value of 'skipback' from the begining. 
     Initially it will be moved by 0. As and when fscanf executes, position
     indicator moves by number of bytes read. So every time position indicator
     is set by the number of characters read. So this loop reads every word
     twice. Comment this line and observe the output */ 
  ret_val = fseek(file_ptr, skipback, SEEK_SET);
  if(-1 == ret_val) /* Error check for fseek */
  {
   printf("fseek failed\n");
  }

  /* rewind sets the position indicator to the begining. Uncomment the below
     line and observe that program executes infinitely */
//  rewind(file_ptr);
  /* Reads one word from the file */
  ret_val = fscanf(file_ptr, "%s", data);
  /* Checks whether EOF is reched or not . If yes, fscanf returns EOF */
  if(EOF == ret_val) /* EOF reached */
  {
   printf("No more strings\n");
   break;
  }
  /* Prints the word read from file */
  printf("Data is %s\n", data);
 }
 return 0;
}
