/*******************************************************************************
*                       HEADER FILES
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
*                       MACROS
*******************************************************************************/
#define MAX 32
//#define MAX 8 /*Comment the previous uncomment this and observe the warning*/
#define SZ 5

#define str_ret int
#define SUCCESS 1
#define FAILURE 0

/*******************************************************************************
*                       FUNCTION DECLARATIONS
*******************************************************************************/
extern str_ret get_string(char *);
extern str_ret remove_newline(char *);
extern str_ret display_string(char *);
extern str_ret str_cpy(char *, char *);
extern str_ret str_cat(char *, char *);
