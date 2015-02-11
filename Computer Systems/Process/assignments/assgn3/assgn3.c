#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
pid_t pid;

pid=fork();

if(0==pid)
{
printf("Child\n");
execlp("pgm2",(char*)0);
}
else
{
printf("Parent\n");
wait(NULL);
}
}
