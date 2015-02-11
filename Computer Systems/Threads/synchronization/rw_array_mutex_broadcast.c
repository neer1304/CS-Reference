/*
Reader Writer problem using one global array of size > 1 using mutex and condition variable

*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

#define BUFFERSIZE	10
#define BUFFERFULL	BUFFERSIZE
#define BUFFEREMPTY	0
#define LOOPSZ		20

int buffer[BUFFERSIZE];

int bufferindicator = BUFFEREMPTY;

int readbufferindex = 0;

pthread_mutex_t cmutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cempty = PTHREAD_COND_INITIALIZER;
pthread_cond_t  cfull  = PTHREAD_COND_INITIALIZER;

/*
Writer function writes into a buffer and indicates to the reader that it has written. After writing into the buffer it waits for the reader to read it and reapeats the process
*/



void* writer_thread(void *arg)
{
	int loopindex = 0;
	int bufferindex = 0;
	while(loopindex < LOOPSZ)
	{
		pthread_mutex_lock(&cmutex);
                printf("Mutex locked by writer thread %d\n", pthread_self() );
		if (BUFFERSIZE-1 == bufferindex)
			bufferindex = 0;
		else
			bufferindex++;
		//If the buffer is full wait for writer and signal the reader
		while (bufferindicator == BUFFERFULL)
		{
			pthread_cond_signal(&cempty);

			pthread_cond_wait(&cfull,&cmutex);
		}
		buffer[bufferindex] = loopindex++;
		bufferindicator++;
		if (BUFFERSIZE-1 == bufferindex)
			bufferindex = 0;
		else
			bufferindex++;
		pthread_cond_broadcast(&cempty); //release all the reader thread waiting on empty condition
		pthread_mutex_unlock(&cmutex);
	}
	return NULL;
}

/*
Reader function waits for the writer to write into the buffer and reads from the bufffer once the writer indicates to it that it has written. 
After reading from the buffer Reader indicates to the writer that it has read.
This process is repeated again and again
*/

void* reader_thread(void *arg)
{
	int loopindex = 0;
	while(loopindex < LOOPSZ)
	{
		printf("\nReader thread %d trying to lock mutex\n", pthread_self());
                pthread_mutex_lock(&cmutex);
		printf("I am going to sleeping threadid %d\n",pthread_self());
		while (bufferindicator == BUFFEREMPTY)
                { 
		     //if the buffer is empty put the reader on wait	
                     printf("\nReader thread %d is waiting on condition cempty\n", pthread_self() );
                     pthread_cond_wait(&cempty,&cmutex);
		}
                printf("threadid %d : buffer[%d] = %d\n",pthread_self(), readbufferindex, buffer[readbufferindex]);
		bufferindicator--;
		if (readbufferindex == (BUFFERSIZE-1))
			readbufferindex = 0;
		else
			readbufferindex++;
		pthread_cond_signal(&cempty);
                printf("\n Reader thread %d signalling condition cempty\n", pthread_self() );  
		pthread_mutex_unlock(&cmutex);
		printf("I will not sleep now threadid %d\n",pthread_self());
		sleep(1);
	}
	return NULL;
}

	
int main(void)
{
	pthread_t tid1, tid2, tid3, tid4;
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
	rv1 = pthread_create(&tid3,&attr,(void *)reader_thread,NULL);
	rv1 = pthread_create(&tid4,&attr,(void *)reader_thread,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
	pthread_join(tid4,NULL);

	return(0);
}
