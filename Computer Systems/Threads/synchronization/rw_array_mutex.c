/*
Reader Writer problem using one global array of size > 1 using mutex and condition variable

*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

#define BUFFERSIZE	5
#define BUFFERFULL	BUFFERSIZE
#define BUFFEREMPTY	0
#define LOOPSZ		20

int buffer[BUFFERSIZE];

int bufferindicator = BUFFEREMPTY;

pthread_mutex_t cmutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condvar = PTHREAD_COND_INITIALIZER;

/*
Writer function writes into a buffer and indicates to the reader that it has written. After writing into the buffer it waits for the reader to read it and reapeats the process
*/



void* writer_thread(void *arg)
{
	int loopindex = 0;
	int bufferindex = 0;
	pthread_mutex_lock(&cmutex);
	while(bufferindex < BUFFERSIZE)
	{
		while (bufferindicator == BUFFERFULL)  
                //if the buffer is full then wait on condition as cannot write beyond buffer
		pthread_cond_wait(&condvar,&cmutex);
		buffer[bufferindex] = loopindex;
		printf("Written value in buffer[%d]\n", bufferindex );
                bufferindicator++;
		pthread_cond_signal(&condvar);
		if (++loopindex == LOOPSZ)  //if loop is complete break
			break;
		//if the write buffer is full re-initialize the buffer
		if (bufferindex == (BUFFERSIZE-1)) 
			bufferindex = 0;
		else
			bufferindex++;
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
	int loopindex = 0;
	int bufferindex = 0;
	pthread_mutex_lock(&cmutex);
	while(bufferindex < BUFFERSIZE)
	{
		while (bufferindicator == BUFFEREMPTY)
		pthread_cond_wait(&condvar,&cmutex); 
//wait on the condition on shared variable which is if buffer is empty then reader has to wait so it goes in  sleep state
		printf("buffer[%d] = %d\n",bufferindex, buffer[bufferindex]);
		bufferindicator--;
		pthread_cond_signal(&condvar);
		if (++loopindex == LOOPSZ)
			break;
		//if the read buffer is full then initialize it again
		if (bufferindex == (BUFFERSIZE-1))
			bufferindex = 0;
		else
			bufferindex++;
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
