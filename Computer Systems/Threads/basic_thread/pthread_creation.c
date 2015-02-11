/*
A simple program having three threads
startroutine1 is the entry point function of the first thread created by the main thread
startroutine2 is the entry point function of the second thread created by the main thread

what are we demonstrating in this program:
1. how to use pthread_create API

2. how to use pthread_join API to wait for a thread to finish and collect the returned data object

3. how to use pthread_exit API to return from a thread 

4. why the parameter to be passed to thread creation function have to be void *

Answer: It has to be generic type as we don't know what type of object will be needed by the application specific thread start routine so it has to be void *

5. why the parameter to be passed to pthread_join has to be void **

Answer:
The thread routine could return only a void pointer as it was a generic routine and the address of the object which it is returning will not be known before the object is returned by it.

The API pthread_join function has to get the address of the object being returned by the thread. The parameter that is passed to pthread_join will need to be modified, so it has to be an address. But what it is getting from the returning thread is also an address so we have to pass an address to an address to pthread_join().

6. why only one parameter is passed to thread creation function, how to pass more than one parameter to the thread creation function?

Answer: It is not known, how many parameters will be required by the start routine function of the thread. One was decided to be the number to keep it simple. One can always pass a pointer to a structure


7. passed parameter, have to be checked for NULL before it can be used in the thread startroutine function

Answer: nothing related to thread, just plain and simple C concept


*/

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include<stdlib.h>
#define LOOPSZ	8

int t1retval = 2;
int t2retval = 10;

/*
startroutine1 takes an input and prints it after properly typecasting it
*/

void * startroutine1(void * thr_p) 
{
	int i = 0;
	//int pinput = *((int *) thr_p);
	int pinput = thr_p ? *((int *) thr_p) : 0;
	
	printf("startroutine1  threadid : %lu\n", pthread_self());

	while (i++ < LOOPSZ)
	{
		printf("startroutine1  thread %d %d\n", i, pinput);
		sleep(1);
	}
	return ((void *) &t1retval);
}

/*
startroutine2 prints the thread id and the value of a local variable i in a loop
*/

void * startroutine2(void * thr_p)
{	
	int i = 0;
	//int pinput = *((int *) thr_p);
	int pinput = thr_p ? *((int *) thr_p) : 0;

	printf("startroutine2  threadid : %lu\n", pthread_self());

	while (i++ < LOOPSZ) 
	{
		printf("startroutine2 thread %d %d\n", i, pinput);
	//	sleep(1);

	}
	pthread_exit ((void *) &t2retval);
	//return ((void *) &t1retval);
}

/*
main creates two threads and waits for them to exit
one of the threads is passed the address of a local variable defined in main whereas the other one is given a NULL parameter
*/


int main()
{
	int retval;
	int * pthreadoutput;
	int thread1input = 10;
	pthread_t tidOne;
	pthread_t tidTwo;
//	pthread_attr_t atrr;
	//pthread_attr_init(&atrr); // initialize attr with default attribute
	//pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);
	retval = pthread_create(&tidOne, NULL, startroutine1, (void *)(&thread1input));
	if (0 != retval)
	{
		printf("thread creation failed\n");
		return (-1);
	}
	printf("%lu\n", tidOne);
	retval = pthread_create(&tidTwo, NULL, startroutine2, (void *)NULL);
	if (0 != retval)
	{
		printf("thread creation failed\n");
		return (-1);
	}
	printf("%lu\n", tidTwo);
	retval = pthread_join(tidOne, (void**)&pthreadoutput);
	
	printf("threadoutput %d\n", *pthreadoutput);
	if (0 != retval)
	{
		printf("thread join failed\n");
		return (-1);
	}

	retval = pthread_join(tidTwo, (void**)&pthreadoutput);

	printf("threadoutput %d\n", *pthreadoutput);
	if (0 != retval)
	{
		printf("thread join failed\n");
		return (-1);
	}
	return 0;
}
