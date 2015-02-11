/*
Reader Writer problem using one global buffer of size 1 using mutex and co ndition variable

*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

#define LOOPSZ 		20

#define BUFFERFULL	1
#define BUFFEREMPTY	0


int 		buffer;
int 		bufferindicator = BUFFEREMPTY;
pthread_mutex_t cmutex 		= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t 	condvar 	= PTHREAD_COND_INITIALIZER;

/*
Writer function writes into a buffer and indicates to the reader that it has written. After writing into the buffer it waits for the reader to read it and reapeats the process
*/



void* writer_thread(void *arg)
{
	int lindex = 0;
	pthread_mutex_lock(&cmutex);
	while(lindex < LOOPSZ)
	{
		while (bufferindicator == BUFFERFULL)
			pthread_cond_wait(&condvar,&cmutex);
//		scanf("%d", &buffer);
		buffer = lindex;
		bufferindicator = BUFFERFULL;
		lindex++;
		pthread_cond_signal(&condvar);
	}
	pthread_mutex_unlock(&cmutex);
	return NULL;
	
}

/*
Reader function waits for the writer to write into the buffer and reads from the bufffer once the writer indicates to it that it has written. 
After reading from the buffer Reader indicates to the writer that it has read.
This process is repeated again and again
*/

void* reader_thread(void *arg)
{
	int lindex = 0;
	pthread_mutex_lock(&cmutex);
	while(lindex<LOOPSZ)
	{
		while (bufferindicator == BUFFEREMPTY)
			pthread_cond_wait(&condvar,&cmutex);
		printf("buffer = %d\n",buffer);
		bufferindicator = BUFFEREMPTY;
		lindex++;
		pthread_cond_signal(&condvar);
		printf("hello\n");
	}
	pthread_mutex_unlock(&cmutex);
	return NULL;
}
	
int main(void)
{
	pthread_t tid1,tid2;
	int rv1,rv2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
//	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	rv1 = pthread_create(&tid1,&attr,(void *)writer_thread,NULL);
	if(rv1 != 0)
	{
		printf("\n Cannot create thread");
		exit(0);
	}
	rv1 = pthread_create(&tid2,&attr,(void *)reader_thread,NULL);
	if(rv1 != 0)
	{
		printf("\n Cannot create thread");
		exit(0);
	}
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return(0);
}
