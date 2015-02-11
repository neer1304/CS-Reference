/*****************************************************************************
*			Header Files
******************************************************************************/

#include "julian_header.h"

/******************************************************************************
*
*       Function Name   : main
*       Description     : Gets the data from user and invokes appropriate
*			  functions to display julian day of the given date 
*       Returns         : Success or Failure 
*
*******************************************************************************/
int main()
{
        int year = 0; /* Year from the user */
        int month = 0; /* Month from user */
        int day = 0 ; /* Day from user */
        int julian_date = 0; /* To find the julian date */
	int day_ret = FAILURE; /* Return value from function */ 	

	day_ret = get_input_process(&year, &month, &day, &julian_date); 
        if(SUCCESS == day_ret)
	{
		printf("Entered date is %d-%d-%d\n", day, month, year);
		printf("Julian date is %d\n", julian_date);
	}
	else
	{
		printf("Error in get_input function\n");
	}

	exit(EXIT_SUCCESS);
}

