#include<stdio.h>
#include<unistd.h>

int main()
{
	int  numchread = 0;
	char temp[16];

	printf("child program running  %d\n", getpid);
	numchread = read(3,temp,15);
//	numchread = read(filefdOne,temp,15);
	temp[numchread] = '\0';
	if(0 != numchread)
	{
		printf("printing by child : %s\n", temp);
	}
	return 1;
}
