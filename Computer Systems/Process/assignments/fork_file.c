#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
pid_t pid;
int fd,readbytes;
char buf[20];
memset(buf,0,20);
char *buf1="I am from child process";
char *buf2="I am from parent process";
fd=open("input",O_CREAT|O_RDWR|O_TRUNC,S_IRWXU);
	if(fd<0)
	{
	 printf("File open failed\n");
	 perror("File error");
	}

	pid=fork();

	if(0==pid)
	{
	printf("Child process\n");
	write(fd,buf1,strlen(buf1));
	exit(0);
	}
	else
	{
	wait(NULL);
	printf("Parent process\n");
	write(fd,buf2,strlen(buf2));
	lseek(fd,0,SEEK_SET);

	while(readbytes=read(fd,buf,10))
	{
	//printf("In read block\n");
	printf("%s",buf);
	memset(buf,0,20);
	}
	printf("\n");
	}

close(fd);
return 0;
}
