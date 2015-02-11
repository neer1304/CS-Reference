#include"header.h"

int main(int argc,char *argv[])
{
struct sockaddr_in server_addr;

int sd;

int conret;

char readbuffer[MAX];

char writebuffer[MAX];

int rdret;

int wret;

if(argv[1]==NULL)
{
printf("Please enter server ip addres to connect\n");
exit(1);
}

if(argv[2]==NULL)
{
printf("Please enter server port number\n");
exit(1);
}

sd=socket(AF_INET,SOCK_STREAM,0);
if(-1==sd)
{
perror("socket");
exit(1);
}

memset(&server_addr,0,sizeof(server_addr));
server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(atoi(argv[2]));
server_addr.sin_addr.s_addr=inet_addr(argv[1]);

conret=connect(sd,(struct sockaddr*)&server_addr,sizeof(server_addr));
if(-1==conret)
{
perror("connect");
exit(1);
}
else
printf("Connected to server you can start sending messages\n");

while(1)
{
rdret=read(0,readbuffer,MAX);

if(rdret<=0)
{
rdret=read(sd,writebuffer,MAX);
if(rdret<=0)
break;
else
wret=write(1,writebuffer,MAX);
memset(writebuffer,0,MAX);
}
wret=write(sd,readbuffer,rdret);
memset(readbuffer,0,MAX);
}
}
