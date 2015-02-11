#include<stdio.h>
#include<error.h>
#include"mem_lib.h"

int main()
{
	/* test my malloc and my free */
	char *block;
	char *block1;

	block = mymalloc(100);
	block1 = mymalloc(100);
	block1 = mymalloc(100);
	block = mymalloc(100);

	myfree(block);

	if(NULL == block)
	{
		printf("memory not allocated by mymalloc");
	}
	else
	{
		sprintf(block,"ABCDE");
		printf("block is %s\n",block);
	}
	
	block1 = mymalloc(100);
	if(NULL == block1)
		printf("memory not allocated by mymalloc");
	else
	{
		sprintf(block1,"12345");
		printf("block1 is %s\n",block1);
	}
	block = mymalloc(100);
	if(NULL == block)
	{
		printf("memory not allocated by mymalloc");
	}
	else
	{
		sprintf(block,"zxy");
		printf("block is %s\n",block);
	}

	myfree(block1);
	myfree(block);

	return 1;
}

