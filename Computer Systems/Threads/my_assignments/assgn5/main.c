#include"msgqueue.h"
#define LOOPSZ 20

sem_t reader;
sem_t writer;
pthread_mutex_t qmutex;
int buffer[MAX];
int front=END;
int rear=END;


void *enqueue(void *arg)
{
int data=0;
int bindex;
for(bindex=0;bindex<MAX;)
{
//sem_wait(&writer);
pthread_mutex_lock(&qmutex);
putqueue(buffer,&front,&rear,data);
pthread_mutex_unlock(&qmutex);
//m_post(&reader);
printf("Data stored in queue %d\n",data);
if(data==LOOPSZ)
break;
if(bindex==MAX-1)
{
bindex=0;
//sem_post(&reader);
}
else
bindex++;
data+=1;
}
return NULL;
}


void *dequeue(void *arg)
{
int item=0;
int bindex;
int lindex=0;
//sem_wait(&reader);
for(bindex=0;bindex<MAX;)
{
//sem_wait(&reader);
pthread_mutex_lock(&qmutex);
item=getqueue(buffer,&front,&rear);
pthread_mutex_unlock(&qmutex);
//sem_post(&writer);
printf("Reader read %d from the buffer\n",item);
//printf("Value of lindex is %d\n",lindex);
//if(++lindex==LOOPSZ)
//break;
//if(bindex==MAX-1)
//bindex=0;
//else
bindex++;
}
//sem_post(&writer);
return NULL;
}

int main()
{
int retval;
pthread_t reader1,reader2,reader3,writer1,writer2;

sem_init(&reader,0,0);
sem_init(&writer,0,MAX); //so that writer can run first

//initqueue(buffer,front,rear);

retval=pthread_create(&writer1,NULL,(void*)enqueue,NULL);

if(-1==retval)
{
perror("thread1 creation failed\n");
}

retval=pthread_create(&writer2,NULL,(void*)enqueue,NULL);

if(-1==retval)
{
perror("thread2 creation failed\n");
}
retval=pthread_create(&reader1,NULL,(void*)dequeue,NULL);

if(-1==retval)
{
perror("thread3 creation failed\n");
}
retval=pthread_create(&reader2,NULL,(void*)dequeue,NULL);

if(-1==retval)
{
perror("thread4 creation failed\n");
}
retval=pthread_create(&reader3,NULL,(void*)dequeue,NULL);

if(-1==retval)
{
perror("thread5 creation failed\n");
}
pthread_join(reader1,NULL);
pthread_join(reader2,NULL);
pthread_join(reader3,NULL);
pthread_join(writer1,NULL);
pthread_join(writer2,NULL);
return 0;
}
