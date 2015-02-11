#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<time.h>

timer_t created_timer[2];

void check_sigusr1(int signo)
 {
      if(signo == SIGUSR1)
      printf("\nFirst Timer Elapsed...%d...\n",created_timer[0]);
      
      if(signo == SIGUSR2)
      printf("\nSecond Timer Elapsed...%d...\n",created_timer[1]);
 }

 int main()
 {
      int i,index;
      struct itimerspec t_spec[2];
      struct sigevent sigeve_struct[2];
      signal(SIGUSR1, check_sigusr1);
      signal(SIGUSR2, check_sigusr1);
      sigeve_struct[0].sigev_signo = SIGUSR1;
      sigeve_struct[1].sigev_signo = SIGUSR2;

      for(index = 0; index < 2; index++)
      {
        sigeve_struct[index].sigev_notify = SIGEV_SIGNAL;
        if(timer_create(CLOCK_REALTIME, &sigeve_struct[index], &created_timer[index]) == 0)
      {
           printf("\nTIMER created successfully..%d..\n",created_timer[index]);
      }
      else
      {
           printf("\nTIMER not created successfully..\n");
           exit(0);
      }

      }

      t_spec[0].it_value.tv_sec = 1;
      t_spec[0].it_value.tv_nsec = 500000000;
      t_spec[0].it_interval.tv_sec = 2;
      t_spec[0].it_interval.tv_nsec = 0;
      
      timer_settime(created_timer[0], 0, &t_spec[0], NULL);
      
      t_spec[1].it_value.tv_sec = 1;
      t_spec[1].it_value.tv_nsec = 0;
      t_spec[1].it_interval.tv_sec = 5;
      t_spec[1].it_interval.tv_nsec = 500000000;

      timer_settime(created_timer[1], 0, &t_spec[1], NULL);

      for(;;);

      return 0;
 }

