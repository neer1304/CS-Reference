/*
This Program demonstrates the usage of following system calls
open()
read()
write()
close()
and what happens when fork is used along with these calls

*/ 

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int  filefdOne   = -1;
	int  numchread   = 0;
	int  childstatus = 0;
	char temp[16];

	//opens file only if the file exists
	filefdOne = open("fileone",O_RDWR);
	if (-1 == filefdOne)
	{
		perror("fileone open failed");
		exit(-1);
	}
	printf("filefdOne %d\n", filefdOne);
	if (!fork())
	{
		//read fileone and write on the standard output
		numchread = read(filefdOne,temp,15);
		temp[numchread] = '\0';
		if(0 != numchread)
		{
			printf("printing by child : %s\n", temp);
		}
	}
	else
	{
		wait(&childstatus);
		
		//read fileone and write on the standard output
		numchread = read(filefdOne,temp,15);
		temp[numchread] = '\0';
		if(0 != numchread)
		{
			printf("printing by parent : %s\n", temp);
		}
	}
	close(filefdOne);
}
