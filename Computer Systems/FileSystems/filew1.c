#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
main()
{
	int fd1,n;
	int data =10;
	/*create a file for writing */
	fd1=open("file1",O_APPEND);
	/*Check the return value of functions for success/failure*/
	if (fd1 < 0)
	{
		printf("File opening Failed\n");
		exit(1);
	}
lseek(fd1,-2,SEEK_END);
	/*Write some data in the file*/
	n=write(fd1,&data, sizeof(data));
	if (-1 == n)
	{	printf("Error in eriting the file\n");
		exit(1);
	}
	printf("Number of bytes written =%d\n",n);
	/*Closing the file descriptor*/
	close(fd1);
}




