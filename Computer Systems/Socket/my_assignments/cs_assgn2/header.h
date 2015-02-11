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

#define SUCCESS 0
#define FAILURE 1

typedef struct snode
{
char *str;
//char word;
struct snode *next;
}snode;

int push(snode **top,char w[]);

char* pop(snode **top);
