
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<netinet/in.h>

int main()
{
        unsigned short local = 9251;     
	int fd;    
        unsigned short network = htons(local);  
	printf("Size of Unsigned short =%d", sizeof(unsigned short));	
	printf("The value of Local is %d\n", local);
	printf("The value of Network  is %d\n", network);
	fd= open ("demofile",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
	write(fd, &local , sizeof (unsigned short));
	

}
