

#include <stdio.h>
#include <stdlib.h>

int main()
{
 int num = 10, *iptr = NULL;
 char ch = 'A', *cptr= NULL;
 void *vptr = NULL; /* void pointer declaration*/

 printf("%u\n", sizeof(vptr));
 iptr = &num;
 printf("%d\n",*iptr); /* Prints 10 */

 cptr = &ch;
 printf("%c\n",*cptr); /* Prints A */

 /* Comment this line to get proper output */
// iptr =  cptr; /* Incompatible pointer assignment */
// printf("%d\n",*iptr); /* Undefined value will be printed */

 vptr = iptr;
 /*  Comment this line to remove the compilation error */
 //printf("%c\n",*vptr); /* Error: void pointer can not be de-refenced */

 printf("%d\n", *((int *) vptr)); /* There is no issue since the void pointer is type casted to correct type*/

 vptr = cptr;
 printf("%c\n", *(char *) vptr);
 return 0;
}







