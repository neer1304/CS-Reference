/*
A simple program having three threads
startroutine1 is the entry point function of the first thread created by the main thread
startroutine2 is the entry point function of the second thread created by the main thread

what are we demonstrating in this program:

1. What is a detached thread and how to create a detached thread - something which does not leave its trace, exit status is not available to collect

2. Why do we need to wait for threads using pthread_join and which type of threads one can wait for - joinable and detached threads

3. It also demonstrates that when any thread including the main thread calls pthread_exit, only that thread exits. If main() function returns from the program(implicit or explicit) the program exits.

4. It also demonstrates that by default all threads are joinable including the main thread unless a programmer changes the status explicitly

*/

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#define LOOPSZ	8

/*
startroutine1 
*/

void * startroutine1(void * thr_p) 
{
	int i = 0;
	int retval = 0;
	pthread_t *poutput = NULL;
	pthread_t  pinput = thr_p ? *((pthread_t *) thr_p) : 0;
	
	printf("startroutine1  threadid: %lu : main threadid: %lu\n", pthread_self(), pinput);

	retval = pthread_join(pinput, (void**)&poutput);

	if (0 != retval)
	{
		printf("thread join failed\n");
	}
	printf("threadoutput %lu\n", *poutput);


	while (i++ < LOOPSZ)
	{
		printf("startroutine1  thread %d \n", i);
		sleep(1);
	}
	return (NULL);
}

/*
startroutine2 
*/

void * startroutine2(void * thr_p)
{
	int i = 0;
	int pinput = thr_p ? *((int *) thr_p) : 0;

	printf("startroutine2  threadid : %lu\n", pthread_self());

	while (i++ < LOOPSZ) 
	{
		printf("startroutine2 thread %d %d\n", i, pinput);
		sleep(1);
	}
	return (NULL);
}

/*
main creates two threads 
*/

pthread_t thread1input;

int main()
{
	int retval;
	pthread_t tidOne;
	pthread_t tidTwo;
	pthread_attr_t atrr;
	pthread_attr_init(&atrr); // initialize attr with default attributes

	thread1input =  pthread_self();

	retval = pthread_create(&tidOne, &atrr, startroutine1, (void *)(&thread1input));
	if (0 != retval)
	{
		printf("thread creation failed\n");
		return (-1);
	}
	retval = pthread_create(&tidTwo, NULL, startroutine2, (void *)NULL);
	if (0 != retval)
	{
		printf("thread creation failed\n");
		return (-1);
	}
	printf("main  threadid : %lu\n", pthread_self());

//following lines are for different experimentation with calls

	sleep(10);
	pthread_exit(&thread1input);
	return (0);
	sleep(10);

	/*sleep(10);
	return (0);
	retval = pthread_detach(pthread_self());
	if (0 != retval)
	{
		printf("thread detach failed\n");
	}
	sleep(10);
	//return (0);
	pthread_exit(&thread1input);*/

}
