/*************************************************************************
*
*  FILE NAME    : tok_rev_header.h
*
*  DESCRIPTION  : Contains header files and function prototypes string 
*		  tokenization and reverse concatenation program
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*  Copyright 2010, Aricent Technologies (Holdings) Ltd
*
**************************************************************************/

/* Avoiding multiple inclusions of header file */
#ifndef TOK_REV_HEADER_H
  #define TOK_REV_HEADER_H 
/*******************************************************************************
*                       HEADER FILES
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*******************************************************************************
*                       MACROS
*******************************************************************************/
#define tok_ret int
#define FAILURE 0
#define SUCCESS 1

/*******************************************************************************
*                       FUCNTION PROTOTYPES
*******************************************************************************/
extern tok_ret tok_rev_concat(char [], char **);
#endif
