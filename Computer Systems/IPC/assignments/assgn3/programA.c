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
char filename[10];
int readbytes=0;
int buffsize=32;


memset(writebuffer,'\0',buffsize);
memset(readbuffer,'\0',buffsize);
memset(filename,'\0',30);
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

//Write filename in fifo1 for programB
write(fd1,filename,strlen(filename));

//Open fifo2 in read only mode
fd2=open("fifo2",O_RDONLY);
if(-1==fd2)
{
printf("Error in opening fifo2 in read mode\n");
perror("fd2");
exit(1);
}

while(1)
{
readbytes=read(fd2,readbuffer,buffsize);

//If the file given by user is read completely then write terminate string on fifo1 and
//read ack on fifo2 then break from loop and terminate
if(readbytes==0)
{
break;
//}
}
//printf("ProgramA has read :-\n");
//write(1,readbuffer,strlen(readbuffer));

else
{
write(1,readbuffer,strlen(readbuffer));  //write contents of file send by pgm2 on stdout
//If while reading the contents of file by pgm2 we recieve terminate then send ack to pgm2 and break from loop
//break;
}
memset(readbuffer,'\0',buffsize);
}

close(fd1);
close(fd2);

printf("\n");
return;
}
