/* parent waiting for more than 1 child */

#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

main()
{
 pid_t pid1,pid2;
int i;
pid1 =fork();
if(pid1 ==0)
{      for(i=0;i<5;i++)
        printf("\nhello\n");
	printf("1st child process id is %d\n",getpid());
	printf("\nfirst child died");
}
else
{
	pid2=fork();
	if(pid2==0)
{
	printf("\nsecond child process id is %d\n",getpid());
	printf("second child dead\n");
}
else
{
	sleep(15);
	printf("\nI am parent and I am dying\n");
}
}
}

