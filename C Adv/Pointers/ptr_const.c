/*******

Note: Please uncomment different statements and observer what happens 

*******/

#include <stdio.h>
#include <stdlib.h>

int main()
{
 const int num = 10;
 int dummy = 11; 

 /* Intialising the pointer variable */ 
int *ptr = NULL; 

 /* Observe the error given by compiler */ 

// num = 100; /* Trying to change the const */
 
   printf ("Num is %d\n", num);

 /* Uncomment the following and observe the warning given by compiler */ 
  ptr = &num;

 /* Uncomment this and appreciate that a const can be changed by a compiler. "const" is an information to compiler, the assigned memmory is not read-only */
 *ptr = 100;

   printf ("Num is %d\n", num);

 /* Correct pointer type to a const */
 const int *ptr2 = &num; // Pointer to a constant

 //*ptr2 = 120;  //Error cannot change as ptr2 is pointer to constant

   printf ("Num from ptr2 is %d\n", *ptr2);

 /* There is no difference between this and the above */
 int const *ptr1 = &dummy; // Pointer constant

 /* We can not change the value pointed by ptr1 */ 
 //*ptr1 = 100; //ptr1 is a constant pointer we cannot change it
 
 //*ptr2 = 200;
  dummy = 300;//dummy can be changed as data is not constant

   printf ("Dummy  is %d\n", dummy);
   printf ("Dummy  is using ptr1 %d\n", *ptr1);

/* Declaring a const pointer. The target value may change, but the pointer will always point to the same object */

  int * const ptr3 = &num; // Constant pointer to int

 /* We can change the value pointed by a constant pointer */
 *ptr3 = 300;
   printf ("Num from ptr3 is %d\n", *ptr3);
 
 /* We can not make the pointer point to another obeject */
//  ptr3 = &dummy;

 /* Neither pointer nor object can be modified */
 // const int * const ptr4 = &num; // const pointer to const int 
 
return 0;
}

