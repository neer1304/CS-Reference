#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> /* for malloc */
#include <unistd.h> /* for sleep */
extern int errno;

void *ThreadRoutine(void *arg)
{
  int a;
  a = *(int *)arg;
  printf("Thread %ld woke up with value %d\n",pthread_self(),a);
  pthread_exit(NULL);
}

int main()
{
  pthread_t threadIds[10];
  int index,index1;
  int *p_argptr;
  int retval;
  for (index=1;index<=10;index++) 
  {
    p_argptr = (int *)malloc(sizeof(int));
    *p_argptr = index;
     retval = pthread_create(&threadIds[index], NULL,ThreadRoutine,(void*)p_argptr);
     if (-1 == retval) 
         perror("Error creating thread");
  }
  for (index1=1;index1<=10;index1++) 
  {
    retval = pthread_join(threadIds[index1],NULL);
    if (0 != retval ) 
	perror("Error in pthread_join");
  }
	pthread_exit(NULL);
}

