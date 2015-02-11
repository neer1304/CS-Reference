#include<stdio.h>
#include<sys/wait.h>

int main()
{
int ret;
printf("Calling wait\n");
ret=wait(NULL);
printf("return value of wait is %d\n",ret);
return 0;
}
