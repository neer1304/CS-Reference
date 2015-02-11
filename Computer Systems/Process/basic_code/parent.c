#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("parent program running %d\n",getpid());
	sleep(5);
	execlp("./child", "child", NULL);
	return 2;
}
