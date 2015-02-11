#include"msgqueue.h"


int putqueue(int Q[],int *front,int *rear,int item)
{
sem_wait(&writer);

if((*rear+1)%MAX==*front)
{
//sem_post(&reader);
printf("Queue overflow\n");
}

if(END==*front)
{
pthread_mutex_lock(&mut);
*front=0;
*rear=0;
pthread_mutex_unlock(&mut);
}

else
{
pthread_mutex_lock(&mut);
*rear=(*rear+1)%MAX;
pthread_mutex_unlock(&mut);
}

pthread_mutex_lock(&mut);
Q[*rear]=item;
pthread_mutex_unlock(&mut);

sem_post(&reader);

return SUCCESS;
}


int getqueue(int Q[],int *front,int *rear)
{
int item;
sem_wait(&reader);

if(END==*front)
{
//sem_post(&writer);
printf("Queue is empty\n");
}

else if(*front==*rear)
{
pthread_mutex_lock(&mut);

item=Q[*front];
*front=END;
*rear=END;

pthread_mutex_unlock(&mut);

sem_post(&writer);
return item;
}
else
{
pthread_mutex_lock(&mut);

item=Q[*front];
*front=(*front+1)%MAX;

pthread_mutex_unlock(&mut);

sem_post(&writer);
return item;
}
}


int initqueue(int Q[],int front,int rear)
{
int i;
for(i=front;i<rear;i++)
Q[front]=0;
return SUCCESS;
}
