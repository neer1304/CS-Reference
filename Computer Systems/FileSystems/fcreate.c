/***************************************************************************
*       FILENAME :fcreate.c 
*       DESCRIPTION:Contains Code for a program that demonstrates the
*       use of open and write call.Writes a string in the file.
*       Invoke the Executable as a.out
****************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
main()
{
	int fd1,fd2,n;
	char *filewrite="Writing to  file";
	fd1=open("sample",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
	/*Check the return value of functions for success/failure*/
	if (fd1 < 0)
	{
		perror("fd1:open");
		printf("File opening Failed\n");
		exit(1);
	}

	n=write(fd1,filewrite,strlen(filewrite));
	if (-1 == n)
	{	printf("Error in eriting the file\n");
		exit(1);
	}
	printf("Number of bytes written =%d\n",n);
	/*Closing the file descriptor*/
	close(fd1);
}




