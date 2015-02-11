#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void *ThreadFunction(void *arg);

void *ThreadFunction(void *arg)
{
int a;
//a=*(int*)arg;
//*(arg)-Null pointer derefernce error
printf("Thread %d executing and thread Id is %ld\n",*(int*)arg,pthread_self());
pthread_exit(NULL);  //control reaches out of non-void function warning
}

int main()
{
int index;
int retval=0;
pthread_t threadId[5];
int *index_arg;
printf("pid of main is %d and threadId is %ld\n",getpid(),pthread_self());
for(index=1;index<=5;index++)
{
index_arg=(int*)malloc(sizeof(int));
*index_arg=index;
//retval=pthread_create(&threadId[index],NULL,ThreadFunction,(void*)&index); 
//take time to update the stack from register 
//sleep(2);
retval=pthread_create(&threadId[index],NULL,ThreadFunction,index_arg); 
//error if pass address of index as it is overriden by other thread
if(-1==retval)
perror("Error creating thread");
//pthread_join(threadId[index],NULL);
}

for(index=1;index<=5;index++)
{
retval=pthread_join(threadId[index],NULL);
if(0!=retval)
perror("Error in pthread_error");
}
pthread_exit(NULL);
}
