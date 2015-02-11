/*
This results into the following behaviour: 
This program is able to append the contents of a file at the end of the same file. 

How does this work?
This piece of code shows that printf keeps a buffer internally and does not flush into the standard output immediately.

But this program works only if the file size is smaller than the internal buffer used by printf. The printf buffer is flushed only when the program is exiting, i.e., after the main returns and before the process exits.

If the second close call "close(stdoutfd);" is invoked then file is closed as both descriptors are closed. In that scenario all characters buffered in the printf's internal buffer is discarded since the file is closed and nothing is redirected to the file.
If write() system call is used instead of printf then it won't work as there is no buffering
*/ 

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int  filefd = -1;
	int  stdoutfd;
	char temp;

	//filefd = open("temp",O_RDWR);
	filefd = open("temp",O_CREAT|O_RDWR, S_IRWXU|S_IRWXG|S_IRWXO);
	if (-1 == filefd) {
		perror("file open failed");
		exit(-1);
	}
//	printf("1funny\n");
	
	close(1);

	/*This dup call returns 1 as the fd*/
	stdoutfd = dup(filefd);
	
	while(0 != (read(filefd,&temp,1))) {
		printf("%c\n",temp);
		/*if you use write system call then you won't see 
		  what you want to see*/
/*
		write(1, &temp, 1);
		write(1, "\n", 1);
*/
	}
	printf("\n");
//	fflush(stdout);

	close(filefd);
	/*if you use the following close system call then you won't see 
	  what you want to see*/
	close(stdoutfd);
}







