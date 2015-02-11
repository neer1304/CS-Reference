/*************************************************************************
                        HEADER FILES
**************************************************************************/
#include <stdio.h>
#include <ctype.h>

/*******************************************************************************
*                       MACROS
*******************************************************************************/
#define file_ret int
#define FAILURE 0
#define SUCCESS 1

/*******************************************************************************
*                       FUNCTION PROTOTYPES
*******************************************************************************/
static file_ret open_file(FILE **, char *, char *);
static file_ret copy_file(FILE **, FILE **);
static file_ret close_file(FILE **);
static file_ret display_file(FILE **);

/******************************************************************************
*
*       Function Name   : open_file
*       Description     : opens a file as specified by name and mode
*       Returns         : Success or Failure
*
*******************************************************************************/
static file_ret open_file(
			  FILE **arg_file, /* Address of file pointer */
			  char *arg_name,  /* Name of the file */
			  char *arg_mode   /* Opening mode of file */
			 )
{
 /* Opening the input file */
 *arg_file = fopen(arg_name, arg_mode);

 /* It is mandatory to check the return value of fopen */
 if(NULL == *arg_file) /* Error check for fopen */
 {
  return FAILURE;
 }
 return SUCCESS; 
}

/******************************************************************************
*
*       Function Name   : close_file
*       Description     : Closes a file
*       Returns         : Success or Failure
*
*******************************************************************************/
static file_ret close_file(
                           FILE **arg_file /* Address of file pointer */
                          )
{
 int ret = 0; /* Return value from function */

 ret = fclose(*arg_file); /* Closing the file */
 /* fclose could fail if the argument is not correct. 
    On error it returns EOF.*/
 if(0 != ret) /* Error check for fclose */
 {
  return FAILURE;
 }
 /* Closing an already closed the file would lead to undefined behaviour.
    Uncomment the following line and observe the output */
 //fclose(*arg_file);
 return SUCCESS;
}

/******************************************************************************
*
*       Function Name   : copy_file
*       Description     : Copies the content of one file into another
*       Returns         : Success or Failure
*
*******************************************************************************/
static file_ret copy_file(
                          FILE **in_file, /* Address of input file pointer */
			  FILE **out_file /* Address of output file pointer */
                         )
{
 int ret = 0; /* Return value from function */
 
 char file_char = '\0', /* To read from a file */
      out_char = '\0'; /* To write into the file */

 /* Reads all characters from the file */
 while(1)
 {
  /* Checks whether EOF is reached. EOF is an indicator to say that end-of-file
     is reached. EOF is not a character in the file. It is set when the any of
     file reading functions reaches end-of-file. */
  if(feof(*in_file) != 0)
  {
   break;
  }
  /* Reads one character from the file. fgetc returns int. We need to typecast
     it into char */
  file_char = (char)fgetc(*in_file);
  /* Checks whether the read character is alphabet or not */
  if(isalpha(file_char)) /* if alphabet */
  {
   /* Aplhabet is converted to upper case */
   out_char = toupper(file_char);
   /* Writing into the output file */
   ret = fputc(out_char, *out_file);
   if(EOF == ret) /* Error check for fputc */
   {
    return FAILURE;
   }
  }
  else /* if not alphabet */
  {
   /* Writing into the file */ 
   ret = fputc(file_char, *out_file);
   if(EOF == ret) /* Error check for fputc */
   {
    return FAILURE;
   }
  }
 } /* End of while */

 return SUCCESS;  
}

/******************************************************************************
*
*       Function Name   : display_file
*       Description     : displays  a file
*       Returns         : Success or Failure
*
*******************************************************************************/
static file_ret display_file(
                             FILE **arg_file /* Address of file pointer */
                            )
{
 char file_char = '\0'; /* To read from the file */
 /* Reads all characters from file */
 while(1)
 {
  /* Checks whether EOF is reached */
  if(feof(*arg_file) != 0)
  {
   break;
  }
  /* Reads char by char from file */
  file_char = (char)fgetc(*arg_file);
  printf("%c", file_char); /* Displays the read char */
 }
 printf("\n");
 return SUCCESS;
}


/******************************************************************************
*
*       Function Name   : main
*       Description     : Copies content of one file into another file
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 FILE *input = NULL,  /* File pointer for the input file */
      *output = NULL; /* File pointer for the output file */

 file_ret ret_val = SUCCESS; /* Return value from functions */

 /* Note: We could have taken the file name from user */

 /* Opens the input file for reading */
 ret_val = open_file(&input, "test", "r");
 if(FAILURE == ret_val) /* Error check for open_file */
 {
  printf("Opening 'test' failed\n");
  return 0;
 }

 /* Opens the output file for writing */
 ret_val = open_file(&output, "output", "w");
 /* Opens a file in append mode. Comment the above line, Uncomment the 
    below line and observe the output with a number of executions */
 //ret_val = open_file(&output, "output", "a");
 if(FAILURE == ret_val) /* Error check for open_file */
 {
  printf("Opening 'output' failed\n");
  return 0;
 }
 
 /* Copies the content of the input file to output file */
 ret_val = copy_file(&input , &output);
 if(FAILURE == ret_val) /* Error check for copy_file */
 {
  printf("Error in copying the file\n");
  return 0;
 }

 /* Closing the input file */
 ret_val = close_file(&input);
 if(FAILURE == ret_val) /* Error check for close_file */
 {
  printf("Closing 'test' failed\n");
  return 0;
 }

 /* The file must be closed before opening it again. If not, the behaviour
    is undefined. More on this, later.
    Comment the following line and observe the output */
 /* Closing the output file */
 ret_val = close_file(&output);
 if(FAILURE == ret_val) /* Error check for close_file */
 {
  printf("Closing 'output' failed\n");
  return 0;
 }

 /* Opening the output file for reading */
 ret_val = open_file(&output, "output", "r");
 if(FAILURE == ret_val) /* Error check for open_file */
 {
  printf("Opening 'output' failed\n");
  return 0;
 }

 /* Displaying the contents of the output file */
 ret_val = display_file(&output); 
 if(FAILURE == ret_val) /* Error check for display_file */
 {
  printf("Displaying 'output' failed\n");
  return 0;
 }

 /* Files get closed automatically when the program terminates. But it is a
    good practice to close the file explicitly. Check the output with valgrind
    after the commenting the below function call */
 /* Closing the output file */
 ret_val = close_file(&output);
 if(FAILURE == ret_val) /* Error check for close_file */
 {
  printf("Closing 'output' failed\n");
  return 0;
 }

 return 0;
}


