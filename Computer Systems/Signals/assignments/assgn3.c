#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

void alarm_handler(int code)
{
printf("You did not entered input in 3 sec please enter again..\n");
printf("Enter your name in alarm handler\n");
alarm(3);
}

int main()
{
signal(SIGALRM,alarm_handler);
int sr=0;
char name[10];
while(sr!=1)
{
printf("Enter your name in while loop\n");
alarm(3);
sr=scanf("%s",name);
}
sleep(11);
//raise(SIGALRM);
printf("You entered %s\n",name);
}

