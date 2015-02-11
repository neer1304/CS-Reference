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
char *tstr="terminate by program B";
char *str="Connection established";
int wret;
int readbytes2=0;
char readbuffer2[32];
char *astr="ack";
char lastbuffer[4];
int flag=1;
int readbytes1=0;
char ch;

memset(writebuffer,'\0',buffsize);
memset(readbuffer,'\0',buffsize);
memset(filename,'\0',30);
memset(readbuffer2,'\0',buffsize);
memset(lastbuffer,'\0',4);

printf("Enter the filename to send to ProgramA\n");
read(0,filename,10);  //read from stdin
//scanf("%s",filename);
if(filename[strlen(filename)-1]=='\n')
filename[strlen(filename)-1]='\0';

//Open fifo1 in read only mode
fd1=open("fifo1",O_RDONLY);
if(-1==fd1)
{
printf("Error in opening fifo1 in read mode\n");
perror("fd1");
exit(1);
}

//Read the "connect" string send by ProgramA
readbytes=read(fd1,readbuffer,buffsize);

//write "connect" on stdout
if(readbytes>0)
{
write(1,readbuffer,strlen(readbuffer));
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

//write connection established on fifo2
wret=write(fd2,str,strlen(str));
if(-1==wret)
{
printf("Error in writing 'conn est'..\n");
exit(1);
}

fd3=open(filename,O_RDONLY);   //open the input file from user

if(fd3<0)
{
printf("Input file cannot be opened\n");
exit(1);
}
memset(filename,'\0',10);

//Read the contents of the input file and write  the contents on fifo2
while(1)
{
readbytes=read(fd3,readbuffer,buffsize);

//When my file reading has been completed then write terminate on fifo2 and read on fifo1 
//for ack when ack recvd then break from loop and terminate
if(readbytes==0)
{

//empty the fifo1 which contains the bigger file contents to read ack send by program1
//while(read(fd1,lastbuffer,4)!=0); //empty fd1
write(fd2,tstr,strlen(tstr));
while(read(fd1,lastbuffer,4)>0)
{
if(strncmp(lastbuffer,"ack",3)==0)
{
memset(lastbuffer,'\0',4);
printf("\nRecieved ack from ProgramA now terminating\n");
//exit(0);
break;
}
else
continue;
}
//while(readbytes=(read(fd1,lastbuffer,buffsize))!=0); //it will not be ack but will be file contents which is left over
/*if(strncmp(lastbuffer,"ack",3)!=0)
{
memset(lastbuffer,'\0',4);
//read(fd1,lastbuffer,4);
printf("\nRecieved ack from ProgramA now terminating\n");
*/
break;
} 

else
{
//Write the contents of file given by user on fifo2 so that pgmA can read the contents on fifo2
write(fd2,readbuffer,strlen(readbuffer)); 
 
//Read the contents of file send by  programA on fifo1
readbytes2=read(fd1,readbuffer2,buffsize);  //read on fifo1
if(readbytes2>0)
{
write(1,readbuffer2,strlen(readbuffer2));  //write contents of file send by pgm1 on stdout
//If while reading the contents of file by pgmA terminate is encountered then write ack on the
//fifo2 so that pgmA can terminate
if(strncmp(readbuffer2,"terminate by program A",22)==0)
{
printf("\nSending ack to program A\n");
write(fd2,astr,strlen(astr));
//break;
}
}
memset(readbuffer,'\0',buffsize);
memset(readbuffer2,'\0',buffsize);
}
}
close(fd1);
close(fd2);
close(fd3);
printf("\n");
return;
}
