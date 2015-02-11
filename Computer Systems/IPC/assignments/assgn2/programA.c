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
char *str="connect by program A";
int readbytes=0;
int buffsize=32;
int counter=0;
char *tstr="terminate by program A";
char readbuffer2[32];
int readbytes2=0;
char *astr="ack";
char lastbuffer[4];

memset(writebuffer,'\0',buffsize);
memset(readbuffer,'\0',buffsize);
memset(filename,'\0',30);
memset(readbuffer2,'\0',buffsize);
memset(lastbuffer,'\0',4);

//Create fifo1 in write mode by program1 assign some area in kernel which is accessible by
//both programA and programB
retval=mkfifo("fifo1",S_IRWXU);
	if(-1==retval)
	{
	printf("FIFO 1 creation error\n");
		if(EEXIST==errno)
		{
		printf("FIFO 1 already exists\n"); 
		}
		else
		exit(1);
	}

//Create fifo2 in read mode by program2
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


printf("Enter the filename to send to ProgramB\n");
readbytes=read(0,filename,10);  //read from stdin
if(filename[strlen(filename)-1]=='\n')
filename[strlen(filename)-1]='\0';
//scanf("%s",filename);
//while(getchar()!='\n');
/*
if(readbytes<=0)
{
printf("Error in reading filename\n");
exit(1);
}
*/
//Open fifo1 in write only mode
fd1=open("fifo1",O_WRONLY);
if(-1==fd1)
{
printf("Error in opening fifo1 in write mode\n");
perror("fd1");
exit(1);
}

//Write 'connect' string in fifo1 for programB
write(fd1,str,strlen(str));

//Open fifo2 in read only mode
fd2=open("fifo2",O_RDONLY);
if(-1==fd2)
{
printf("Error in opening fifo2 in read mode\n");
perror("fd2");
exit(1);
}

//Block on read till get connection established on fifo2
//read the contents on fifo2
while(1)
{
readbytes=read(fd2,readbuffer,buffsize);
if(readbuffer>0)
if(strncmp(readbuffer,"Connection established",22)==0)
{
//printf("ProgramA has read :-\n");
write(1,readbuffer,strlen(readbuffer));  //write on stdout
}
memset(readbuffer,'\0',buffsize);
break;
}
printf("\n");

fd3=open(filename,O_RDONLY);   //open the input file from user

if(fd3<0)
{
printf("Input file cannot be opened\n");
exit(1);
}
memset(filename,'\0',10);
//Read the contents of the input file and write  the contents on fifo1
while(1)
{
readbytes=read(fd3,readbuffer,buffsize);

//If the file given by user is read completely then write terminate string on fifo1 and
//read ack on fifo2 then break from loop and terminate
if(readbytes==0)
{
write(fd1,tstr,strlen(tstr));
//memset(readbuffer,'\0',buffsize);
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

/*read(fd2,readbuffer,buffsize);

if(strncmp(readbuffer,"ack",3)==0)
//{
printf("Recieved ack from ProgramB now terminating\n");
//exit(0);*/
break;

}
//printf("ProgramA has read :-\n");
//write(1,readbuffer,strlen(readbuffer));

else
{
//Write the contents of the input file by user on fifo1 for pgm2 to read
write(fd1,readbuffer,strlen(readbuffer));  //write on fifo1

//Read the contents of the file send by pgm2 on fifo2
readbytes2=read(fd2,readbuffer2,buffsize);  //read on fifo2
if(readbytes2>0)
{
write(1,readbuffer2,strlen(readbuffer2));  //write contents of file send by pgm2 on stdout

//If while reading the contents of file by pgm2 we recieve terminate then send ack to pgm2 and break from loop
if(strncmp(readbuffer2,"terminate by program B",22)==0)
{
printf("\nSending ack to pgm2 on fifo1\n");
write(fd1,astr,strlen(astr));
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
