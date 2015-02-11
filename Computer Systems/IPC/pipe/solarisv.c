/* To Demonstrate how the pipe is used */

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


main ()
{
	int     pipefd[2];
	int     lcounter = 0;
	ssize_t buffsize = 31;
	char    writebuffer[32];
	char    readbuffer[32];
	pid_t   pid;
	int     status;
	int     filewritefd;
	
	
	pipe (pipefd);			/*Create Pipe with pipefd[0] as readend
					  and pipefd[1] as writeend*/
	pid = fork ();			/*Create the child*/
	
	if (0 == pid)			/*Child */
	{
		close(pipefd[0]);	/*Close the read end of the pipe */
	
		while (lcounter++ < 16)
		{
			printf("please enter the next string to send \n");

			buffsize = read(0, writebuffer, buffsize);
			if (buffsize > 0)
			{
				write(pipefd[1], writebuffer, buffsize);
			}
			buffsize = 31;
			buffsize = read(pipefd[1], readbuffer, buffsize);
			if (buffsize > 0)
			{
				write(1, readbuffer, buffsize);
			}
			buffsize = 31;
		}
		close(pipefd[1]);
		return;
	}
	else				/*Parent*/
	{
		close(pipefd[1]);	/*Close the write end of pipe*/
	
		filewritefd = open ("abcfile", O_WRONLY|O_APPEND);
		while (lcounter++ < 16)
		{
			buffsize = read(pipefd[0], readbuffer, buffsize);
			if (buffsize > 0)
			{
//				write(filewritefd, readbuffer, buffsize);
				write(pipefd[0], readbuffer, buffsize);
			}
			buffsize = 31;
		}
		close(pipefd[0]);
		wait(&status);
		return;
	}
}
