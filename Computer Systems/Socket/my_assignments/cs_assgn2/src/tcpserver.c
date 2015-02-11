#include"header.h"

#define MYPORT 3412

//char** readstring(int connectionsocket,char *string[]);
void readstring(int connectionsocket,snode *top);
//void sendstring(int sd,char *string);
void sendstring(int sd,snode *top);

void signal_term()
{
//close(connectionsocket);
//close(listensocket);
exit(0);
}

void signal_stp()
{
exit(0);
}

int main()
{
snode *top=NULL;
int listensocket,connectionsocket;
signal(SIGINT,signal_term);
signal(SIGTSTP,signal_stp);

struct sockaddr_in serveradd,clientadd;
char buf[100];
int binderror;
char **cstr;
socklen_t len;

char databuf[1024];
char *strbuf[80];

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

int opt=1;
setsockopt(listensocket,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

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
		//cstr=
		readstring(connectionsocket,top);
		sleep(1);
		//sendstring(connectionsocket,top);
		close(connectionsocket);
		printf("Finished serving one client\n");
	}
close(listensocket);	
}

/*
char** readstring(int connectionsocket,char *string[])
{
int pointer=0,n;

while((n=read(connectionsocket,*string+pointer,60))>0)
{
pointer =pointer+1;
}
//string[pointer]='\0';
//string[pointer+1]=" ";
printf("Server:received %s\n",*string);
return string;
}

*/
/*
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
printf("String %s sent to client\n",buffer);
}
*/

void readstring(int connectionsocket,snode *top)
{
int n;
char c;
char str[60];
int i=0;

memset(str,'\0',60);
//c=malloc(sizeof(char));
printf("Server received\n");
while((n=read(connectionsocket,&c,1)>0))
{
//memset(str,'\0',60);
if(c!=' ')
{
str[i]=c;
//push(&top,c);
i++;

//printf("%c",c);
}
else
{
//printf("in else part of read loop\n");
str[i+1]=c;
printf("%c",str[i+1]);
//str[i+2]=' ';
push(&top,str);
printf("%s",str);
memset(str,'\0',60);
i=0;
//push(&top,' ');
}
}
sendstring(connectionsocket,top);
}


void sendstring(int connectionsocket,snode *top)
{
char *c;
printf("\nSending to client\n");
while(top!=NULL)
{
//c=malloc(strlen(top->str));
//printf("In while loop of send string\n");
//strcpy(c,pop(&top));
c=pop(&top);
printf("%s\n",c);
//write(connectionsocket,&c,1);
write(connectionsocket,c,strlen(c));
write(connectionsocket," ",1);
//top=top->next;
//free(c);
//c=NULL;
}

}
