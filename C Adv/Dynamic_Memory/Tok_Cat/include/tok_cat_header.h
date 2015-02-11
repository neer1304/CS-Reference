/*************************************************************************
*
*  FILE NAME    : tok_rev_header.h
*
*  DESCRIPTION  : Contains header files and function prototypes string 
*		  tokenization and reverse concatenation program
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
