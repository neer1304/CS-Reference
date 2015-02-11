/*
This Program demonstrates the usage of following system calls
dup()
lseek()
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int  filefdOne  = -1;
	int  filefdTwo  = -1;
	int  stdoutfd   = -1;
	int  fileptr    = 0;
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
	filefdTwo = open("filetwo",O_CREAT|O_RDWR, S_IRWXU|S_IRWXG|S_IRWXO);
	if (-1 == filefdTwo)
	{
		perror("filetwo open failed");
		exit(-1);
	}

	//closes standard output file
	close(1);
	//This dup call returns 1 as the fd
	stdoutfd = dup(filefdTwo);
	fileptr = printf("funny\n");
	fileptr = write(1, "fuuny", 5);
	if (fileptr <= 0)
	{
		perror("filetwo write failed 1");
	}
	
	fileptr = write(1, "fuuny", 5);
	if (-1 == fileptr)
	{
		perror("filetwo write failed 2");
	}


	//closes filefdTwo descriptor
	close(filefdTwo);
	
	//read fileone byte by byte and write on the standard output 
	while(0 != (read(filefdOne,&temp,1)))
	{
		printf("%c", temp);
	}
	fflush(stdout);

	//set file offset(pointer) to the begining of the file
	fileptr = lseek(filefdOne, 0, SEEK_SET);
	if (0 != fileptr)
	{
		perror("lseek call failed");
		exit(-1);
	}

	//if you close stdoutfd/1, what do you think would happen?
//	close(stdoutfd);
	//close(1);
	//read fileone byte by byte and write on the standard output 
	while(0 != (read(filefdOne,&temp,1)))
	{
		printf("%c", temp);
	}

	close(filefdOne);
}


















