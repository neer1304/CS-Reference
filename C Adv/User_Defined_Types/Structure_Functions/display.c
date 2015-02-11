/*************************************************************************
*                       Header Files
**************************************************************************/
#include "header.h"

/*************************************************************************
*                       LOCAL MACROS
**************************************************************************/
#define IN
#define OUT

/******************************************************************************
*
*       Function Name  : emp_struct_display
*       Description    : Displaying structure elements by recieving
*			 structure as an argument.
*       Returns        : SUCCESS or FAILURE
*
*******************************************************************************/
usr_ret emp_struct_display(
			   IN emp_details_et arg_struct /* Structure */
			  )
{
 /* Observe of size of the argument. It is the size of the structure itself.
    Passing a structure to the function increases memory usage. Means
    the stack frame size increases */
 printf("Structure Argument\n");
 printf("******************\n");
 printf("Size of the argument is %d\n", sizeof(arg_struct));

 /* Displaying the elements using structure argument */
// printf("Emp ID = %d\t", arg_struct.id);
 printf("Emp ID = %d\t", arg_struct.id);
 printf("Emp Name = %s\t", arg_struct.name);
 printf("Emp Salary = %f\n", arg_struct.salary); 
 arg_struct.id++;
 return SUCCESS;
}

/******************************************************************************
*
*       Function Name  : emp_struct_ptr_display
*       Description    : Displaying structure elements by recieving
*                        poiter to structure as an argument.
*       Returns        : SUCCESS or FAILURE
*
*******************************************************************************/
usr_ret emp_struct_ptr_display(
                               IN emp_details_et *arg_ptr /* Ptr to Structure */
                              )
{
 /* Observe the size of the argument. It is the size of the pointer. So
    memory usage is less.*/
 printf("Pointer to Structure Argument\n");
 printf("*****************************\n");
 printf("Size of the argument is %d\n", sizeof(arg_ptr));

 /* Displaying the elements using pointer to structure*/
 printf("Emp ID = %d\t", arg_ptr->id);
 printf("Emp Name = %s\t", arg_ptr->name);
 printf("Emp Salary = %f\n", arg_ptr->salary);
 return SUCCESS;
}

/******************************************************************************
*
*       Function Name  : emp_struct_elem_display
*       Description    : Displaying structure elements by recieving
*                        individual elements as arguments.
*       Returns        : SUCCESS or FAILURE
*
*******************************************************************************/
usr_ret emp_struct_elem_display(
                                IN int arg_id, /* Argument to id */
			        IN char *arg_name, /* Argument to name */
			        IN float arg_sal /* Argument to salary */
                               )
{
 /* It is to demonstrate that structure elements can be passed seperately */
 printf("Structure Element Argument\n");
 printf("**************************\n");

 /* Displaying the elements using structure element arguments */
 printf("Emp ID = %d\t", arg_id);
 printf("Emp Name = %s\t", arg_name);
 printf("Emp Salary = %f\n", arg_sal);
 return SUCCESS;
}
