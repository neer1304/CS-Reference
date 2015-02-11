#include<stdio.h>
#include<time.h>
#include<signal.h>
static void sig_usr1(int);
static void sig_usr2(int);
main()
{
	struct sigevent signal_spec;
	timer_t created_timer1,created_timer2;
	struct itimerspec new ,new1;
	signal_spec.sigev_signo=SIGUSR1;

	signal_spec.sigev_notify=SIGEV_SIGNAL;
	signal(SIGUSR1,sig_usr1);
	signal(SIGUSR2,sig_usr2);
	if (timer_create(CLOCK_REALTIME,&signal_spec,&created_timer1)==0)
	{
		printf("Timer 1 Creation is successful\n");
	}
	else 
	{
		printf("Timer Creation is unsuccessful\n");
		exit(0);
	
	}
	/*Timer 2 raises SIGUSR2*/
	signal_spec.sigev_signo=SIGUSR2;

	if (timer_create(CLOCK_REALTIME,&signal_spec,&created_timer2)==0)
	{
		printf("Timer 2 Creation is successful\n");
	}
	else 
	{
		printf("Timer Creation is unsuccessful\n");
		exit(0);
	
	}
	/*Set the itimerspec strcture for timer 1*/
	new.it_value.tv_sec=2;
	new.it_value.tv_nsec=0;
	new.it_interval.tv_sec=0;
	new.it_interval.tv_nsec=0;
	
	/*Setting the timer for Timer 1*/
	timer_settime(created_timer1,0,&new,NULL);

	/*Set the itimerspec strcture for timer 2*/
	new1.it_value.tv_sec=1;
	new1.it_value.tv_nsec=0;
	new1.it_interval.tv_sec=1;
	new1.it_interval.tv_nsec=0;

	/*Setting the timer for Timer 2*/
	timer_settime(created_timer2,0,&new1,NULL);
	for(;;)
		pause();
		
}
	
static void sig_usr1(int signo)
{
	printf("Timer 1 fired\n");
}

static void sig_usr2(int signo)
{
	printf("Timer 2 fired\n");
}


