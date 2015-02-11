#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>

int main()
{
int retval=0;
int fd1;  //for fifo1
int fd2;  //for fifo2
char writebuffer[32];
char readbuffer[32];
char *str="connectfifo2";
int readbytes=0;
int buffsize=32;
char *tstr="terminate by program A";
char readbuffer2[32];
char lastbuffer[4];


memset(writebuffer,'\0',buffsize);
memset(readbuffer,'\0',buffsize);
memset(readbuffer2,'\0',buffsize);
memset(lastbuffer,'\0',4);

//Create fifo2 
retval=mkfifo("fifo2",S_IRWXU);
	if(-1==retval)
	{
	printf("FIFO 2 creation error\n");
		if(EEXIST==errno)
		{
		printf("FIFO 2 already exists\n"); 
		}
		else
		exit(1);
	}


fd1=open("fifo1",O_WRONLY);
if(-1==fd1)
{
printf("Error in opening fifo1 in write mode\n");
perror("fd1");
exit(1);
}

//Write 'connect' string in fifo1 for programB
write(fd1,str,strlen(str));

fd2=open("fifo2",O_RDONLY);
if(-1==retval)
{
  printf("FIFO2 open error in read mode\n");
}

//Write new fifo name for the program B
//write(fd1,nfifo,strlen(nfifo));

//Block on read till get connection established on fifo2
//read the contents on fifo2


//while(1)
//{
readbytes=read(fd2,readbuffer,buffsize);
if(readbytes>0)
{
if(strncmp(readbuffer,"Connection established",22)==0)
{
//printf("ProgramA has read :-\n");
write(1,readbuffer,strlen(readbuffer));  //write on stdout
write(fd1,tstr,strlen(tstr));
}
memset(readbuffer,'\0',buffsize);
//break;
}
//}
printf("\n");


while(read(fd2,lastbuffer,4)>0)
{
if(strncmp(lastbuffer,"ack",3)==0)
{
memset(lastbuffer,'\0',4);
printf("\nRecieved ack from ProgramB now terminating\n");
//exit(0);
break;
}
else
continue;
}

close(fd1);
close(fd2);
printf("\n");
return;
}
