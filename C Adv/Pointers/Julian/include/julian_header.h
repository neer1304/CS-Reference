/*************************************************************************
*
*  FILE NAME    : julian_header.h
*
*  DESCRIPTION  : Contains header files and function prototypes for julian prgoram*
*
**************************************************************************/

/*******************************************************************************
*                       HEADER FILES
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
*                       MACROS
*******************************************************************************/
#define julian_ret int

/* Error Codes */
#define SUCCESS 1
#define FAILURE 0

/* Fuction parameter classifier */

#define IN
#define OUT

/*******************************************************************************
*                       FUCNTION PROTOTYPES
*******************************************************************************/

extern julian_ret get_input_process(int *, int *, int *, int *);
