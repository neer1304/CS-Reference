#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
int fd1,fd2,rwt,lsrt;
char buf1[50],buf2[50];
fd1=open("file1",O_RDWR,S_IRWXU);
if(fd1<0)
{
printf("File1 could not be opened\n");
perror("File open failed");
}

fd2=open("file2",O_RDWR,S_IRWXU);
if(fd2<0)
{
printf("File2 could not be opened\n");
perror("File open failed");
}

printf("Enter the string for file 1\n");
fgets(buf1,30,stdin);

if(buf1[strlen(buf1)-1]=='\n')
buf1[strlen(buf1)-1]='\0';

printf("Enter the string for file 2\n");
fgets(buf2,30,stdin);

if(buf2[strlen(buf2)-1]=='\n')
buf2[strlen(buf2)-1]='\0';

lsrt=lseek(fd1,0,SEEK_END);
if((off_t)-1==lsrt)
{
printf("lseek failed for file1\n");
}
rwt=write(fd1,buf1,strlen(buf1));
if(0==rwt)
{
printf("write failed for file1\n");
}


lsrt=lseek(fd2,0,SEEK_END);
if((off_t)-1==lsrt)
{
printf("lseek failed for file2\n");
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
