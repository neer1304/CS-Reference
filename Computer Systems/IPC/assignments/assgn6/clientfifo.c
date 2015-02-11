#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main()
{
int fd1;
int wret;
char readbuffer[32];
int buffsize=32;
int readbytes=0;

memset(readbuffer,'\0',buffsize);
//open the fifo in client in write mode only
fd1=open("fifo1",O_WRONLY);
if(-1==fd1)
{
  printf("Error in opening fifo1 in write only mode in client\n");
  perror("fd1");
  exit(1);
}

printf("Enter the text to send to the server -\n");

while(1)
{
readbytes=read(1,readbuffer,buffsize);
readbuffer[buffsize-1]='\0';
if(readbytes>0)
{
wret=write(fd1,readbuffer,strlen(readbuffer));
if(-1==wret)
{
printf("Write failed exiting..\n");
exit(1);
}

//if(strncmp(readbuffer,"bye",3)==0)
//break;
if(strstr(readbuffer,"bye"))
break;
memset(readbuffer,'\0',buffsize);
}
else
break;
}
close(fd1);
}


