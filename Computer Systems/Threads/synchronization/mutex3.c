/*In this code there is one global variale declared.Main thread and mythread increments the myglobal variable 20 times individually.*/

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int myglobal;
pthread_mutex_t mymutex=PTHREAD_MUTEX_INITIALIZER;/*Static Initialization of mutex variable*/

void *thread_function(void *arg) 
{
	int i,j;
  	for ( i=0; i<20; i++ ) 
	{
   		pthread_mutex_lock(&mymutex);
    		j=myglobal;
    		j=j+1;
    		sleep(1);
    		myglobal=j;
		pthread_mutex_unlock(&mymutex);
    		printf("In thread_function value of myglobal:%d\n",myglobal);
//	    pthread_mutex_unlock(&mymutex);
  	}
  return NULL;
}

int main(void) 
{

	  pthread_t mythread;
  	  int i;

  	if ( pthread_create( &mythread, NULL, thread_function, NULL) ) 
  	{
       		printf("error creating thread\n");
       		exit(1);
  	}

  	for ( i=0; i<20; i++) 
  	{
    		pthread_mutex_lock(&mymutex);
    		myglobal=myglobal+1;
		pthread_mutex_unlock(&mymutex);
    		printf("In main value of myglobal:%d\n",myglobal);
//		   pthread_mutex_unlock(&mymutex);
    		sleep(1);
  	}

  	if ( pthread_join ( mythread, NULL ) ) 
  	{
      		printf("error joining thread\n");
      		exit(1);
  	}

  	printf("\nThe value of myglobal is %d\n",myglobal);

  	exit(0);

}
