/***************************************************************************
*	FILENAME : threadrace.c
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of modification of a global variable by multiple threads.
*	Invoke the Executable as a.out (Link with Linker option -lpthread)
*	Copyright 2007 Aricent 
****************************************************************************/
#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>

int counter;/*A global variable that will be accessed simultaneously by 
two threads*/
void *doit(void *);

int main()
{
	pthread_t th1,th2;/* th1 & th2 are Thread Identifiers */
	int status;
	/*Creating Thread1*/
	status=pthread_create(&th1,NULL,doit,NULL);
	if ( status )
	{
		printf("Error in Creating Thread\n");
		exit(status);
	}
	/*Creating Thread2*/
	status=pthread_create(&th2,NULL,doit,NULL);
	if ( status )
	{
		printf("Error in Creating Thread\n");
		exit(status);
	}
	/*Waiting for Thread 1 to Complete */
	status=pthread_join(th1,NULL);
	if ( status )
	{
		printf("Error in Joining a Thread\n");
		exit(status);
	}
	/*Waiting for Thread 2 to Complete */
	status=pthread_join(th2,NULL);
	if ( status )
	{
		printf("Error in Joining a Thread\n");
		exit(status);
	}
	printf("Main:The value of Counter is  %d\n",counter);
	exit(0);
}

/********************************************************************
*	FUNCTION NAME:doit
*	DESCRIPTION:Increments a global variable counter.
*	NOTES : No Error Checking is done .
*	RETURNS :void *
*********************************************************************/
void * doit(void *ptr)
{
	int count,localvar;
	//pthread_detach(pthread_self());
	for(count=0;count<15000;count++)
	{
		localvar = counter;
		printf("%d:%d\n",pthread_self()%10,localvar + 1);
		counter= localvar + 1;
	}
	return NULL;
}


