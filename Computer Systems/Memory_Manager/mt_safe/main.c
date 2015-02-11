/*
A simple program having two threads alocating/deallocating dynamic memory
startThread1 is the entry point function of one thread
startThread2 is the entry point function of the other thread
*/

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>


/*
startThread1 takes an input through thread creation and prints it after properly typecasting it
*/

void * startthread1(void * thr_p) 
{
	int i;
	/* test my malloc and my free */
	char *block;
	char *block1;
	block = mymalloc(16);
	if(NULL == block)
	{
		printf("memory not allocated by mymalloc");
	}
	else
	{
		sprintf(block,"ABCDE");
		printf("block is %s\n",block);
	}
	
	block1 = mymalloc(16);
	if(NULL == block1)
		printf("memory not allocated by mymalloc");
	else
	{
		sprintf(block1,"12345");
		printf("block1 is %s\n",block1);
	}
	myfree(block);
	myfree(block1);
	return 1;
}

/*
startThread2 prints the thread id and the value of a local variable i in a loop
*/

void * startthread2(void * thr_p) 
{
	int i;
	/* test my malloc and my free */
	char *block;
	char *block1;
	block = mymalloc(16);
	if(NULL == block)
	{
		printf("memory not allocated by mymalloc");
	}
	else
	{
		sprintf(block,"ZYXWVU");
		printf("block is %s\n",block);
	}
	
	block1 = mymalloc(16);
	if(NULL == block1)
		printf("memory not allocated by mymalloc");
	else
	{
		sprintf(block1,"98765");
		printf("block1 is %s\n",block1);
	}
	myfree(block);
	myfree(block1);
	return 1;
}

/*
main creates two threads and waits for them to exit
threads have system scope
threads are passed the address of a local variable defined in main 
*/


int main()
{
	int retval;
	int thread1input = 10;
	int thread2input = 10;
	pthread_t m_ThreadId;
	pthread_t l_ThreadId;
	pthread_attr_t atrr;
	pthread_attr_init(&atrr); // initialize attr with default attributes
	pthread_attr_setscope(&atrr, PTHREAD_SCOPE_SYSTEM);

retval=pthread_create(&l_ThreadId, &atrr,startthread1, (void*)(&thread1input));
	if (0 != retval)
	{
		printf("thread creation failed\n");
		return (-1);
	}
retval = pthread_create(&m_ThreadId, NULL, startthread2, (void*)&thread2input);
	if (0 != retval)
	{
		printf("thread creation failed\n");
		return (-1);
	}
	printf("main thread %d %d\n", pthread_self(), thread1input);


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
	printf("main thread %d\n", pthread_self());
	return 0;
}
