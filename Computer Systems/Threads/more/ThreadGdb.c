/***************************************************************************
*	FILENAME : thread.c
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of pthread calls
*	Invoke the Executable as a.out
****************************************************************************/
#include<pthread.h>
#include<sys/types.h>
void printids(const char * s);
void * th_f(void *arg);
int main(void)
{
	pthread_t ntid; /*Thread Identifier*/
	int status;
	/*Creating a thread*/
	status=pthread_create(&ntid,NULL,th_f,NULL);
	if (status != 0)
	{
		printf("Error in Creating Thread\n");
		exit(status);
	}
	printids("Main thread:");
//	pthread_join(ntid,NULL);
	pthread_exit(NULL);	

}
/********************************************************************
*	FUNCTION NAME:printids
*	DESCRIPTION:Prints the  information of a Thread
*	NOTES : No Error Checking is done .
*	RETURNS :void 
*********************************************************************/
void printids(const char * s)
{
	pid_t pid;
	pthread_t tid;
	pid=getpid();/*Getting the Process Id*/
	tid=pthread_self();/*Getting the Thread Identifier*/
	printf("%s pid %u tid %u\n",s,pid,tid);

}
/********************************************************************
*	FUNCTION NAME:th_f
*	DESCRIPTION:A Thread Entry Point.
*	NOTES : No Error Checking is done .
*	RETURNS :void *
*********************************************************************/
void * th_f(void *arg)
{
	printids("New thread: ");
}


















