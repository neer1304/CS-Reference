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
int retval=0;
char readbuffer[32];
int readbytes=0;
int buffsize=32;

memset(readbuffer,'\0',buffsize);

retval=mkfifo("fifo1",S_IRWXU);

if(-1==retval)
{
  printf("Error in creating fifo in the server\n");
  if(errno==EEXIST)
  printf("FIFO1 already exist\n");
  else
  exit(1);
}

fd1=open("fifo1",O_RDONLY);

if(-1==fd1)
{
printf("Error in opening fifo1 in read only mode in server\n");
perror("fd1");
exit(1);
}

printf("Data recieved from the client -\n");

while(1)
{
readbytes=read(fd1,readbuffer,buffsize);
if(readbytes>0)
write(1,readbuffer,strlen(readbuffer));
if(strstr(readbuffer,"bye"))
break;
else
{
memset(readbuffer,'\0',buffsize);
continue;
}
}

close(fd1);
return;
}
