/*
A simple program having two threads
startThread1 is the entry point function of one thread
startThread2 is the entry point function of the other thread
both threads try to access a globalvar simultaneously and experience contention as they try to share the global variable
*/

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int globalvar = 0;

#define LOOP_SIZE 1
#define THR1_LOOP_START 0
#define THR2_LOOP_START 40 


/*
sets globalvar to the value passed to the function as the input parameter
increments globalvar in the loop and prints it along with the thread id
*/

void * commonfunction(int local) {
	int i = 10;
	globalvar=local;
	while (i++ > LOOP_SIZE) {
		globalvar++;
		printf("thread id : %d : globalvar : %d \n", pthread_self(), globalvar);
		printf("address of i & globalvar : %u : %u\n", &i, &globalvar);
	}
	return ((void *) NULL);
}

/*
startThread1 calls the commonfunction with THR1_LOOP_START as the loop start point
*/

void * startthread1(void * thr_p) {
	commonfunction(THR1_LOOP_START);
	return ((void *) NULL);
}


/*
startThread2 calls the commonfunction with THR2_LOOP_START as the loop start point
*/

void * startthread2(void * thr_p) {
	commonfunction(THR1_LOOP_START);
	return ((void *) NULL);
}


/*
main creates two threads and waits for them to exit
threads have system scope
both the threads are given NULL as the parameter
*/

int main()
{
	int retval;
	pthread_t m_ThreadId;
	pthread_t l_ThreadId;
	pthread_attr_t atrr;
	pthread_attr_init(&atrr); // initialize attr with default attributes
	pthread_attr_setscope(&atrr, PTHREAD_SCOPE_SYSTEM);

	retval = pthread_create(&l_ThreadId, &atrr, startthread2, (void *)NULL);
	if (0 != retval)
	{
		printf("thread creation failed\n");
		return (-1);
	}
	retval = pthread_create(&m_ThreadId, NULL, startthread1, (void *)NULL);
	if (0 != retval)
	{
		printf("thread creation failed\n");
		return (-1);
	}
	pthread_exit(&retval);
	printf("main thread will not come here\n");


	retval = pthread_join(l_ThreadId, NULL);
	if (0 != retval)
	{
		printf("thread join failed\n");
		return (-1);
	}
	retval = pthread_join(m_ThreadId, NULL);
	if (0 != retval)
	{
		printf("thread join failed\n");
		return (-1);
	}


	return 0;

}
