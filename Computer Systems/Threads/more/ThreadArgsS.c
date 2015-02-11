/***************************************************************************
*       FILENAME : ThreadArgs.c
*       DESCRIPTION:Contains Code for a program that demonstrates the
*       use of pthread calls
*       Invoke the Executable as a.out*      
****************************************************************************/
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define NUM_THREAD 5

void *printme(void *th)
{
	int *p;
	p=(int*)th;
	printf("I am Thread %d\n",*p);
	free(th);
	pthread_exit(NULL);
}

main()
{
	pthread_t threads[NUM_THREAD];
	int t,rc;
	int *iptr;
	/*Creating the Threads*/
	for(t=0;t<NUM_THREAD;t++)
	{
		printf("Creating Thread\n");
		iptr = (int*)malloc(sizeof(int));
		*iptr=t;
		rc = pthread_create(&threads[t],NULL,printme,(void*)iptr);
		if(rc) printf("Printf Error Creating Thread");
	}
	pthread_exit(NULL);
}

















