#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/wait.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
void sendstring(int sd,char *string);

int main(int argc,char *argv[])
{
int sd,fd;
int con_ret;

struct sockaddr_in serveradd;

sd=socket(AF_INET,SOCK_STREAM,0);
if(sd<0)
{
perror("socket");
exit(1);
}

if(argv[1]==NULL)
{
printf("Please enter server's IP address\n");
exit(0);
}

if(argv[2]==NULL)
{
printf("Please enter server's port\n");
exit(0);
}

if(argv[3]==NULL)
{
printf("Please enter the string to be send to the server\n");
exit(0);
}

memset(&serveradd,0,sizeof(serveradd));

serveradd.sin_family=AF_INET;
serveradd.sin_port=htons(atoi(argv[2]));
serveradd.sin_addr.s_addr=inet_addr(argv[1]);

con_ret=connect(sd,(struct sockaddr*)&serveradd,sizeof(serveradd));
if(con_ret<0)
{
printf("Cannot connect to server\n");
exit(1);
}
sendstring(sd,argv[3]);
return 0;
}

void sendstring(int sd,char *string)
{
int n,byteswritten=0,written;
char buffer[1024];
strcpy(buffer,string);
n=strlen(buffer);
while(byteswritten<n)
{
written=write(sd,buffer+byteswritten,(n-byteswritten));
byteswritten+=written;
}
printf("String %s sent to server\n",buffer);
}
