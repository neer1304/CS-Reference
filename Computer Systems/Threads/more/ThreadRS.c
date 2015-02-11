/***********************************************************************
*	FILENAME : thread.c
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of pthread calls
*	Invoke the Executable as a.out
*********************************************************************/
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#define MAX_LINE_SIZE  120
void * th_f(void *arg);
char * read_line(int fd);
char * process_line(char *src);
pthread_mutex_t mymutex =  PTHREAD_MUTEX_INITIALIZER;
int main(int argc, char *argv[])
{
	pthread_t ntid; /*Thread Identifier*/
	int status;
	int fd;
	fd = open (argv[1] , O_RDONLY);
	if ( 0 > fd )
	{
		//Need not proceed;
		perror("File opening Failed\n");
		exit(1);
	}
	/*Creating a thread*/

	status=pthread_create(&ntid,NULL,th_f,(void *)fd);

	if (status != 0)
	{
		printf("Error in Creating Thread\n");
		exit(status);
	}
	th_f(fd);

}
/********************************************************************
*	FUNCTION NAME:th_f
*	DESCRIPTION:A Thread Entry Point.
*	NOTES : No Error Checking is done .
*	RETURNS :void *
*********************************************************************/
void * th_f(void *arg)
{
	char * lptr;
	while (1)
	{
		pthread_mutex_lock(&mymutex);
		lptr = read_line ( (int)arg);
		pthread_mutex_unlock(&mymutex);
		if (NULL == lptr)
		{
			//Nothing more to read;
			pthread_exit(NULL);
		}
		
		printf("%u %s\n",pthread_self(), process_line(lptr));
		write(1, lptr, strlen(lptr));
		free(lptr);
		//pthread_mutex_unlock(&mymutex);
	}
		
}
/********************************************************************
	Description of the Function

********************************************************************/
char * read_line(int fd)
{	
	//static char buffer[MAX_LINE_SIZE];
	char *buffer;
	int ret, index=0;
	buffer = (char *)malloc(MAX_LINE_SIZE);
	if (NULL == buffer)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	memset( buffer, '\0', MAX_LINE_SIZE);
	while((ret=read(fd, buffer + index, 1))>0)
	{
		if ('\n' == *(buffer + index))
		{
			index++;
			*(buffer + index) = '\0';
			return buffer;	
		}
		index ++;
	}
	
	//Now read is returning 0 or -ve 
	return NULL;
	
}

/********************************************************************
	Description of the Function

********************************************************************/
char * process_line(char *src)
{	
	int index;
	for (index = 0; src[index]; index++)
		src[index] = toupper(src[index]);
		src[index] = 0;

	return src;
}
















