#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define MYPORT 3412

void readstring(int connectionsocket,char *string);

int main()
{
int listensocket,connectionsocket;

struct sockaddr_in serveradd,clientadd;

int binderror;

socklen_t len;

char buf[100];
char databuf[1024];

memset(buf,0,100);
memset(databuf,0,1024);

//Step-1 create a socket for tcp,ipv4 conn
listensocket=socket(AF_INET,SOCK_STREAM,0); //0 for tcp and first parameter for Ipv4
if(listensocket<0)
{
perror("socket");
exit(1);
}

memset(&serveradd,0,sizeof(serveradd));

serveradd.sin_family=AF_INET;

serveradd.sin_port=htons(MYPORT);

serveradd.sin_addr.s_addr=htonl(INADDR_ANY);

//Step2- bind the socket(gives socket the local address)
binderror=bind(listensocket,(struct sockaddr*)&serveradd,sizeof(serveradd));
if(-1==binderror)
{
perror("BIND");
exit(1);
}

//Step-3 listen for conn from client
listen(listensocket,2);

//Main loop of the server
	while(1)
	{
	printf("Server:Waiting for the client connection.Start of main loop\n");

	len=sizeof(clientadd);
        //Step-4 accept the conn on socket
	connectionsocket=accept(listensocket,(struct sockaddr*)&clientadd,&len);
		if(connectionsocket<0)
		{
			if(errno==EINTR)
			{
			printf("Interrupted system call\n");
			continue;
			}
                }
		printf("Connection from %s\n",inet_ntop(AF_INET,&clientadd.sin_addr,buf,sizeof(buf)));
		//addfamily,*src,*dest,cnt
		readstring(connectionsocket,databuf);
		close(connectionsocket);
		printf("Finished serving one client\n");
	}
close(listensocket);	
}

void readstring(int connectionsocket,char *string)
{
int pointer=0,n;

while((n=read(connectionsocket,(string+pointer),1024))>0)
{
pointer =pointer+n;
}
string[pointer]='\0';
printf("Server:received %s\n",string);
}
