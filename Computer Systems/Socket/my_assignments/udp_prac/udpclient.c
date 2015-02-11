#include"header.h"

int main(int argc,char *argv[])
{
int sd;
struct sockaddr_in server_addr;
int ret;

if(argv[1]==NULL)
{
printf(" server ip address is reqd\n");
exit(1);
}

if(argv[2]==NULL)
{
printf("server's port no is reqd\n");
exit(1);
}

if(argv[3]==NULL)
{
printf("string to send to server\n");
exit(1);
}

sd=socket(AF_INET,SOCK_DGRAM,0);
if(sd<0)
{
perror("socket");
exit(1);
}

memset(&server_addr,0,sizeof(server_addr));

server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(atoi(argv[2]));
server_addr.sin_addr.s_addr=inet_addr(argv[1]);

printf("Sending the string %s to the server side\n",argv[3]);
ret=sendto(sd,argv[3],strlen(argv[3]),0,(struct sockaddr*)&server_addr,sizeof(server_addr));
if(-1==ret)
{
printf("send failed\n");
}
close(sd);
return 0;
}
