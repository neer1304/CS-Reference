#include<stdio.h>
#include<unistd.h>

int main()
{
pid_t pid;
int childstatus;
pid = fork();
fork();
fork();
if (pid == 0) {
pid = fork();
pid=fork();
//pid=fork();
//pid=fork();
if (pid == 0)
{
printf("child\n");
}
}
else {
pid = wait(&childstatus);
printf("process id of child %d\n", pid);
}
return 1;
}

