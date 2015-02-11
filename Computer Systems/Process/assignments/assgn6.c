#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>

int main()
{
pid_t pid,i;
int status=10;
if((pid=fork())==0)
{
printf("pid of first child is %d and its parent is %d\n",getpid(),getppid());
if((pid=fork())>0) //Same as child
{
wait(NULL);
printf("pid of second child is %d and its parent id is %d\n",getpid(),getppid());
exit(10);
}
sleep(2);
printf("Second Child, parent Id =%d\n",getppid());
exit(0);
}
else
{
//Parent code
i=wait(&status); //get the status of terminated child
printf("after loop pid is %d and parent id is %d\n",getpid(),getppid());
printf("My Child with pid %d exited with status %d\n",i,WEXITSTATUS(status));
}
return 0;
}

