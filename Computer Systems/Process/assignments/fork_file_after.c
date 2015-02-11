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
int fd,readbytes,wret;
char buf[20];
memset(buf,0,20);
char *buf1="I am from child process i have written in input file";
char *buf2="I am from parent process";
	
	pid=fork();
        
	fd=open("input",O_RDWR,S_IRWXU);

	if(fd<0)
	{
	 printf("File open failed\n");
	 perror("File error");
	}


	if(0==pid)
	{
	printf("Child process\n");
	wret=write(fd,buf1,strlen(buf1));
        printf("In child process write returns %d\n",wret);
        close(fd);
	exit(0);
	}
	else
	{
	wait(NULL);
	//bring the file pointer to the end since parent will open the file again 
	lseek(fd,0,SEEK_END);
	printf("Parent process\n");
        //Parent overwrites the contents of the child
	wret = write(fd,buf2,strlen(buf2));
        printf("In parent process write returns %d\n",wret);
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
