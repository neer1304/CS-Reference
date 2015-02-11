#include<stdio.h>
#include<pthread.h>

#define FAILURE 0
#define FREE 0
#define BUSY 1
#define NOT_INITIALIZED 0
#define INITIALIZED 	1

#define MAX_BLOCKS 	2
#define MAX_BLOCK_SIZE	1024
#define MAX_USER_BLOCK	1024

typedef struct block_info
{
	unsigned char status; /* block is free or used */
	char data[MAX_USER_BLOCK];

}Block_Info;

static int initindicator = NOT_INITIALIZED;
pthread_mutex_t gmutex = PTHREAD_MUTEX_INITIALIZER;

Block_Info memory_block_arr[MAX_BLOCKS];


int init()
{
	memset(memory_block_arr, 0, MAX_BLOCKS*MAX_BLOCK_SIZE);
}

char * mymalloc(size)
{
	int lindex;

	if(size> MAX_USER_BLOCK)
	{
		return (NULL);
	}
	pthread_mutex_lock(&gmutex);

	if (initindicator == NOT_INITIALIZED)
	{
		init();
		initindicator = INITIALIZED;
	}
	pthread_mutex_unlock(&gmutex);

	/* find a free block */
	for(lindex = 0; lindex< MAX_BLOCKS; lindex++)
	{
		pthread_mutex_lock(&gmutex);
		if(FREE == memory_block_arr[lindex].status)
		{
			memory_block_arr[lindex].status = BUSY;
			pthread_mutex_unlock(&gmutex);
			return((char *)&memory_block_arr[lindex].data);
		}
		else
		{
			/*all the blocks have been allocated, could not 
			find any free block*/
			if(lindex == (MAX_BLOCKS - 1))
			{
				pthread_mutex_unlock(&gmutex);
				return(NULL); 
			}
		}
		pthread_mutex_unlock(&gmutex);
	}

}

void myfree(char * address)
{
	int lindex;
	/* find the block by a linear search which has been free'd by the user and mark that free */
	for(lindex = 0; lindex< MAX_BLOCKS; lindex++)
	{
		pthread_mutex_lock(&gmutex);
		if(address == (char *)&memory_block_arr[lindex].data)
			memory_block_arr[lindex].status = FREE;
		pthread_mutex_unlock(&gmutex);
	}
}
