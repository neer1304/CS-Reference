#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

int main()
{
int fd1,fd2,bytesread;
char buf[10];
memset(buf,'\0',10);
fd1=open("input",O_RDONLY);
if(fd1<0)
{
printf("Error in opening f1\n");
perror("File open error");
}
fd2=open("f2",O_CREAT|O_RDWR,S_IRWXU);
if(fd2<0)
{
printf("Error in opening f1\n");
perror("File open error");
}
close(1);
dup(fd2);

while((bytesread=read(fd1,buf,9))>0)
{
buf[strlen(buf)+1]='\0';
printf("%s",buf);
}
close(fd1);
close(fd2);
return 0;
}
