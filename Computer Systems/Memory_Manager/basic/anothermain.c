#include<stdio.h>
#include<error.h>
#include"mem_lib.h"

int main()
{
	/* test my malloc and my free */
	char *block;
	char *block1;

	block = mymalloc(8);

	if(NULL == block)
	{
		printf("memory not allocated by mymalloc 1st time\n");
	}
	else
	{
		block = block+8;
		*block = 1;
		sprintf(block,"xxxxx");
		printf("block is %s\n",block);
	}
	
	block1 = mymalloc(8);
	if(NULL == block1)
	{
		printf("memory not allocated by mymalloc 2nd time\n");
	}
	else
	{
		sprintf(block1,"12345");
		printf("block1 is %s\n",block1);
	}

	*block = 0;
	block1 = mymalloc(8);
	if(NULL == block1)
	{
		printf("memory not allocated by mymalloc 3rd time\n");
	}
	else
	{
		sprintf(block1,"12345");
		printf("block1 is %s\n",block1);
	}

	myfree(block1);
	myfree(block);

	return 1;
}
















