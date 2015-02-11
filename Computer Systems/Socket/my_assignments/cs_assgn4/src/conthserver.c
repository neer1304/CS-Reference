#include"header.h"

#define PORT 34125

void* doit(void *arg);
void* count(void *arg);

void sig_handler(int code)
{
pthread_t th1;
pthread_create(&th1,NULL,count,NULL);
}

void sig_handler1(int code)
{
exit(0);
}

void sig_chld(int code)
{
while(waitpid(-1,NULL,WNOHANG)>0);
}

int main()
{
signal(SIGINT,sig_handler);
signal(SIGTSTP,sig_handler1);
signal(SIGCHLD,sig_chld);

struct sockaddr_in my_addr,client_addr;

int listensocket,new_socket;

int ret;

socklen_t len;

//struct hostent* h;

ipcon *pipcon;

//pipcon = &ipcon;

pthread_t th2;

int yes=1;

listensocket=socket(AF_INET,SOCK_STREAM,0);
if(-1==listensocket)
{
perror("socket");
exit(1);
}

memset(&my_addr,0,sizeof(my_addr));
my_addr.sin_family=AF_INET;
my_addr.sin_port=htons(PORT);
my_addr.sin_addr.s_addr=htonl(INADDR_ANY);

//setsockopt(listensocket,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int));

ret=bind(listensocket,(struct sockaddr*)&my_addr,sizeof(my_addr));
if(-1==ret)
{
perror("bind");
exit(1);
}

//pthread_create(th1,NULL,count,NULL);

listen(listensocket,5);

while(1)
{
len=sizeof(client_addr);

new_socket=accept(listensocket,(struct sockaddr*)&client_addr,&len);
if(new_socket<0)
{
perror("new_socket");
exit(1);
}
printf("Recieved connection from %s\n",inet_ntoa(client_addr.sin_addr));

pipcon=(struct ipcon*)malloc(sizeof(ipcon));

pipcon->sd=new_socket;

pipcon->ipaddrcl=inet_ntoa(client_addr.sin_addr);

pthread_create(&th2,NULL,doit,(void*)pipcon);
}
//close(listensocket);
}

void* count(void *arg)
{
printf("The number of client serviced are %d\n",num);
pthread_exit(NULL);
}

void* doit(void *arg)
{
char c;
int ret;
char buff[MAX];
memset(buff,'\0',MAX);
struct ipcon *ipc = (struct ipcon*)arg;
int i=0;
while(1)
{
if(i>MAX)
break;
ret=read(ipc->sd,&c,1);
if(ret<=0)
break;
buff[i]=c;
i++;
//printf("in while loop\n");
}
buff[i+1]='\0';
printf("The string recvd from client side - %s now concatinating ip address\n",buff);
strcat(buff,ipc->ipaddrcl);
printf("After concat %s now writing to socket\n",buff);
write(ipc->sd,buff,strlen(buff));
num++;
close(ipc->sd);
pthread_exit(NULL);
}
