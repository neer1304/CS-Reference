#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

void sigusr2_handler(int code)
{
printf("SIGUSR2 signal handler called\n");
raise(SIGINT);
}

int main()
{
printf("In main\n");
signal(SIGUSR2,sigusr2_handler);
printf("Now raising SIGUSR2 and terminating\n");
raise(SIGUSR2);
}
