#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<error.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/stat.h>

#define MYPORT 3412
#define MAX 1024

int num=0;

typedef struct ipcon
{
int sd;
char *ipaddrcl;
}ipcon;
