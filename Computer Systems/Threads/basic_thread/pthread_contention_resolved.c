/*
A simple program having two threads
startThread1 is the entry point function of one thread
startThread2 is the entry point function of the other thread
both threads try to access a globalvar simultaneously and experience contention as they try to share the global variable
they resolve contention by using a mutex variable and locking it appropriately
*/

#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

//struct mystruct globalvar;
//float globalvar;


#define LOOP_SIZE 0x2fff
#define THR1_LOOP_START 0
#define THR2_LOOP_START 0x8fff

int globalvar = 0;
int anotherglobal = 0;

pthread_mutex_t gmutex;

void * commonfunction(int local) {
	int i = 0;
//	pthread_mutex_lock(&gmutex);
	globalvar=local;
	while (i++ < LOOP_SIZE)
	{
		globalvar++;
		printf("thread id : %d : globalvar : %d\n", pthread_self(), globalvar);
	}
//	pthread_mutex_unlock(&gmutex);
	return ((void *) NULL);
}

void * depositing(void * thr_p) {
	while (1)
	{
		pthread_mutex_lock(&gmutex);
		deposit(20);
		pthread_mutex_unlock(&gmutex);
	}
	return ((void *) NULL);
}


void * withdrawal(void * thr_p) {
	while (1)
	{
		pthread_mutex_lock(&gmutex);
		withdraw(50);
		pthread_mutex_unlock(&gmutex);
	}
	return ((void *) NULL);
}


int main()
{
	int retval;
	pthread_t m_ThreadId;
	pthread_t l_ThreadId;
	pthread_attr_t atrr;
	pthread_attr_init(&atrr); // initialize attr with default attributes
	pthread_attr_setscope(&atrr, PTHREAD_SCOPE_SYSTEM);
	pthread_mutex_init(&gmutex, NULL);

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
