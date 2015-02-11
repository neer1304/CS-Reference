

#include <stdio.h>

int main()
{ 
 int x = 15, 
     y = 0,
     *ptr, 
    **pptr = NULL; 

 /* Invalid derefer since the pointer is not initialised to a valid address */

// printf("*ptr valus is %d\n", *ptr);

 /* Invalid derefer leads to crash if the pointer is initialised to NULL */
// printf("**pptr valus is %d\n", **pptr);

 ptr = &x; /* Assign address of x to ptr */ 
 pptr = &ptr; /* Assign address of ptr to pptr */ 
 
 /* Observer the warning given by compiler - gcc -Wall */ 

 y = *ptr++ + *ptr++; 
 
 /* Use brackets to clearly specify what you are intending. Here we derefer and then increment the value */
// y = (*ptr)++ - (*ptr)++; 

 /* If you want to increment the pointer and then derefer */
  y = *(ptr++) - *(ptr++); 

 
 printf("y value is %d\n", y);
 printf("x value is %d\n", x);

pptr=&ptr; 
printf("ptr = %p   %p\n", ptr, pptr);
ptr++;
pptr++;
printf("ptr = %p   %p\n", ptr, pptr);
return 0;
}

