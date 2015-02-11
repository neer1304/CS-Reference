#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<sys/time.h>
#include<stdlib.h>
#include<signal.h>

time_t cur_time;

void timer_handler(int signal)
  {
    cur_time = time(NULL);
    printf("\ninside handler%s\n\n",ctime(&cur_time));
  }

struct itimerval interval;

main()
  {
   interval.it_interval.tv_sec = 2;// repetition interval
   interval.it_interval.tv_usec =0 ;


   interval.it_value.tv_sec=1;//curent value
   interval.it_value.tv_usec=0;

   signal(SIGALRM,timer_handler);

   setitimer(ITIMER_REAL,&interval,NULL);


//   cur_time=time(NULL);
  // printf("\nStart time = %s\n",ctime(&cur_time));

   while(1)
    {	
	//printf("hello\n");
	//sleep(1);	
	pause();
    } 
}   

