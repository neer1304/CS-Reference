#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
int fd1,fd2,rwt;
char *buf1="open system call",*buf2="write system call";
fd1=open("file1",O_CREAT|O_RDWR,S_IRWXU);
if(fd1<0)
{
printf("File1 could not be opened\n");
perror("File open failed");
}

fd2=open("file2",O_CREAT|O_RDWR,S_IRWXU);
if(fd2<0)
{
printf("File2 could not be opened\n");
perror("File open failed");
}
rwt=write(fd1,buf1,strlen(buf1));
if(0==rwt)
{
printf("write failed for file1\n");
}

rwt=write(fd2,buf2,strlen(buf2));
if(0==rwt)
{
printf("write failed for file2\n");
}
close(fd1);
close(fd2);

return 0;
}
