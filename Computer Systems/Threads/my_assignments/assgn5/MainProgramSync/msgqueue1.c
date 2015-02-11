#include"msgqueue.h"

sem_t qsem;

int putqueue(int Q[],int *front,int *rear,int item)
{

if((*rear+1)%MAX==*front)
{
//sem_post(&reader);
printf("Queue overflow\n");
}

if(END==*front)
{
*front=0;
*rear=0;
}
else
{
*rear=(*rear+1)%MAX;
}
Q[*rear]=item;
return SUCCESS;
}


int getqueue(int Q[],int *front,int *rear)
{
int item;
if(END==*front)
{
//sem_post(&writer);
printf("Queue is empty\n");
}
else if(*front==*rear)
{
item=Q[*front];
*front=END;
*rear=END;
return item;
}
else
{
item=Q[*front];
*front=(*front+1)%MAX;
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
