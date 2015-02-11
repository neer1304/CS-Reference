#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
int fd1,rret,rsk;

fd1=open("input",O_RDONLY);
char buff[5];
if(fd1<0)
{
printf("Error in opening in input file\n");
perror("File opening error");
}
rsk=lseek(fd1,10,SEEK_SET);
printf("The value of current file offset is %d\n",rsk);

if((off_t)-1==rsk)
{
printf("lseek failed..\n");
}

while((rret=read(fd1,buff,5))>0)
{
//printf("Inside while loop\n");
printf("%s",buff);
}
//printf("Outside while loop\n");
close(fd1);
return 0;
}
