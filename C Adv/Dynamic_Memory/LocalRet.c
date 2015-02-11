#include<stdio.h>

static int *func(void);
int main()
{
        int num,*ptr = NULL;
        ptr=func();
      //  ptr = (int *)func();
        num = *ptr;
       printf("Value of num is %d",num);
        return 1;
}
int *func()
{
        int num1;
        num1 = 10;
        return(&num1);
}

