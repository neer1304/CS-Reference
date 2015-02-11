#include<sys/time.h>
#include<sys/resource.h>
#include<unistd.h>
#include<errno.h>
#include<sched.h>
#include<stdio.h>

#define DEBUG 1
#define MAX_THREADS 5
#define THREAD_STACK 1024

int  g_temp = 10;
int new_thread()
{

  g_temp+= 10;
}

main()
{

  int thrd_id_arr[MAX_THREADS],ret_val,i;
  char *thrd_stack[MAX_THREADS];  


#ifdef DEBUG
  printf("\n g_temp before new thrd = %d", g_temp);
#endif
  for(i =0; i<MAX_THREADS;i++)
{
   
    thrd_stack[i] = (void *)malloc(THREAD_STACK);

  if(thrd_stack[i]== NULL)
   perror("\nCould not allocate memory for Stack");
    printf("\nI am here\n");
    fflush(stdout);


thrd_id_arr[i] = clone(new_thread, thrd_stack[i], CLONE_VM|CLONE_FS, NULL);

#ifdef DEBUG
  printf(" new thrd id = %d", thrd_id_arr[i]);
#endif

  if(thrd_id_arr[i]<0)
	perror("\n could not create new thrd " );
}
sleep(10);
#ifdef DEBUG
  printf("\n g_temp after new thrd = %d", g_temp);
#endif

}
