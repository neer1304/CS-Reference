/*****************************************************************************
*                       Header Files
******************************************************************************/

#include "header.h"

/******************************************************************************
*
*       Function Name   : main
*       Description     : Demonstates how structure can be passed to a function
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 emp_details_et employee; /* Structure Variable */
 usr_ret ret_val = SUCCESS; /* Return Value from functions */
 
 memset(&employee, 0, sizeof(employee)); /* Initializing the structure */
 
 /* Updating the structure elements */
 employee.id = 231239;
 strcpy(employee.name, "Paulo Coelho");
 employee.salary = 23.678;

 /* Function calls to display structurements */
 ret_val = emp_struct_display(employee);
 ret_val = emp_struct_ptr_display(&employee);
 ret_val = emp_struct_elem_display(employee.id, employee.name, employee.salary);
 
 return 0;
}

