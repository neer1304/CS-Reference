/*  Demo for mutex..When aprocess access aglobal variable it should be locked by mutex and unlocked.  */

#include<pthread.h>
#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>

pthread_mutex_t mymutex=PTHREAD_MUTEX_INITIALIZER;

int balance=1000;

void deposit(void *ptr)
{ 
  int i;
  for(i=1;i<=50;i++)
  {
     pthread_mutex_lock(&mymutex);
     balance=balance+50;
     printf("\nBALANCE AFTER %d DEPOSIT:\t%d\n",i,balance);
     pthread_mutex_unlock(&mymutex);
     sleep(2);
  }
  pthread_exit(NULL);

}



int main()
{
  pthread_t mythread;
  int i;
  
  if(pthread_create(&mythread,NULL,(void*)&deposit,NULL))
  {
         perror("Error in creating thread");
	 exit(1);
  }
  
 
 for(i=1;i<=20;i++)
 {
    pthread_mutex_lock(&mymutex);
    balance=balance-20;
    printf("\nBALANCE AFTER %d WITHDRAWAL:\t%d\n",i,balance);
    pthread_mutex_unlock(&mymutex);
    sleep(1);
 }
 
  
  
  if(pthread_join(mythread,NULL))
  {
      perror("Error in joining the threads");
      exit(1);
  }
  
 
 printf("\n\n\nFINAL BALANCE :\t%d",balance);
 
  printf("\nmain thread exiting\n");
  return 0;
  
}

