#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int main()
{
printf("Inside main now sleeping for 5 sec..\n");
signal(SIGINT,SIG_IGN);
signal(SIGTERM,SIG_DFL);
sleep(3);
printf("Generating 'SIGINT' signal\n");
raise(SIGINT);
printf("After ignoring SIGINT signal\n");
printf("Generating 'SIGTERM' signal\n");
raise(SIGTERM);
printf("It won't print\n");
return 0;
}
