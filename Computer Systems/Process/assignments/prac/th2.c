#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
pid_t pid;
int childstatus;
printf("The parent is %d\n",getpid());
pid = fork();
//if (pid == 0) 
//{
//fork();
//pid = fork(); 
//printf("The parent pid of parent is %d\n",getpid());
if (pid == 0)
{
//printf("The id of this child is %d\n",getpid());
fork();
//printf("The id of this child is %d\n",getpid());
fork();
//printf("The id of this child is %d\n",getpid());
fork();
printf("child\n");
}
//}
else
{
pid = wait(&childstatus);
printf("process id of child %d\n", pid);
}
return 1;
}

