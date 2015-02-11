#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
pid_t pid;

pid=fork();
if(0==pid)
{
printf("Child\n");
}
else
{
printf("Parent\n");
execlp("pgm2",NULL);
}
}
