#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


int readfunction()
{
	int    fd;
	int    retval = 0;
	int    lcounter = 0;
	size_t buffsize = 31;
	char   readbuffer[32];

        retval = mkfifo("abcfile", S_IRWXU);
	if(-1 == retval)
        {
		printf("FIFO CREATION ERROR\n");
		if(EEXIST==errno)
		{
			printf("FIFO ALREADY Exists\n");
                }
		else
			exit(-1);
        }
	fd = open("abcfile", O_RDONLY);
	memset(readbuffer,'\0',32);
	while (lcounter++ < 16)
	{
		buffsize = read(fd, readbuffer, buffsize);
		if (buffsize > 0)
		{       printf("I have read\n");
			write(1, readbuffer, buffsize);
		}
		buffsize = 31;
	}
	close(fd);
	return;
}

int main ()
{

	printf("I am the reader program\n");
	readfunction();
	printf("I am done with reading\n");
	return 1;
}

