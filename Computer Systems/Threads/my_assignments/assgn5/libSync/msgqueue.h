#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<semaphore.h>

#define MAX 5

#define END -1

#define SUCCESS 0

#define FAILURE 0

int putqueue(int Q[],int *front,int *rear,int item);

int getqueue(int Q[],int *front,int *rear);

int initqueue(int q[],int front,int rear);

sem_t reader;
sem_t writer;
pthread_mutex_t mut;
