#include"header.h"

int main(int argc,char *argv[])
{
struct sockaddr_in server_add;
int sd;
int ret;
int n;
int arr[100];
int i,j;
int sarr[100];

if(argv[1]==NULL)
{
printf("Please enter server ip address\n");
exit(1);
}
if(argv[2]==NULL)
{
printf("Please enter port no.\n");
exit(1);
}
sd=socket(AF_INET,SOCK_STREAM,0);
if(sd<0)
{
perror("socket");
exit(1);
}

memset(&server_add,0,sizeof(server_add));

server_add.sin_family=AF_INET;
server_add.sin_port=htons(atoi(argv[2]));
server_add.sin_addr.s_addr=inet_addr(argv[1]);

ret=connect(sd,(struct sockaddr*)&server_add,sizeof(struct sockaddr));

if(ret==-1)
{
perror("connect");
exit(1);
}

ag:
printf("Please enter the number you want to sort\n");
scanf("%d",&n);
if(n>100)
{
printf("This is too much please enter number less than 100\n");
goto ag;
}
printf("Please enter the %d numbers you want to sort\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
write(sd,(char*)&arr[i],sizeof(int));
}
shutdown(sd,1);
//while(n=read(sd,arr,sizeof(int))>0);
for(i=0;i<n;i++)
{
ret=read(sd,(char*)&sarr[i],sizeof(int));
if(-1==ret)
printf("Read failed\n");
}

printf("After sorting the contents are:-\n");
for(j=0;j<n;j++)
printf("%d ",sarr[j]);
printf("\n");
close(sd);
}
