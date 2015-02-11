/*
It demonstrates that if signal() system call is made more than once for 
the same signal with different signal handlers, the signal handler installed by 
the last signal() call will persist.
It also demonstrates that the signal handler can be installed from a signal handler also
*/

#include<stdio.h>
#include<signal.h>
#include<errno.h>

void alternate_handler(int signum);

void signal_handler(int signum)
{
	printf("signal_handler for signal : %d invoked\n", signum);
	signal(SIGINT,alternate_handler);
}

void alternate_handler(int signum)
{
	printf("alternate_handler for signal : %d invoked\n", signum);
	signal(SIGINT,signal_handler);
}


main()
{
	int sigret = 0;
	signal(SIGINT,signal_handler);
   /* 	if (errno != 0) 
	{
		printf("SIGINT set error %d \n", errno);
	}*/
	while(1) 
	{
		raise(SIGINT);
		//pause();
		sleep(3);
		printf("signal demo: while loop \n");
	}
	printf("can't print this \n");
}
