/*****************************************************************************
*                       Header Files
******************************************************************************/
#include "ptr_header.h"

/*****************************************************************************
*                       Macros
******************************************************************************/
#define MAX 2
/******************************************************************************
*
*       Function Name   : main
*       Description     : Demonstrates how to use pointer to a structure
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 /* Declaring and initializing the structure. Each structure elements has to
    be initialized seperately. */
 point difference = {0,0};

 /* Declare and initialize an array of structures. */
 point positions[MAX] = {{0,0},{0,0}}; 

 /* Alternate way of initialzing strcture with memset */
 memset(&difference, 0, sizeof(point));
 memset(positions, 0, MAX * sizeof(point));

 point *ptr_point = NULL; /* Pointer to a structure */
 
/* Assigns the address of the structure to the pointer */
 ptr_point = &difference;

 /* Accepting the co-ordinates for the first point.
    To access structure elements, we use '.' operator */
 printf("Enter co-ordinates of the first point\n");
 scanf("%d%d", &positions[0].x, &positions[0].y);

 /* Accepting the co-ordinates for the second point */
 printf("Enter co-ordinates of the first point\n");
 scanf("%d%d", &positions[1].x, &positions[1].y);

 /* Finding out the difference between 'x' values */
 difference.x = positions[0].x - positions[1].x;

 /* Finding out the difference between 'y' values */
 difference.y = positions[0].y - positions[1].y;
 
 /* Displaying the structure elements using structure variable
    and '.' operators */
 printf("Difference in x and y of points are\n");
 printf("%d\t%d\n", difference.x, difference.y);

 /* Displaying the structure elements using pointer to structure
    and '->' operator */ 
 printf("Difference in x and y of points are\n");
 printf("%d\t%d\n", ptr_point->x, ptr_point->y);

 /* Demonstrates how to refer to a structure using the pointer.*/
 printf("Difference in x and y of points are\n");
 printf("%d\t%d\n", (*ptr_point).x, (*ptr_point).y);
 return 0;
}
