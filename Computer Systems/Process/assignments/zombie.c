#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
pid_t pid;

pid=fork();

if(0==pid)
{
printf("Child process\n");
printf("Zombie process\n");
exit(0);
}
else
{
printf("Parent process\n");
sleep(15);
}
return 0;
}
