/*
Reader Writer problem using one global array of size > 1 using semaphore 

*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<semaphore.h>

#define BUFFERSIZE 5 
#define LOOPSIZE   10

int    buffer[BUFFERSIZE];
sem_t  reader;
sem_t  writer;

/*
Writer function writes into a buffer and indicates to the reader that it has written. After writing into the buffer it waits for the reader to read it and reapeats the process
*/

void* writer_thread(void *arg)
{
	int lindex = 0;
	int buffindex = 0;
	for (buffindex = 0; buffindex < BUFFERSIZE;)
	{
		sem_wait(&writer);
		buffer[buffindex] = lindex++;
		sem_post(&reader);

                if (lindex == LOOPSIZE)
			break;
		if (buffindex == BUFFERSIZE-1)
			buffindex = 0;
		else
			buffindex++;
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
	int lindex = 0;
	int buffindex = 0;
	for (buffindex = 0; buffindex < BUFFERSIZE; )
	{
		sem_wait(&reader);
		printf("buffer[%d] = %d\n", buffindex, buffer[buffindex]);
		sem_post(&writer);
		if (++lindex == LOOPSIZE)
			break;
		if (buffindex == BUFFERSIZE-1)
			buffindex = 0;
		else
			buffindex++;
	}
	return NULL;
}


int main(void)
{
	pthread_t tid1,tid2;
	int rv1,rv2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
//	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

	sem_init(&reader, 0, 0);
	sem_init(&writer, 0, BUFFERSIZE);

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
