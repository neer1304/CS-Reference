#include"header.h"

int main()
{
 FILE *infile = NULL; /* File pointer */
 int ch,eid,rnum,num; 
 /* Declaring and initializing an item array with NELEM elments */
 emp emparray[EMPNUM];   // = {{2,"Rice",50.0},{4,"Roti",8.0},{6,"Curd",6.5}};
char ename[MAX];
// emp *emp_ptr = emparray; /* Pointer to the structure */

 int ret_val = 0; /* Return value of fread, fwrite, fclose */
      /* Return value of ferror */
 /* Initializing the single structure */
 //memset(item_ptr,0,sizeof(item));

again:printf("Enter the number of record to be inserted\n");
scanf("%d",&num);
if(num>EMPNUM)
{
printf("Memory insufficient.Please enter lesser no. of records..\n");
goto again;
}
else
{ 
insertRec(emparray,num);
}
 /* Opening a binary file in writing mode */
 infile = fopen("../include/emp_data", "wb");
 if(NULL == infile) /* Error check for fopen */
 {
  printf("Error in opening file\n");
  return 0;
 }  
 
 /* Write the entire array into the file */
 ret_val = fwrite(emparray, sizeof(emp),num, infile);
 printf("fwrite returns %d\n", ret_val);
 
 /* One common error in error checking is that check the error against the 
    number of bytes written. Rather fwrite returns number of elements written.
    Comment this line and uncomment the next one after observing the output */

 if(num != ret_val) /* Error check for fwrite */
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
 infile = fopen("../include/emp_data", "rb");
 if(NULL == infile) /* Error check for fopen */
 {
  printf("Error in opening file\n");
  return 0;
 }  

 /* Reads one item at a time from the file */
/* while(1)
 {
  * Reads one item at a time. Note the size and number of elements *
  ret_val = fread(emparray, sizeof(emp), 1, infile);
 
  * fread returns number of elements read *
  printf("fread returns %d\n", ret_val);
  if(0 == ret_val) * Checking the return value of fread to stop reading */
  {
   /* Checks whether fread returned 0 because of error or EOF reached. ferror
      tests the error indicator and returns non-zero value on error. To observe
      how ferror works, change the opening mode of file from 'r' to 'w' *
   err_ret = ferror(infile);
   if(err_ret != 0) * Error occured *
   {
    printf("Error in reading the file\n");
   }
   else * EOF reached *
   {
    printf("EOF reached\n");
   }
   break;
  }
  * Displaying the read values *
*  printf("Emp id = %d\t", emp_ptr->id);
  printf("Emp Name = %s\t", emp_ptr->name);
  printf("Emp Dept = %s\t", emp_ptr->dept);
  printf("Phone No= %ld\t",emp_ptr->phno);
  printf("\n");
 }
*/


again1: printf("\nEnter 1-to get the record by name\n 2-to get the record by id\n3-to get the records by record number\n 4-to exit");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the name of the employee\n");
scanf("%s",ename);
getRecByName(infile,ename);
//fclose(infile);
break;

case 2:
printf("Enter the id of the employee\n");
scanf("%d",&eid);
getRecById(infile,eid);
//fclose(infile);
break;

case 3:
printf("Enter the record number\n");
scanf("%d",&rnum);
getRecByNum(infile,rnum);
//fclose(infile);
break;

case 4:
exit(0);

default:
printf("Please enter an valid option\n");
goto again1;
break;
}

 /* Closing the file after writing */
 ret_val = fclose(infile);
 if(0 != ret_val) /* Error check for fclose */
 {
  printf("Error in closing the file\n");
  return 0;
 }
}
 return SUCCESS;
}
