#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int balance=1000;
pthread_mutex_t gmutex=PTHREAD_MUTEX_INITIALIZER;

void *Deposit(void *arg1)
{
//int b;
int i;
//b=*(int*)arg1;
pthread_mutex_lock(&gmutex);
for(i=0;i<50;i++)
//b=b+50;
*(int*)arg1=*(int*)arg1+50;
//sleep(6);
pthread_mutex_unlock(&gmutex);
printf("In deposit function balance is %d\n",*(int*)arg1);
}

void *Withdraw(void *arg2)
{
//int w;
int j;
//w=*(int*)arg2;
pthread_mutex_lock(&gmutex);
for(j=0;j<20;j++)
*(int*)arg2=*(int*)arg2-20;
pthread_mutex_unlock(&gmutex);
printf("In withdraw function balance is %d\n",*(int*)arg2);
}

int main()
{
pthread_t t1,t2;
int retval;
//int *bal;
//bal=malloc(sizeof(int));
//*bal=balance;
retval=pthread_create(&t1,NULL,Deposit,(void*)&balance);
if(-1==retval)
printf("Thread t1 failed\n");
//sleep(3);
//*bal=balance;
retval=pthread_create(&t2,NULL,Withdraw,(void*)&balance);
if(-1==retval)
printf("Thread t2 failed\n");

pthread_join(t1,NULL);
pthread_join(t2,NULL);
}
