#include"header.h" 

/****************************************************************************
*       Function Name   : main
*       Description     : Demonstration of function pointers
*       Returns         : Success or Failure
****************************************************************************/
int main()
{
 int index = 0; /* for loop index */
 /*Initializing an array */
// int num[MAX] = {222,33,11,555,44,444,666,77,88,99};
 char *input[MAX];

 int ret = 0; 
 int (*f_ptr)(char*, char*) = NULL; /* Function pointer */

 for(index=0;index<MAX;index++)
 input[index]=(char*)malloc(20*sizeof(char));

 for(index=0;index<MAX;index++)
 { 
  printf("Please enter the String %d\n",index);
  scanf("%s",input[index]);
 }
 printf("The original string array before sorting is :-\n");
 for(index=0;index<MAX;index++)
 {
 printf("%s ",input[index]);
 }
 printf("\n");

 f_ptr = compare; /* Assigning address of function to function pointer */ 

 /* Invoking the function using function pointer */
 ret = f_ptr(input[0], input[1]);
 if(ret == 0) /* If the first number is larger */
 {
  printf("*****************************\n");
  printf("%s is greater than %s\n", input[0], input[1]);
  printf("*****************************\n");
 }
 else /* If the first number is smaller */
 {
  printf("*****************************\n");
  printf("%s is smaller than %s\n", input[0], input[1]);
  printf("*****************************\n");
 }

 /* Sorting the array. "compare" is a function which is passed as an argument */
 sort(input, MAX, compare);

 printf("The sorted array is\n");
 printf("*******************\n");
 /* Displaying the array elements */
 for(index = 0; index < MAX; index += 1)
 {
  printf("%s ", input[index]);
 }
 printf("\n");

//free the input array 
for(index=0;index<MAX;index++)
{
free(input[index]);
input[index]=NULL;
}
 return 0;
}
