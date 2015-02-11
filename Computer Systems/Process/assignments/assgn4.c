#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
pid_t pid;
if(argc<2)
{
printf("Program Usage:Executable Command CmdFlags\n");
exit(1);
}
else
{
//printf("argv has value %s",*argv);
pid=fork();

if(0==pid)
{
execvp(argv[1],argv+1);
}
else
{
printf("In parent\n");
wait(NULL);
}
}
return 0;
}
