#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<semaphore.h>
#include<stdlib.h>

void* reader(void *arg);
void* writer(void *arg);


int buff[2];

sem_t rd;
sem_t wrt;

//int i=0;

void *reader(void *arg)
{
int j=0;
//printf("In reader thread\n");
for(j=0;j<9;j++)
{
sem_wait(&rd);
printf("Reader read %d from the buffer\n",buff[*(int*)arg]);
(*(int*)arg)++;
//i++;
if(*(int*)arg>1)
*(int*)arg=0;
sem_post(&wrt);
}
return NULL;
}

void *writer(void *arg)
{
int j=0;
for(j=0;j<9;j++)
{
//printf("In writer thread\n");
sem_wait(&wrt);
buff[*(int*)arg]=*(int*)arg;
printf("Writer wrote %d in the buffer\n",*(int*)arg);
//*(int*)arg++;
//if(*(int*)arg>1)
//*(int*)arg=0;
sem_post(&rd);
}
return NULL;
}

int main()
{
sem_init(&rd,0,0);
sem_init(&wrt,0,1);

pthread_t t1,t2;
int i=0;
int retval;

retval=pthread_create(&t1,NULL,(void*)writer,(void*)&i);
if(0!=retval)
{
perror("writer");
exit(1);
}

retval=pthread_create(&t2,NULL,(void*)reader,(void*)&i);
if(0!=retval)
{
perror("reader");
exit(1);
}

pthread_join(t1,NULL);
pthread_join(t2,NULL);

return 0;
}
