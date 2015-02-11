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
void readstring(int connectionsocket,char *string);

int main(int argc,char *argv[])
{
int sd,fd;
int con_ret;
char rbuff[100];
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
printf("Please enter the string1 to be send to the server\n");
exit(0);
}

if(argv[4]==NULL)
{
printf("Please enter string2 to be send to the server\n");
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
sendstring(sd,argv[4]);
shutdown(sd,1);
readstring(sd,rbuff);
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

void readstring(int connectionsocket,char *string)
{
int pointer=0,n;

while((n=read(connectionsocket,(string+pointer),1024))>0)
{
pointer =pointer+n;
}
string[pointer]='\0';
printf("Client:received %s\n",string);
}

