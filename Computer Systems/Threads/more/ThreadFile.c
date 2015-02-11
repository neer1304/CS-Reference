#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int counter;
void *doit(void *);
int fd;
int main()
{
	char buf[10];
	pthread_t th1,th2;
	int ret;
	ret = pthread_create(&th1,NULL,doit,NULL);
	if (ret)
	{
		printf("Error in Creating Thread\n");
		exit(1);
	}

	ret=pthread_join(th1,NULL);
	if (ret)
	{
		printf("Error in Joining Thread\n");
		exit(1);
	}
	ret=read(fd,buf,2);
	if (-1 == ret)
	{
		printf("Main : Error in reading File\n");
		exit(1);
	}
	buf[ret]='\0';
	printf("Read By main %s\n",buf);
	printf("%d",counter);
	exit(0);
}
void * doit(void *ptr)
{
	int i,val;
	char buf[10];
	fd=open("sample",O_RDONLY);
	if (-1 == fd)
	{
		printf("Error in opening the File\n");
		pthread_exit(NULL);	
	}
	i=read(fd,buf,2);
	buf[i]='\0';
	printf("Read By thread %s\n",buf);
}

