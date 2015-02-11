**************************************************************************/

/*******************************************************************************
*                       HEADER FILES
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
*                       MACROS
*******************************************************************************/

#define IN
#define OUT
#define MODI

#define MAX 5
#define ROW 2
#define COL 3

/*******************************************************************************
*                       FUNCTION PROTOTYPES
*******************************************************************************/
extern void update_1d_array(int [], int);
extern void update_1d_ptr(int *, int);
extern void reverse_1d_ptr(int *, int);
extern void display_1d(int [], int);
extern void display_2d_array(int [][COL]);
extern void display_2d_ptr(int (*ptr)[COL]);
extern void display_2d_dbl_ptr(int **ptr);
