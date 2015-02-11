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
int readbytes=0;
int buffsize=32;
char *str="Connection established";
int wret;
int readbytes2=0;
char readbuffer2[32];
char *astr="ack";
char lastbuffer[4];

memset(writebuffer,'\0',buffsize);
memset(readbuffer,'\0',buffsize);
memset(readbuffer2,'\0',buffsize);
memset(lastbuffer,'\0',4);

//Create  fifo1 in read only mode in ProgramB
retval=mkfifo("fifo1",S_IRWXU);
if(-1==retval)
{
printf("Error in creating fifo1\n");
if(errno==EEXIST)
printf("FIFO1 already exists\n");
else
exit(1);
}

fd1=open("fifo1",O_RDONLY);
if(-1==fd1)
{
printf("Error in opening fifo1 in read mode\n");
perror("fd1");
//exit(1);
}

//Read the "connect" string send by ProgramA
readbytes=read(fd1,readbuffer,7);

//write "connect" on stdout
if(readbytes>0)
{
write(1,readbuffer,strlen(readbuffer));
}
memset(readbuffer,0,buffsize);

readbytes=read(fd1,readbuffer,5);

//if(readbuffer[strlen(readbuffer)-1]=='\n')
//readbuffer[strlen(readbuffer)-1]='\0';


//Open fifo2 in write only mode
fd2=open(readbuffer,O_WRONLY);
if(-1==fd2)
{
printf("Error in opening fifo2 in write mode\n");
perror("fd2");
exit(1);
}


printf("\n");

memset(readbuffer,'\0',buffsize);


//write connection established on fifo2
wret=write(fd2,str,strlen(str));
if(-1==wret)
{
printf("Error in writing 'conn est'..\n");
exit(1);
}

//blocking here
readbytes2=read(fd1,readbuffer2,buffsize);  //read on fifo1
if(readbytes2>0)
{
write(1,readbuffer2,strlen(readbuffer2));

if(strncmp(readbuffer2,"terminate by program A",22)==0)
{
printf("\nSending ack to program A\n");
write(fd2,astr,strlen(astr));
//break;
}
}
memset(readbuffer,'\0',buffsize);
memset(readbuffer2,'\0',buffsize);
close(fd1);
close(fd2);
printf("\n");
return;
}
