#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sched.h>
#include<malloc.h>
#include<signal.h>

#define THREAD_STACK 1024*64	/*64 KB stack */
#define MAX_THREADS 10

int threadFunction (void *arg)
/*The child thread will execute the function */
{
  printf ("\nchild thread exiting");
  return 0;
}

main ()
{
  void *stack[MAX_THREADS];
  int thr_id_arr[MAX_THREADS];
  int i;
/*Create the child threads &Allocate the stack */

  printf ("\nCtreating child threads");

  for (i = 0; i < MAX_THREADS; i++)
   {
    stack[i] = malloc (THREAD_STACK);

    thr_id_arr[i] =
      clone (&threadFunction, (char *) stack[i] + THREAD_STACK,
	     SIGCHLD | CLONE_FS | CLONE_VM | CLONE_FILES | CLONE_SIGHAND, 0);
        

if (thr_id_arr[i] == -1)
  {
    perror ("clone");

    exit (1);
  }
}

for (i = 0; i < MAX_THREADS; i++)
  {
    thr_id_arr[i] = waitpid (thr_id_arr[i], 0, 0);
    if (thr_id_arr[i] == -1)
      {
	perror ("waitpid");
	exit (1);
      }
  }

for (i = 0; i < MAX_THREADS; i++)
  {
    free (stack);
    printf ("\nchild thread returned and stack freed");
  }

return 0;
}
