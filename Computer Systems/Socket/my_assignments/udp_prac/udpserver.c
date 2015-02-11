#include"header.h"
#define MYPORT 34125

int main()
{
struct sockaddr_in my_addr,client_addr;
int listensocket;
int yes=1;
int ret;
int rcvd;
char buffer[100];
//memset(buffer,'\0',1024);
int len;

listensocket=socket(AF_INET,SOCK_DGRAM,0);
if(listensocket<0)
{
perror("socket");
exit(1);
}

if((ret=setsockopt(listensocket,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)))<0)
{
perror("setsockopt");
exit(1);
}

memset(&my_addr,0,sizeof(my_addr));

my_addr.sin_family=AF_INET;
my_addr.sin_port=htons(MYPORT);
my_addr.sin_addr.s_addr=htonl(INADDR_ANY);

ret=bind(listensocket,(struct sockaddr*)&my_addr,sizeof(my_addr));
if(ret<0)
{
perror("bind");
exit(1);
}

//while(1)
//{
printf("Server recvd\n");
len=sizeof(client_addr);
rcvd=recvfrom(listensocket,buffer,sizeof(buffer),0,(struct sockaddr*)&client_addr,&len);
if(rcvd<=0)
{
printf("read failed\n");
exit(1);
}
printf("Server recvd %s\n",buffer);
//}
close(listensocket);
}
