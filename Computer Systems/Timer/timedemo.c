#include<stdio.h>
#include<errno.h>
#include<time.h>
#include<signal.h>
static void sig_usr(int);
main()
{
	struct sigevent signal_spec;
	int ret;
	timer_t created_timer;
	struct itimerspec new , old;
	signal_spec.sigev_signo=SIGUSR1;
	signal_spec.sigev_notify=SIGEV_SIGNAL;
	if (SIG_ERR ==signal(SIGUSR1,sig_usr))
	{
		printf("Failed to registern Signal Handler\n");
		exit(1);
	}
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
            ret = pause();
	    if (-1 == ret)
	    {
		printf("Pause has returned\n");
		//Now Check errno
		//Trying to show that pause returs after a signal handler 
		//Has returned.
		if (EINTR == errno)
		{
			printf("Interrupted System Call\n");
		}
		else
		{
			perror("Pause Returned:");
		}
	    }
	   
         }	
	
}
	
static void sig_usr(int signo)
{
	printf("Signal Received from Timer\n");
}



