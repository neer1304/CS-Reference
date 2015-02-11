#include<sys/mman.h>
#include<semaphore.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
main()
{

	int i,fd;
	struct stat stat;
	int x = 2;
	i =0;
	int *ptr = &x;
	pid_t pid;
	fd = shm_open("/t5",O_CREAT|O_RDWR|O_TRUNC,S_IRUSR|S_IWUSR);
	ftruncate(fd,sizeof(fd));
	ptr = (int *) mmap(0,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	close(fd);
	printf("ptr value =%u:\n",ptr);
	*ptr = 2;
	pid = fork();
	if(pid ==0)
	{
		printf("child ptr value =%d: and virtual address : %u\n",*ptr,ptr);
		*ptr = i % 256;
		sleep(1);
		printf("After sleep child ptr value =%d:\n",*ptr);
		exit(0);
	}
	else
	{
		printf("Parent ptr value =%d and virtual address : %u:\n",*ptr,ptr);
		sleep(1);
		*ptr = 10;
	}
	wait(NULL);
	exit(0);
}
