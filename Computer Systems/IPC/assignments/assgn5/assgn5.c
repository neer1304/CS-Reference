#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


//ls -al|sort

int main()
{
	int fd[2];
        char readbuffer[800];
        int bufflen=800;
	pid_t pid;
        int fd3;
 	pipe(fd);
        
	pid=fork();
        int ret=0;

	  if(0==pid)
	  {
	   //Child writes into pipe
	    close(fd[0]); //close the reading end
            close(1);   //close standard o/p
	    dup2(fd[1],1); //duplicate fd[1] as standard o/p 
           ret= execlp("ls","ls","-l",(char*)NULL);
           if(-1==ret)
 	   printf("exec failed\n");               
	  }

	else
	{
         memset(readbuffer,'\0',bufflen);
	 //Parent reads from pipe
	close(fd[1]); //close the writing end
      //  execl("ls","-l");
        read(fd[0],readbuffer,bufflen-1);
        //printf("%s",readbuffer);     
          readbuffer[bufflen-1]='\0';
         fd3=open("lsOp",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
	write(fd3,readbuffer,strlen(readbuffer));
        ret=execlp("sort","sort","lsOp",(char*)NULL);
        if(-1==ret)
	printf("exec failed in parent\n");
	wait(NULL);
        }

}
