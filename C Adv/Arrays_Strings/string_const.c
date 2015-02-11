/***************************************************************************
*			STANDARD HEADER FILES
***************************************************************************/
#include <stdio.h>
#include <string.h>

/***************************************************************************
*			MACROS
***************************************************************************/
#define MAX 32

/****************************************************************************
*
*       Function Name   : main
*       Description     : Demonstration string contant and character array
*       Returns         : Success or Failure
*
****************************************************************************/
int main()
{
 /* str1 is a constant pointer pointing to a char array */
 char str1[MAX] = "The Alchemist";

 /* str2 is a pointer to a constant.*/
 char *str2 = "Paulo Coelho";
 
printf("str1 = %s\n", str1);
 /* Length is number of characters upto '\0' - 13 */
 printf("Length of str1 is %u\n",strlen(str1)); 
 /* Size is the total bytes allocated for the array */
 printf("Size of str1 is %u\n",sizeof(str1)); 

 printf("str2 = %s\n", str2);
 /* Length is number of characters upto '\0' - 12 */
 printf("Length of str2 is %u\n",strlen(str2)); 
 /* Size of str2 is nothing but the size of the pointer */
 printf("Size of str2 is %u\n",sizeof(str2)); 

 /* str1 is const pointer. But what is pointed by that is not a constant.
    sO INDIVIDUAL ELements can be modified . "The Alchemist is stored in the 
    stack frame of main */
 str1[4] = 'E';
 printf("str1 = %s\n", str1);

 /* str2 is pointer to a constant. Its target can not be modified.
    So individual elements can not be modified. "Paulo Coelho" is stored in
    a read only area. The following line crashes the program */
 //str2[0] = 'B';

 /* str1 is constant pointer. It can not be made point to another object.
    The following line gives a compilation error. */
 //str1 = "PRISM";

 /* The following is correct because it modifies the target object */
 strcpy(str1, "PRISM");
 printf("str1 = %s\n", str1);
 
 /* str2 is a pointer to a constant. That itself is not a constant. So it can
    be made point to another object */
 str2 = "Nalanda";
 printf("str2 = %s\n", str2);

 return 0;
}
