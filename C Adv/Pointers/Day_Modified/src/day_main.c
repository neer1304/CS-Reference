/*******************************************************************************
*
*  DESCRIPTION  : Calculate the day of the week on which a given date falls
*                 based on the Julian day for that date. The day of the week is
*                 calculated as follows
*
*                       year = year in question (all four digits)
*                       Jul_day = Julian day of date in question (1 to 366)
*                       fours = integer portion of (year- 1) / 4
*                       hundreds = integer portion of (year - 1) /100
*                       four_hund = integer portion of (year - 1) / 400
*                       day = (year + Jul_day + fours - hundreds + four_hun) % 7
*
*                       where
*
*                       Result  Means
*
*                       0       Saturday
*                       1       Sunday
*                       2       Monday
*                       3       Tuesday
*                       4       Wednesday
*                       5       Thursday
*                       6       Friday
******************************************************************************/

/*****************************************************************************
*			Header Files
******************************************************************************/

#include "day_header.h"

/******************************************************************************
*
*       Function Name   : main
*       Description     : Gets the data from user and invokes appropriate
*			  functions to display the day of the given date 
*       Returns         : Success or Failure 
*
*******************************************************************************/
int main()
{
	/* Function to get the input and do the functionality */
	get_input_process();

	return EXIT_SUCCESS;
}

