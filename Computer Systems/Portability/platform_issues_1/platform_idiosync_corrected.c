#include<stdio.h>
#include<sys/types.h>

/*
If you want to make it work on two different platforms (64/32 bit)
you will have to compile different pieces of code
Following are the platform/compiler assumptions:
1. The size of an unsigned long type on a 64-bit machine is 64 bits
2. The size of an unsigned int type on a 32-bit machine is 32 bits
3. The size of a pointer type on a 64-bit machine is 64 bits
4. The size of a pointer type on a 32-bit machine is 32 bits
*/

main(int argc, char *argv[])
{
        int * ptr;
        ptr = &argc;

#if defined(MACHINE_64_BIT)
        unsigned long int_usedas_ptr;
        int_usedas_ptr = (unsigned long)ptr;
        printf("The Value of argc  is %d\n",*((unsigned long *)int_usedas_ptr));

#elif  defined(MACHINE_32_BIT)
        unsigned int int_usedas_ptr;
        int_usedas_ptr = (unsigned int)ptr;
        printf("The Value of argc  is %d\n",*((unsigned int *)int_usedas_ptr));
#endif
}
