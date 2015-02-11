#include<stdio.h>
#include<unistd.h>

int main()
{
pid_t pid;
int childstatus;
pid = fork();
if (pid == 0) {
pid = fork();
if (pid == 0)
{
printf("child");
}
}
else {
pid = wait(&childstatus);
printf("process id of child %d", pid);
}
return 1;
}

