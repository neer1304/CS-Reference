#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <semaphore.h>
#include<sys/types.h>
#include<pthread.h>
sem_t sem;

int main()
{
  pid_t childpid;

  key_t key,key1;
  int shmid,shmid1;
  int *data;
  int prev = 3;


 key = ftok("thread1.c",'R');
  //shmid = shmget(key, 1024, 0644 | IPC_CREAT);

  //sem_init(&sem,1,1);

 // data = shmat(shmid, (void *)0, 0);
  //printf("Virtual address%u\n",data);
/*  if(data == (int *)(-1))
    perror("shmat");

  *data = prev;*/


  if((childpid = fork()) < 0) // error occured

    {
      perror("Fork Failed");
      exit(1);
    }
  else if(childpid == 0) // child process
    {
      /* Write to Shared Memory */
  key1 = ftok("thread2.c",'R');
  shmid = shmget(key1, 4, 0644 | IPC_CREAT);
      data = shmat(shmid,(void *)0,0); 
  shmid1 = shmget(key, 4, 0644 | IPC_CREAT);
    data = shmat(shmid1,(void *)0,0); 
 *data=2000;
          printf("Virtual address%u\n",data);
//	malloc(200); 
  //  data = shmat(shmid,(void *)0,0); 
   //  while(*data<=20)
     //   {
          printf("child Virtual address%u  %d\n",data,*data);
		sleep(5);
//          sem_wait(&sem);
          printf("Child Process\n");
          *data = *data + 5;
           printf("%d\n",*data);
  //        sem_post(&sem);
        //}
          sleep(1);
    }
  else // parent process
    {
      /* Write to Shared Memory */
  shmid = shmget(key, 4, 0644 | IPC_CREAT);
      data = shmat(shmid,(void *)0,0); 
          printf("Parent Virtual address%u  %d\n",data,*data);
      //while(*data<=50)
        //{
          printf("Virtual address%u\n",data);
    //      sem_wait(&sem);
          printf("Parent\n");
          *data = *data + 10;
           printf("%d\n",*data);
      //    sem_post(&sem);
        //}
    }

  /* Detach from Shared Memory */
  shmdt((void *)data);

  return 0;
}
