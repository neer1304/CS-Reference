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
int fd3;  //for input file from use[6~
char writebuffer[32];
char readbuffer[32];
char filename[10];
int readbytes=0;
int buffsize=32;
int counter=0;
int wret;

memset(writebuffer,'\0',buffsize);
memset(readbuffer,'\0',buffsize);
memset(filename,'\0',30);


//Open fifo1 in read only mode
fd1=open("fifo1",O_RDONLY);
if(-1==fd1)
{
printf("Error in opening fifo1 in read mode\n");
perror("fd1");
exit(1);
}

//Read the filename  send by ProgramA
readbytes=read(fd1,readbuffer,buffsize);

//write "connect" on stdout
if(readbytes>0)
{
fd3=open(readbuffer,O_RDONLY);   //open the input file from user

if(fd3<0)
{
printf("Input file cannot be opened\n");
exit(1);
}
}

printf("\n");

memset(readbuffer,'\0',buffsize);

//Open fifo2 in write only mode
fd2=open("fifo2",O_WRONLY);
if(-1==fd2)
{
printf("Error in opening fifo2 in write mode\n");
perror("fd2");
exit(1);
}

//Read the contents of the input file and write  the contents on fifo2
while(1)
{
readbytes=read(fd3,readbuffer,buffsize);

//When my file reading has been completed then write terminate on fifo2 and read on fifo1 
//for ack when ack recvd then break from loop and terminate
if(readbytes==0)
{
break;
}
//printf("ProgramA has read :-\n");
//write(1,readbuffer,strlen(readbuffer));
else
{
//Write the contents of file given by user on fifo2 so that pgmA can read the contents on fifo2
write(fd2,readbuffer,strlen(readbuffer)); 
 
}
memset(readbuffer,'\0',buffsize);
}
close(fd1);
close(fd2);
close(fd3);
printf("\n");
return;
}
