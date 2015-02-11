#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int fd[2];
	char buff[20];
	char rdbuff[20];
	int readbytes=0;
	int wret;

	pid_t pid;

	pipe(fd);

	pid=fork();

	  if(0==pid)
	  {
	   //Child reads from pipe
	    close(fd[1]); //close the writing end
	     while(readbytes=read(fd[0],rdbuff,sizeof(rdbuff))>0)
	     {
		printf("Child recieved string:- %s\n",rdbuff);
		if(strncmp(rdbuff,"quit",4)==0)
		{
		printf("Child recieved 'exit' read end exiting\n");
		close(fd[0]);
		}
		  memset(rdbuff,0,20);
	     }
	   return 0;
	  }

	else
	{
	 //Parent writes in pipe
	close(fd[0]); //close the reading end
	printf("Enter the string or type 'quit' to quit\n");
	scanf("%s",buff);
		while(strncmp(buff,"quit",4)!=0)
		{
		 wret=write(fd[1],buff,strlen(buff));
 
		   if(0==wret)
		   {
		    printf("write failed exiting..\n");
		    exit(1);
	           }
		 memset(buff,0,20);
		 sleep(1);
		 printf("Enter the string or type 'quit' to quit\n");
		 scanf("%s",buff);
		}
	

	 wret=write(fd[1],buff,strlen(buff));
	printf("Parent exiting..\n");
	close(fd[1]);
	wait(NULL);
	return;
}

}
