#include<pthread.h>
#include<stdio.h>

typedef struct emp
{
int id;
char name[30];
long int phno;
}emp;

void *PrintEmpInfo(void *arg)
{
emp e;
e=*(emp*)arg;
printf("The emp id is %d\n",e.id);
printf("The emp name is %s\n",e.name);
printf("The emp contact no is %ld\n",e.phno);
pthread_exit(NULL);
}

int main()
{
pthread_t threadId;
emp e;

printf("Enter the emp id\n");
scanf("%d",&e.id);
printf("Ente the emp name\n");
scanf("%s",e.name);
printf("Enter the emp contact no.\n");
scanf("%ld",&e.phno);

int retval;
retval=pthread_create(&threadId,NULL,PrintEmpInfo,(void*)&e);
if(-1==retval)
perror("Error creating thread");

retval=pthread_join(threadId,NULL);

pthread_exit(NULL);
}
