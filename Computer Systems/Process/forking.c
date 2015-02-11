#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int var = 0;
	printf("L0%d\n",getpid());
	printf("L1:%d\n",getpid());
	var = fork();
	printf("Bye:Parent:%d,child:%d\n",getppid(),getpid());
        return 1;
}
