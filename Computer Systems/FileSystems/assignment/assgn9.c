#include<sys/types.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
int fd1,rlnk;
//fd1=open("input",O_RDONLY);
rlnk=link("input","input2");
if(-1==rlnk)
{
printf("link failed..\n");
}
else if(0==rlnk)
printf("Link is created\n");
//close(fd1);
return 0;
}
