#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
pid_t pid;
int status=10,wrt=0;

pid=fork();

if(0==pid)
{
printf("Child\n");
printf("The pid of child is %d\n",getpid());
printf("The pid of child parent is %d\n",getppid());
exit(10);
}
else
{
printf("Parent\n");
wrt=wait(&status);
printf("The pid of parent is %d\n",getpid());
printf("The pid of grand parent is %d\n",getppid());
printf("retvalue %d :status %d\n",wrt,status);
printf("child exit status %d\n",WEXITSTATUS(status));
}

}
