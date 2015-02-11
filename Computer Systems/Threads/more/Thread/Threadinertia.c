/***************************************************************************
*	FILENAME : thread.c
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of pthread calls
*	Invoke the Executable as a.out
****************************************************************************/
#include<pthread.h>
#include<sys/types.h>
void printids(const char * s);
void  *printer_thread(void *arg);
int main(void)
{
	pthread_t ntid; /*Thread Identifier*/
	int status, i;
	char *string_ptr;
	string_ptr = "Before Value";
	/*Creating a thread*/
	status=pthread_create(&ntid,NULL, printer_thread,(void*)&string_ptr);
	if (status != 0)	
	{
		printf("Error in Creating Thread\n");
		exit(status);
	}
	//Trying to give the Thread a Chance to run
	//Use either of the Loops, below? Is there a difference in O/P?
	//for (i=0; i <1000000; i++);
	//for (i=0; i <50000; i++);
	
	string_ptr = "After value";
	status = pthread_join(ntid, NULL);
	if (status != 0)	
	{
		printf("Error in joining Thread\n");
		exit(status);
	
	}
	exit(0);
	
}
/********************************************************************
*	FUNCTION NAME:printer_thread
*	DESCRIPTION:A Thread Entry Point.
*	NOTES : No Error Checking is done .
*	RETURNS :void *
*********************************************************************/
void *printer_thread(void * arg)
{
	char *string = *((char **) arg);
	printf("%s\n", string);
	return(NULL);
}
