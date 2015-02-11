#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{
pid_t pid;

pid=fork();

if(0==pid)
{
printf("Child\n");
sleep(15);
printf("Orphan\n");
}
else
{
printf("Parent\n");
exit(0);
}
}
