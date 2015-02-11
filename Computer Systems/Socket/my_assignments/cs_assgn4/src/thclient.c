#include "header.h"

int main(int argc,char *argv[])
{
struct sockaddr_in server_addr;
int csd;
int ret;
int fd;
char buffer[MAX];
char c;
int i;

memset(buffer,'\0',MAX);

if(argv[1]==NULL)
{
printf("Please enter the IP address\n");
exit(1);
}

if(argv[2]==NULL)
{
printf("Please enter the port no.\n");
exit(1);
}

if(argv[3]==NULL)
{
printf("Please enter the string to be sent\n");
exit(1);
}

csd=socket(AF_INET,SOCK_STREAM,0);
if(csd<0)
{
perror("csd");
exit(1);
}

memset(&server_addr,0,sizeof(server_addr));
server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(atoi(argv[2]));
server_addr.sin_addr.s_addr=inet_addr(argv[1]);

ret=connect(csd,(struct sockaddr*)&server_addr,sizeof(server_addr));

if(-1==ret)
{
perror("connect");
//printf("%s",errno);
exit(1);
}
i=0;

write(csd,argv[3],strlen(argv[3]));
shutdown(csd,SHUT_WR);
while(1)
{
if(i>MAX)
break;
ret=read(csd,&c,1);
if(ret<=0)
break;
buffer[i]=c;
i++;
}
//buffer[i+1]='\0';

fd=open("../bin/input",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
if(fd<0)
{
perror("file error");
exit(1);
}

ret=write(fd,buffer,strlen(buffer));
if(ret<=0)
{
perror("write failed\n");
exit(1);
}
close(csd);
return 0;
}


