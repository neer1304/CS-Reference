/*************************************************************************
*				HEADER FILES
*************************************************************************/
#include <stdio.h>

/*************************************************************************
*				MACROS
*************************************************************************/
#define MAX 5
#define ROW 2
#define COL 3

/******************************************************************************
*
*       Function Name   : main
*       Description     : Demonstration of arrays
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
 int index_1, index_2, index_3; /* Array indices */
 /* Declaring and initializing a 1-D array. Only first 3 elements are initialized. Remaining elements are initialized to 0 by default */
 int numbers[MAX] = {11,22,33};
 /* Declaring and initializing a 2-D array */
 int matrix[ROW][COL] = {{1,2,3}, {4,5,6}};

 /*Uncomment the following and observe the warning */ 
//int matrix[ROW][COL] = {1,2,3,4,5,6};

 /* Uncomment the following lines and observe the errors. This emphasizes the fact that array is a const pointer */
//numbers[MAX] = {100,200,300,400,500};
//numbers = &index_1;
 
 /* Uncomment the following to demonstrate ABR - Array Bound Read. Also the 
    element is left out - off-By-One bug  */
/* for(index_1 = 1; index_1 <= MAX; index_1 += 1)
 {
  printf("%d\t", numbers[index_1]); 
 }

 printf("\n");
*/
 /* Displaying the 1-D array elements */ 
 /*for(index_1 = 0; index_1 < MAX; index_1 += 1)
 {
  printf("%d\t", numbers[index_1]); 
 }

 printf("\n");
*/
 // Displaying the 2-D array elements 
 /*for(index_2 = 0; index_2 < ROW; index_2 += 1)
 {
  for(index_3 = 0; index_3 < COL; index_3 += 1)
  {
   printf("%d\t", matrix[index_2][index_3]); 
  }
 }
 printf("\n");
 */
 /* Example for ABW - Array Bound Write */
 for(index_2 = 0; index_2 < COL; index_2 += 1) 
 {
  for(index_3 = 0; index_3 < ROW; index_3 += 1)
  {
   matrix[index_2][index_3] = index_2 * index_3; 
   printf("%d\t",matrix[index_2][index_3]);
  }
 }
printf("\n");
 /* Displaying the 2-D array elements */ 
 for(index_2 = 0; index_2 < ROW; index_2 += 1)
 {
  for(index_3 = 0; index_3 < COL; index_3 += 1)
  {
   printf("%d\t", matrix[index_2][index_3]); 
  // printf("%d\t",matrix[index_3][index_3]);
  }
 }
 printf("\n");
 
 return 0;
}
