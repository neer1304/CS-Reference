#include<stdio.h>
#include<string.h>

#define FREE 0
#define BUSY 1
#define NOT_INITIALIZED 0
#define INITIALIZED 	1

#define MAX_BLOCKS 	2
#define MAX_USER_BLOCK	8

typedef struct block_info
{
	unsigned char status; /* block is free or used */
	char data[MAX_USER_BLOCK];

}Block_Info;

static int initindicator = NOT_INITIALIZED;

static Block_Info memory_block_arr[MAX_BLOCKS];


static void init()
{
	memset(memory_block_arr, 0, MAX_BLOCKS*sizeof(Block_Info));
}

char * mymalloc(int size)
{
#ifdef  STD_LIB_IMPL
	return ((char*)malloc(size));
	
#else
	int lindex;

	if(size > MAX_USER_BLOCK)
	{
		return (NULL);
	}

	if (NOT_INITIALIZED == initindicator)
	{
		init();
		initindicator = INITIALIZED;
	}

	/* find a free block */
	for(lindex = 0; lindex < MAX_BLOCKS; lindex++)
	{
		if(FREE == memory_block_arr[lindex].status)
		{
			memory_block_arr[lindex].status = BUSY;
			return((char *)&memory_block_arr[lindex].data);
		}
		else
		{
			/*all the blocks have been allocated, could not 
			find any free block*/
			if((MAX_BLOCKS - 1) == lindex)
				return(NULL); 
		}
	}

#endif
}

void myfree(char * address)
{

#ifdef  STD_LIB_IMPL
	free(address);

#else
	int lindex;
	/* find the block by a linear search which has been free'd by the user and mark that free */
	for(lindex = 0; lindex< MAX_BLOCKS; lindex++)
	{
		if(address == (char *)&memory_block_arr[lindex].data)
			memory_block_arr[lindex].status = FREE;
	}
#endif
}
