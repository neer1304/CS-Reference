#include<signal.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
//signal(SIGTERM,SIG_DFL);
pid_t pid;

pid=fork();

if(0==pid)
{
printf("In Child\n");
printf("Sleeping child for 5 sec\n");
sleep(5);
printf("Child terminating\n");
}

else
{
printf("In parent\n");
printf("Sending terminate signal to child\n");
kill(pid,SIGTERM);
}
printf("The pid is %d and ppid is %d\n",getpid(),getppid());
return 0;
}
