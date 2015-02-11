#include<stdio.h>
#include<time.h>
#include<signal.h>
static void sig_usr(int);
main()
{
	char buf[4];
	struct sigevent signal_spec;
	timer_t created_timer;
	struct itimerspec new , old;
	signal_spec.sigev_signo=SIGINT;
	signal_spec.sigev_notify=SIGEV_SIGNAL;
	signal(SIGINT,sig_usr);
	if (timer_create(CLOCK_REALTIME,&signal_spec,&created_timer)==0)
	{
		printf("Timer Creation is successful\n");
	}
	else 
	{
		printf("Timer Creation is unsuccessful\n");
		exit(0);
	
	}
	/*Set the itimerspec strcture*/
	new.it_value.tv_sec=1;
	new.it_value.tv_nsec=0;
	new.it_interval.tv_sec=2;
	new.it_interval.tv_nsec=0;
	/*Setting the timer*/
	timer_settime(created_timer,0,&new,NULL);
         while(1)
	 {
            pause();
         }	
	
}
	
static void sig_usr(int signo)
{
	printf("Signal Received\n");
}



