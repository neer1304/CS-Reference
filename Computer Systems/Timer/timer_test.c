#include<sys/time.h>
#include<sys/types.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *strsignal (int sig);

void timer_handler (int a)
 {
  /* handle signal */
  printf ("\nsignal Caught signal no : %s\n\n", (char *) strsignal (a));

 }

main ()
{
  int retval;
  struct itimerval timerValue;
  struct itimerval oldTimerValue;
  timerValue.it_interval.tv_sec = 3;
  timerValue.it_interval.tv_usec = 0;

  timerValue.it_value.tv_sec = 1;
  timerValue.it_value.tv_usec = 0;


   signal (SIGALRM, timer_handler);
   retval = setitimer (ITIMER_REAL, &timerValue, NULL);

  if (-1 == retval)
    perror ("Could not set timer");


    while(1);

}
