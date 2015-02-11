#include<stdio.h>
#include<sched.h>
#include<sys/types.h>
#include<sys/wait.h>

#define THREAD_STACK 1024

int a = 5;

void *do_temp ()
{
  a += 5;
}

main ()
{
  int i, ntid[5];
  void *thr_stk[5];


  for (i = 0; i < 5; i++)
    {
      thr_stk[i] = malloc (THREAD_STACK);
      ntid[i] = clone ((void *) &do_temp, (char *) thr_stk[i] + THREAD_STACK,
		       CLONE_VM | CLONE_VFORK, NULL);
      printf("\nthe value of a is %d\n",a);
    }

      for(i=0;i<5;i++)
      free(thr_stk);
}
