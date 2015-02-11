/*************************************************************************
*			Header Files
**************************************************************************/

#include "day_header.h"

/*************************************************************************
*			Local Functions
**************************************************************************/

static int leap_year_check(int);
static int julian_date_find(int, int, int);
static int day_of_the_week(int, int);
static void display_day(int);

/******************************************************************************
*
*       Function Name   : get_input_process
*       Description     : gets input from user and invokes other functions
*       Returns         : Nothing
*
*******************************************************************************/
void get_input_process(void)
{
        int user_year = 0; /* Year from the user */
        int user_month = 0; /* Month from user */
        int user_day = 0 ; /* Day from user */

        int leap_check = 0; /* To check for leap year */

        int julian_date = 0; /* To find the julian date */

        int index_for_day = 0; /* To find the index of the day */

	/* Getting input from user */
        printf("\nEnter an year:\n");
        scanf("%d",&user_year);

        printf("\nEnter a month:\n");
        scanf("%d",&user_month);

        printf("\nEnter an day:\n");
        scanf("%d",&user_day);

        /* Checking for leap year */
        leap_check = leap_year_check(user_year);
        if(leap_check > 0) /* leap year */
        {
                printf("\n%d is a leap year",user_year);
        }
        else /* not a leap year */
        {
                printf("\n%d is not a leap year",user_year);
        }

        /* Finding out the Julian date for the given year */
        julian_date = julian_date_find(user_year,user_month,user_day);
        printf("\nJulian Date for %d-%d-%d is %d", user_day,user_month,
                        user_year,julian_date);

      /* Finding out the index for the given date */
        index_for_day = day_of_the_week(user_year,julian_date);
        printf("\nIndex for day is %d",index_for_day);


        printf("\n\n*********************************************************");
        printf("\n\n\t\tTHE DAY IS:\t");
        /* Displaying the day using the index */
        display_day(index_for_day);
        printf("\n*********************************************************\n");

}

/******************************************************************************
*
*       Function Name   : leap_year_check
*       Description     : Finds out whether an year is a leap year or not
*       Returns         : 0 if not leap year and 1 if leap year
*
*******************************************************************************/

static int leap_year_check(
				int leap_year /* Input Variable - Year */
		   	  )
{
        int leap_return = 0; /* Value to be returned from the function */

	/* Checking for leap year */
        if (((0 == leap_year % 4) && (0 != leap_year % 100)) || (0 == leap_year % 400))
        {
                leap_return = 1;
        }

        return leap_return;
}

/******************************************************************************
*
*       Function Name   : julian_date_find
*       Description     : Finds out the julian date of a date
*       Returns         : Julian date
*
*******************************************************************************/

static int julian_date_find(
				int year,  /* Input - Year */ 
				int month, /* Input - Month */
				int day    /* Input - Day */
		    	   )
{
        int mon_count = 1; /* To keep track of month count */
        int days_count = day; /* To keep track of day count */

        while(mon_count < month) /* Till the given month */
        {
		/* If there are 31 days in a month */
                if((mon_count == 1) || (mon_count == 3) || (mon_count == 5) ||
                 (mon_count == 7) || (mon_count == 8) || (mon_count == 10) ||
                 (mon_count == 12))
		{
                        days_count = days_count + 31;
		}
		/* If there are only 30 days in a month */
                else if((mon_count == 4) || (mon_count == 6) || (mon_count==
                        9) || (mon_count == 11))
		{
                        days_count = days_count + 30;
		}
		/* If there are 29 days in Feb */
                else if ((mon_count == 2) && (leap_year_check(year)))
		{
                        days_count = days_count + 29;
		}
		/* If there are 28 days in Feb */
                else if((mon_count == 2) && (!leap_year_check(year)))
		{
                        days_count = days_count + 28;
		}

                mon_count++; /* Incrementing month */
        } /* End of While */

        return days_count;
}

/******************************************************************************
*
*       Function Name   : day_of_the week
*       Description     : Finds out the index of the day 
*       Returns         : Day index
*
*******************************************************************************/

static int day_of_the_week(
				int year,  /* Input - Year */ 
				int julian /* Input - Julian Date */
		   	  )
{

        int day_index = 0; /* Stores the index of the day */
	/* Temporary variables*/
        int cal_julian = julian; 
        int cal_year = year; 
        int fours = (cal_year - 1) / 4;
        int hundreds = (cal_year - 1) / 100;
        int four_hund = (cal_year - 1) / 400;

        /* Calculating the day index */
        day_index = (cal_year + cal_julian + fours - hundreds + four_hund) % 7;

        return day_index;
}

/******************************************************************************
*
*       Function Name   : display_day
*       Description     : Displays the day of the week using the day index
*       Returns         : Nothing
*
*******************************************************************************/


static void display_day(
		 	int day_index /* Input : Index of the day */
		       )
{
	/* Switches based on the index */
        switch(day_index)
        {
                case 0:
			{
                         printf("Saturday\n");
                         break;
			}
                case 1:
			{
                         printf("Sunday\n");
                         break;
			}
                case 2:
			{
                         printf("Monday\n");
                         break;
			}
                case 3:
			{
                         printf("Tuesday\n");
                         break;
			}
		case 4:
			{
                         printf("Wednesday\n");
                         break;
			}
                case 5:
			{
                         printf("Thursday\n");
                         break;
			}
                case 6:
			{
                         printf("Friday\n");
                         break;
			}
		default:
			{
			 printf("Invalid Index\n");
			 break;
			}
        }
}

