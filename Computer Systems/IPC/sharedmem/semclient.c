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
	int count;
}shared;

sem_t *sem;

main()
{
	int fd,i,len;
	pid_t pid;
	shared  *ptr;
	shared  *ptr1;
	shared  var;
	int fd1;
	char * pfile = NULL;
	fd1 = open("t1",O_CREAT|O_RDWR,S_IRWXU);
	fd = shm_open("/t4",O_RDWR,S_IRWXU);
	len = sizeof(struct shared);
        printf("len%u \n",len); 
	write(fd,&var,2*len);
	ptr = (shared*)mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);	

        printf("Ptr%u \n",ptr);
	close(fd);
	sem = sem_open("/t1",0);
         pid = getpid();
	for(i=0;i<10;i++)
	{
		sem_wait(sem);
		printf("pid :%ld : %d\n",(long)pid,ptr->count++);
		sleep(2);	
		printf("Hello\n");
		sem_post(sem);
	}
	exit(0);
}
