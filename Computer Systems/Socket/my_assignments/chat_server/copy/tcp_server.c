#include"header.h"

#define MYPORT 34125

void sig_handler1(int code)
{
exit(0);
}

void sig_handler2(int code)
{
exit(0);
}

int main()
{
signal(SIGINT,sig_handler1);
signal(SIGTSTP,sig_handler2);

struct sockaddr_in my_addr,client_addr;

int listensocket;

int new_socket;

int retbind;

socklen_t len;

char readbuffer[MAX];

char writebuffer[MAX];

int rdret;

int wret;

listensocket=socket(AF_INET,SOCK_STREAM,0);
if(-1==listensocket)
{
perror("socket");
exit(1);
}

memset(&my_addr,0,sizeof(my_addr));
my_addr.sin_family=AF_INET;
my_addr.sin_port=htons(MYPORT);
my_addr.sin_addr.s_addr=htonl(INADDR_ANY);

retbind=bind(listensocket,(struct sockaddr*)&my_addr,sizeof(my_addr));
if(-1==retbind)
{
perror("bind");
exit(1);
}

listen(listensocket,1);

while(1)
{
len=sizeof(client_addr);

new_socket=accept(listensocket,(struct sockaddr*)&client_addr,&len);
if(-1==new_socket)
{
perror("accept");
exit(1);
}
printf("Connected to client %s\n",inet_ntoa(client_addr.sin_addr));

rd:
printf("Message from Client\n");
rdret=read(new_socket,readbuffer,MAX);
wret=write(1,readbuffer,rdret);
memset(readbuffer,0,MAX);

if(rdret<=0)
{
printf("Reply to Client\n");
rdret=read(0,writebuffer,MAX);
wret=write(new_socket,writebuffer,MAX);
memset(writebuffer,0,MAX);
}
else
goto rd;
}
}
