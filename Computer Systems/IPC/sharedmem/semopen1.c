#include<unistd.h>
#include<sys/types.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/mman.h>

typedef struct shared
{
	sem_t sem;
	int count;
}shared;

main()
{
	int fd,i,len;
	shared  *ptr;
	shared  *ptr1;
	shared  var;
	int fd1;
	char * pfile = NULL;
	i=0;
	fd1 = open("./t1",O_CREAT|O_RDWR,S_IRWXU);
	fd = open("./t4",O_CREAT|O_RDWR|O_TRUNC,S_IRWXU);
	len = sizeof(struct shared);
        printf("len%u \n",len); 
	write(fd,&var,2*len);
	ptr = (shared*)mmap(NULL,2*len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);	
	pfile = (char*)mmap(NULL,64,PROT_READ|PROT_WRITE,MAP_SHARED,fd1,0);	
	ptr1=ptr+1;
	close(fd1);
	while(i<64)
	{
		*(pfile+i) = 'c';
		printf("%c\n", *(pfile+i));
		i++;
	}

        printf("Ptr(t4):%p \n",ptr);
        printf("Ptr1(t1):%p \n",ptr1);
	close(fd);
        sem_init(&ptr->sem,1,1);/*Semaphore for child */
        sem_init(&ptr1->sem,1,0);/*Semaphor for parent */

       if(fork() == 0)
	{
	   for(i=0;i<10;i++)
	    {
		sem_wait(&ptr->sem);
		printf("Hello child  Count :%d\n",ptr->count++);
		sleep(1);
		printf("Another Hello child  Count :%d\n",ptr->count++);
		sem_post(&ptr1->sem);
	     
	    }
	}
	else
         {   	
	   for(i=0;i<10;i++)
	    {
		sem_wait(&ptr1->sem);
		printf("parent  Count :%d\n",ptr->count++);
		printf("inside Parent process\n");
		sem_post(&ptr->sem);
	     }
	  wait(NULL);
	  exit(0);
	}
}
