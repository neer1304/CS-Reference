#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>

main()
{
	int pid;
	execlp("ls","ls","-l",(char *)0);
	pid =fork();
	execlp("ls","ls","-l",(char *)0);
	if(pid==0)
	{
		printf("\nexec starts\n");
		execlp("ls","ls","-l",(char *)0);
		printf("exit\n");
	}
	else
	{		
		wait(0); 
		printf("parent\n");
	}
}
