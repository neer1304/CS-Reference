/*************************************************************************
*
*  FILE NAME    : binary_file.c
*
*  DESCRIPTION  : Demonstrates block reading and writing with binary file
**************************************************************************/

/*************************************************************************
                        HEADER FILES
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
*                       MACROS
*******************************************************************************/
#define NELEM 3
#define MAX 32

/*******************************************************************************
*                       USER DEFINED VARIABLES
*******************************************************************************/
/* Item structure which has item number, item name and item cost.*/
typedef struct item
{
 int item_num;
 char item_name[MAX];
 float item_cost;
}item;

/******************************************************************************
*
*       Function Name   : main
*       Description     : Demontration of fread and fwrite
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 FILE *infile = NULL; /* File pointer */
 
 /* Declaring and initializing an item array with NELEM elments */
 item itemarray[NELEM] = {{2,"Rice",50.0},{4,"Roti",8.0},{6,"Curd",6.5}};

 item single_item, /* To read one item at a time */
      *item_ptr = &single_item; /* Pointer to the structure */

 int ret_val = 0, /* Return value of fread, fwrite, fclose */
     err_ret = 0; /* Return value of ferror */
 /* Initializing the single structure */
 //memset(item_ptr,0,sizeof(item));
 
 /* Opening a binary file in writing mode */
 infile = fopen("item_data", "wb");
 if(NULL == infile) /* Error check for fopen */
 {
  printf("Error in opening file\n");
  return 0;
 }  
 
 /* Write the entire array into the file */
 ret_val = fwrite(itemarray, sizeof(item), NELEM, infile);
 printf("fwrite returns %d\n", ret_val);
 
 /* One common error in error checking is that check the error against the 
    number of bytes written. Rather fwrite returns number of elements written.
    Comment this line and uncomment the next one after observing the output */

 if(NELEM != ret_val) /* Error check for fwrite */
 //if(sizeof(item) != ret_val)
 {
  printf("Error in writing\n");
  return 0;
 }

 /* Closing the file after writing */
 ret_val = fclose(infile);
 if(0 != ret_val) /* Error check for fclose */
 {
  printf("Error in closing the file\n");
  return 0;
 }

 /* Opening the binary file for reading */
 infile = fopen("item_data", "rb");
 if(NULL == infile) /* Error check for fopen */
 {
  printf("Error in opening file\n");
  return 0;
 }  

 /* Reads one item at a time from the file */
 while(1)
 {
  /* Reads one item at a time. Note the size and number of elements */
  ret_val = fread(item_ptr, sizeof(item), 1, infile);
 
  /* fread returns number of elements read */
  printf("fread returns %d\n", ret_val);
  if(0 == ret_val) /* Checking the return value of fread to stop reading */
  {
   /* Checks whether fread returned 0 because of error or EOF reached. ferror
      tests the error indicator and returns non-zero value on error. To observe
      how ferror works, change the opening mode of file from 'r' to 'w' */
   err_ret = ferror(infile);
   if(err_ret != 0) /* Error occured */
   {
    printf("Error in reading the file\n");
   }
   else /* EOF reached */
   {
    printf("EOF reached\n");
   }
   break;
  }
  /* Displaying the read values */
  printf("Item Number = %d\t", item_ptr->item_num);
  printf("Item Name = %s\t", item_ptr->item_name);
  printf("Item Cost = %f\t", item_ptr->item_cost);
  printf("\n");
 }

 /* Closing the file after writing */
 ret_val = fclose(infile);
 if(0 != ret_val) /* Error check for fclose */
 {
  printf("Error in closing the file\n");
  return 0;
 }
 return 0;
}
