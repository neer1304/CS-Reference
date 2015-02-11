#include<stdio.h>
#include<sys/types.h>

/*
Will it  work on different H/W platforms?
*/

main(int argc, char *argv[])
{
        int * ptr;
        ptr = &argc;
        unsigned int int_usedas_ptr;
        int_usedas_ptr = (unsigned int)ptr;
        printf("%d %d\n",sizeof(ptr),sizeof(int));
	printf("The Value of argc  is %d\n",*((unsigned int *)int_usedas_ptr));
}
