#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>

int account=1000;
//pthread_mutex_t gmutex=PTHREAD_MUTEX_INITIALIZER;
sem_t sdepo,swid;

void *Deposit(void *arg1)
{
//int b;
int i;
//b=*(int*)arg1;
//pthread_mutex_lock(&gmutex);
sem_wait(&sdepo);
for(i=0;i<50;i++)
//b=b+50;
*(int*)arg1=*(int*)arg1+50;
sleep(1);
//pthread_mutex_unlock(&gmutex);
sem_post(&swid);
printf("In deposit function balance is %d\n",*(int*)arg1);
}

void *Withdraw(void *arg2)
{
//int w;
int j;
//w=*(int*)arg2;
//pthread_mutex_lock(&gmutex);
sem_wait(&swid);
if(*(int*)arg2>1000)
{
for(j=0;j<20;j++)
*(int*)arg2=*(int*)arg2-20;
printf("In withdraw function balance is %d\n",*(int*)arg2);
}
else
{
printf("Balance not enough to withdraw\n");
//sleep(1);
}
sem_post(&sdepo);
//pthread_mutex_unlock(&gmutex);
}

int main()
{
pthread_t t1,t2;
int retval;

sem_init(&sdepo,0,1);
sem_init(&swid,0,0);
//int *bal;
//bal=malloc(sizeof(int));
//*bal=account;
retval=pthread_create(&t1,NULL,Withdraw,(void*)&account);
if(-1==retval)
printf("Thread t1 failed\n");
//sleep(3);
//*bal=account;
retval=pthread_create(&t2,NULL,Deposit,(void*)&account);
if(-1==retval)
printf("Thread t2 failed\n");

pthread_join(t1,NULL);
pthread_join(t2,NULL);
}
