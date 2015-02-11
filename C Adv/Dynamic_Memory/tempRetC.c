#include<stdio.h>
#include<stdlib.h>

int *func(void);
int main()
{
        int num,*ptr;
        ptr = func();
        if(ptr!=NULL)
        {
                num = *ptr;
                printf("Value of num is %d\n",num);
        }
       // free(ptr);
        return 0;
}
int *func()
{
        int *num1;
        num1 = malloc(sizeof(int));
        if(NULL == num1)
        {
                return NULL;
        }
        *num1 = 10;
        return(num1);
}

