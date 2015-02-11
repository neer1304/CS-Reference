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

#define ant_ret int
#define SUCCESS 1
#define FAILURE 0

/*******************************************************************************
*                       FUNCTION DECLARATIONS
*******************************************************************************/
extern ant_ret get_string(char *);
extern ant_ret remove_newline(char *);
extern ant_ret display_string(char *);
extern ant_ret search_antonym (char *, char **);

