/*************************************************************************
*
*  FILE NAME    : pbv_pbr_header.h
*
*  DESCRIPTION  : Contains header files and function prototypes for swap prg
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*  Copyright 2010, Aricent Technologies (Holdings) Ltd
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

#define INT 1
#define CHAR 2

/*******************************************************************************
*                       FUCNTION PROTOTYPES
*******************************************************************************/
extern void pbv_swap_int(int, int);
extern void pbv_swap_char(char, char);
extern void pbr_swap(void *, void *, int);


