

#include <stdio.h>

int main()
{
 /* Local Variable */
 char ch = 'A';
 int num = 111;
 long int l_num = 22334455;
 float f = 22.2;
 double d = 33.3;

 /* Pointer variables and their initializations */
 char *c_ptr = &ch;
 int *i_ptr = &num;
 long int *li_ptr = &l_num;
 /* Uncomment the following and observe the warning given by compiler */
 //int *li_ptr = &l_num;
 float *f_ptr = &f;
 double *d_ptr = &d;

 /* Displaying the size of variables and their pointers.*/
 /* Size of pointer is same irrespective of the object they are pointing to */
 printf("sizeof char =%u, sizeof char* = %u\n", sizeof(ch), sizeof(c_ptr));
 printf("sizeof int =%u, sizeof int* = %u\n", sizeof(num), sizeof(i_ptr));
 printf("sizeof long int =%u, sizeof long int* = %u\n", sizeof(l_num), sizeof(li_ptr));
 printf("sizeof float =%u, sizeof float* = %u\n", sizeof(float), sizeof(f_ptr));
 printf("sizeof double  =%u, sizeof double* = %u\n", sizeof(double), sizeof(d_ptr));

 /* Displaying the address different variables using pointer */
 printf("Address of variables\n"); 
 printf("********************\n");
 printf("Address of ch is %p\n", c_ptr);  
 printf("Address of num is %p\n", i_ptr);  
 printf("Address of long num is %p\n", li_ptr);  
 printf("Address of f is %p\n", f_ptr);  
 printf("Address of d is %p\n", d_ptr);  

 /* Incrementing all pointers */
 /* Pointers are incremented by the size of the object they are pointing to */
 c_ptr++; 
 i_ptr++; 
 li_ptr++; 
 f_ptr++; 
 d_ptr++; 
 
 /* Displaying pointer values after they are incremented  */
 printf("Pointer After incrementing\n"); 
 printf("********************\n");
 printf("Address of ch is %p\n", c_ptr);  
 printf("Address of num is %p\n", i_ptr);  
 printf("Address of long num is %p\n", li_ptr);  
 printf("Address of f is %p\n", f_ptr);  
 printf("Address of d is %p\n", d_ptr);  

 return 0;
}
