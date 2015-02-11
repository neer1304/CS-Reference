#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
pid_t pid;

execlp("pgm2",(char*)0);
pid=fork();

if(0==pid)
{
printf("Child\n");
}
else
{
printf("Parent\n");
wait(NULL);
}
}
