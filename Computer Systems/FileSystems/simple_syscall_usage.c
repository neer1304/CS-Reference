/*
This Program demonstrates the usage of following simple system calls
open()
read()
write()
close()
*/ 

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int  filefdOne = -1;
	int  filefdTwo = -1;
	char temp;

	//opens file only if the file exists
	//why do you need "open" call?
	filefdOne = open("fileone",O_RDWR); 
	if (-1 == filefdOne)
	{
		perror("fileone open failed");
		exit(-1);
	}

	//opens a file and creates it if it does not exists. The third argumenti
	//gives the permissions
	//experiment with various permission values
	filefdTwo = open("filetwo",O_CREAT|O_RDWR|O_EXCL, S_IRWXU|S_IRWXG|S_IRWXO);
	if (-1 == filefdTwo)
	{
		perror("filetwo open failed");
		exit(-1);
	}
	
	//read fileone byte by byte and write into filetwo
	while(0 != (read(filefdOne,&temp,1)))
	{
		write(filefdTwo, &temp, 1);
		write(1,&temp,1);
	}
	close(filefdOne);
	close(filefdTwo);
}
