#include "julian_header.h"

/*************************************************************************
*			Local Functions
**************************************************************************/

static julian_ret leap_year_check(int *, int *);
static julian_ret julian_date_find(int *, int *, int *, int *, int *);

/******************************************************************************
*
*       Function Name   : get_input_process
*       Description     : gets input from user and invokes other functions
*       Returns         : Nothing
*
*******************************************************************************/
julian_ret get_input_process(
				IN int *arg_day, /* Day from user */
				IN int *arg_month, /* Month from user */
				IN int *arg_year, /* Year from user */
				OUT int *arg_julian /* Julian day */
			    )
{
        int leap_check = 0; /* To check for leap year */
	int ret_val = SUCCESS;
	int err_ret = 0;
	
	if(NULL == arg_day || NULL == arg_month || NULL == arg_year || NULL == arg_julian)
	{
		ret_val = FAILURE;
	}
	else
	{
		/* Getting input from user */
        	printf("\nEnter an year:\n");
        	err_ret = scanf("%d",arg_year);
		if(err_ret <= 0)
		{
			return FAILURE;
		}

        	printf("\nEnter a month:\n");
        	err_ret = scanf("%d",arg_month);
		if(err_ret <= 0)
		{
			return FAILURE;
		}
		/* The following is a sample error checking. */
		if (((*arg_month) <= 0) || ((*arg_month) > 12))
		{
			return FAILURE;
		}
        	printf("\nEnter an day:\n");
        	err_ret = scanf("%d",arg_day);
		if(err_ret <= 0)
		{
			return FAILURE;
		}

        	/* Checking for leap year */
        	ret_val = leap_year_check(arg_year, &leap_check);
		if(SUCCESS == ret_val)
		{
        	 /* Finding out the Julian date for the given year */
		 ret_val = julian_date_find(arg_year,arg_month,arg_day, &leap_check, arg_julian);
			
		}
	}
	return ret_val;
}

/******************************************************************************
*
*       Function Name   : leap_year_check
*       Description     : Finds out whether an year is a leap year or not
*       Returns         : SUCCESS or FAILURE
*
*******************************************************************************/

static julian_ret leap_year_check(
				   IN int *arg_year, /*User year */
				   OUT int *arg_check /* result of leap ckeck */
		   	  	 )
{
	int ret_val = SUCCESS;
	if(NULL == arg_year || NULL == arg_check)
	{
		ret_val = FAILURE;
	}
	else
	{
		/* Checking for leap year */
	        if (((0 == *arg_year % 4) && (0 != *arg_year % 100)) || (0 == *arg_year % 400))
        	{
                	*arg_check = 1;
	        }
		else
		{
			*arg_check = 0;
		}
	}
	return ret_val; 
}	

/******************************************************************************
*
*       Function Name   : julian_date_find
*       Description     : Finds out the julian date of a date
*       Returns         : SUCCESS or FAILURE 
*
*******************************************************************************/

static julian_ret julian_date_find(
				   IN int *year, /* User year */   
				   IN int *month, /* User month */
				   IN int *day,    /* User day */
				   IN int *arg_leap, /* leap check */
				   OUT int *arg_julian /* Julian date */
		    	   	  )
{
	int ret_val = SUCCESS;
        int mon_count = 1; /* To keep track of month count */
        *arg_julian = *day; /* To keep track of day count */
	if(NULL == year || NULL == month || NULL == day || NULL == arg_leap || NULL == arg_julian)
	{
	 ret_val = FAILURE;
	}
	else
	{
         while(mon_count < *month) /* Till the given month */
         {
	  /* If there are 31 days in a month */
          if((mon_count == 1) || (mon_count == 3) || (mon_count == 5) ||
                 (mon_count == 7) || (mon_count == 8) || (mon_count == 10) ||
                 (mon_count == 12))
	  {
           *arg_julian = *arg_julian + 31;
	  }
	  /* If there are only 30 days in a month */
          else if((mon_count == 4) || (mon_count == 6) || (mon_count== 9) || (mon_count == 11))
	  {
           *arg_julian = *arg_julian + 30;
	  }
	  /* If there are 29 days in Feb */
          else if ((mon_count == 2) && (*arg_leap))
	  {
           *arg_julian = *arg_julian + 29;
	  }
          /* If there are 28 days in Feb */
          else if((mon_count == 2) && (!(*arg_leap)))
	  {
           *arg_julian = *arg_julian + 28;
	  }

          mon_count++; /* Incrementing month */
         }
        } /* End of While */

        return ret_val;
}

