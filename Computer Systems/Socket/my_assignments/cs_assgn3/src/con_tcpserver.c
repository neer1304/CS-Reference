#include"header.h"
#define PORT 34125

void sig_handler(int code)
{
exit(0);
}

void sig_handler1(int code)
{
exit(0);
}

void sig_handler_chd(int code)
{
while(waitpid(-1,NULL,WNOHANG)>0);
}

int main()
{
signal(SIGINT,sig_handler);
signal(SIGTSTP,sig_handler1);
signal(SIGCHLD,sig_handler_chd);

char buf[100];

pid_t pid;

int num;

memset(buf,0,100);

int buffer[100];
int i=0;
int n;

int yes=1;

socklen_t clen;

struct sockaddr_in my_addr,client_addr;

int ret;

int listensocket,new_socket;

listensocket=socket(AF_INET,SOCK_STREAM,0);

if(-1==listensocket)
{
perror("socket");
exit(1);
}

if(-1==(setsockopt(listensocket,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int))));
{
perror("setsockopt");
}

memset(&my_addr,0,sizeof(my_addr));

my_addr.sin_family=AF_INET;
my_addr.sin_port=htons(PORT);
my_addr.sin_addr.s_addr=htonl(INADDR_ANY);

ret=bind(listensocket,(struct sockaddr*)&my_addr,sizeof(struct sockaddr));

if(-1==ret)
{
perror("bind");
}
clen=sizeof(client_addr);

listen(listensocket,10);


while(1)
{
new_socket=accept(listensocket,(struct sockaddr*)&client_addr,&clen);
if(-1==new_socket)
{
perror("new_socket");
exit(1);
}

printf("Server recieved connection from %s\n",inet_ntoa(client_addr.sin_addr));
//printf("Server recieved connection from %s\n",inet_ntop(AF_INET,&client_addr.sin_addr,buf,sizeof(buf)));

pid=fork();

if(pid==0)
{
close(listensocket);

printf("The number recieved are :-\n");
while((n=(read(new_socket,(char*)&buffer[i],sizeof(int))))>0)
{
printf("%d ",buffer[i]);
i++;
}
//num=sizeof(buffer)/sizeof(buffer[0]);
num=i;
mergesort(buffer,0,num-1);
//while((n=write(new_socket,buffer,sizeof(int)))>0);

printf("\nThe array after sorting is :-\n");
for(i=0;i<num;i++)
printf("%d ",buffer[i]);

printf("\nNow sending to the client\n");

//ret=write(new_socket,(char*)buffer,sizeof(buffer));  //this also work
for(i=0;i<num;i++)
write(new_socket,(char*)&buffer[i],sizeof(int));
if(-1==ret)
{
printf("Write failed\n");
exit(1);
}
close(new_socket);
printf("Finished serving one client\n");
exit(0);
}
close(new_socket);
}
return 0;
}
