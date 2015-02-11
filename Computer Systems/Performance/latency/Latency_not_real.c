#include<signal.h>
#include<stdio.h>
#include<sys/times.h>
#include<time.h>

void catch_alarm (int signo)
  {
    printf ("\nSignal Caught\n");
  }

main ()
 {
    int a;
    int i;
    int initial_time,final_time; 
    char name[10];
    struct tms now, later;

    //signal (SIGALRM, catch_alarm);

    initial_time = times (&now);
    printf ("times gives %d\n", initial_time);
    printf ("user time,system time is %d: %d:\n", now.tms_utime, now.tms_stime);
    puts("\nenter your name:\n\n");
    gets(name);
    for (i = 1; i < 10000; i++)
      {
        puts(name);
        a = 1;
      } 
    final_time = times (&later);

   printf ("times gives %d\n", final_time);

   printf ("user time,system time is %d: %d:\n", later.tms_utime, later.tms_stime);
 }
