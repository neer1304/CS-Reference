#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/stat.h>


int main(int argc,char *argv[])
{
int fd[2];

pid_t pid;

int file1,file2;

char readbuffer[30];
char writebuffer[30];


int rdret;
int wret;

if(argv[1]==NULL)
{
printf("Please enter input file\n");
exit(1);
}

if(argv[2]==NULL)
{
printf("Please enter output file\n");
exit(1);
}
pipe(fd);
pid =fork();

if(pid==0)
{
printf("Child\n");
close(fd[1]); //close the write end
file2=open(argv[2],O_CREAT|O_WRONLY,S_IRWXU);
if(file2<0)
{
perror("file2");
exit(1);
}
while((rdret=read(fd[0],readbuffer,30))>0)
{
if(rdret>0)
write(file2,readbuffer,rdret);
else
break;
memset(readbuffer,0,30);
}
close(fd[0]);
}

else
{
printf("Parent\n");
close(fd[0]);  //close the read end
file1=open(argv[1],O_RDONLY);
if(file1<0)
{
perror("file1 open failed");
exit(1); 
}
while((rdret=read(file1,readbuffer,30))>0)
{
wret=write(fd[1],readbuffer,rdret);
if(wret<=0)
break;
memset(readbuffer,0,30);
}
close(fd[1]);
printf("Child terminated status %d\n",wait(NULL));
}

}
