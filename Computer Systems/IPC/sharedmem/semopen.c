#include<unistd.h>
#include<sys/types.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<errno.h>


main()
{
	int fd,i,buf,fd1,fd2,len;
	//sem_t *buf1,*buf2;
	int *count ;
	int x = 2;
	sem_t *psem1,*csem1;
	
	fd = shm_open("./t4",O_CREAT|O_TRUNC|O_RDWR,S_IRWXU);
	write(fd,&buf,sizeof(int));
	ftruncate(fd,sizeof(fd));
	close(fd);
	count = (int *)mmap(0,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);	
//	psem = sem_open("sem",O_CREAT|O_TRUNC,S_IRWXU,0);
//	csem = sem_open("sem1",O_CREAT|O_TRUNC,S_IRWXU,1);
     /*  len = sizeof(sem_t);
	printf("\nLength of semaphore%d:\n",len);

	fd1 = shm_open("./t7",O_CREAT|O_RDWR|O_TRUNC,S_IRWXU);
	printf("fd1:%d\n",fd1);
	fd2 = shm_open("./t8",O_CREAT|O_RDWR|O_TRUNC,S_IRWXU);
	printf("fd2:%d\n",fd2);
	if(fd1!=0)
	    perror("open");
	else
	    printf("t3 open");
	if(fd2!=0)
	    perror("open");
	else
	    printf("t2 open");
	write(fd1,&buf1,sizeof(sem_t));
	write(fd2,&buf2,sizeof(sem_t));
	close(fd1);
	close(fd2);
        psem1 = (sem_t *)mmap(0,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd1,0);
        csem1 = (sem_t *)mmap(0,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd2,0);
	
	printf("Shared memory value:%u\n",count);
	printf("Semaphore value:%u\n",psem1);
	printf("Semaphore value:%u\n",csem1);
        
	sem_init(psem1,1,0);
	sem_init(csem1,1,1);*/

	*count = 2;
       if(fork() == 0)
	{
  	   printf("Child Process\n");
	   for(i=0;i<10;i++)
	    {
//		sem_wait(csem1);
//		printf("child  Count :%d\n",*count);
		sleep(1);
		*count = 7;
		printf("Hello\n");
		//sem_post(psem1);
	     
	    }
	exit(0);
	}
	else
         {   	
           printf("Parent Process\n");
	   for(i=0;i<10;i++)
	    {
		//sem_wait(psem1);
		printf("parent  Count :%d\n",*count);
		*count = 2;
		//sem_post(csem1);
	     }
	  wait(NULL);
	  exit(0);
	}
}
