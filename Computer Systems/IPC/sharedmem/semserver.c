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
	//sem_t sem;
	int count;
}shared;
sem_t *sem;
main()
{
	int fd,i,len;
	shared  *ptr;
	shared  var;
	fd = shm_open("/t4",O_CREAT|O_RDWR|O_TRUNC,S_IRWXU);
	len = sizeof(struct shared);
        printf("len%u \n",len); 
	//write(fd,&var,2*len);
	ptr = (shared*)mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);	
	ftruncate(fd,sizeof(fd));
        printf("Ptr%u \n",ptr);
	close(fd);
	sem = sem_open("/t1",O_CREAT|O_EXCL|O_RDWR,S_IRWXU,1);
	//sem_wait(sem);
        printf("Ptr%u \n",ptr);
	//sem_post(sem);
        sem_close(sem);

	exit(0);
}
