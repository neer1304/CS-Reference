/***************************************************************************
*	FILENAME : threadrace.c
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of modification of a global variable by multiple threads.
*	Invoke the Executable as a.out (Link with Linker option -lpthread)
****************************************************************************/
#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>

void *doit1(void *);
void *doit2(void *);
char *transform(char *);

int main()
{
	pthread_t th1,th2;/* th1 & th2 are Thread Identifiers */
	int status,i;
	/*Creating Thread1*/
	status=pthread_create(&th1,NULL,doit1,NULL);
	if ( status )
	{
		printf("Error in Creating Thread\n");
		exit(status);
	}
	/*Creating Thread2*/
	status=pthread_create(&th2,NULL,doit2,NULL);
	if ( status )
	{
		printf("Error in Creating Thread\n");
		exit(status);
	}
	for(i=0;i<500;i++)
		printf("%s\n", transform("111111111111111111"));
	pthread_exit(NULL);
}


/********************************************************************
*	FUNCTION NAME:doit
*	DESCRIPTION:Increments a global variable counter.
*	NOTES : No Error Checking is done .
*	RETURNS :void *
*********************************************************************/
char* transform (char *input)
{
	static char carray[20];
	int index = 0;
	int i;
	//strcpy(carray, input);
	while(*(input + index))
	{
		*(carray + index) = *(input + index);
		index++;
		//Just Spending Time Here
		for (i=0; i < 500000; i++);
	}
	*(carray + index) = *(input + index);
	
	return carray;
	
	
}
void * doit1(void *arg)
{
	int i;
	for(i=0;i<300;i++)
		printf("%s\n", transform("222222222222222222"));
}
void * doit2(void *arg)
{
	int i;
	for(i=0;i<200;i++)
		printf("%s\n", transform("333333333333333333"));
}


