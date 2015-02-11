/* parent waiting for more than 1 child */

#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

main()
{
 pid_t pid1,pid2;
int i,wpid;
pid1 =fork();
if(pid1 ==0)
{     /*  for(i=0;i<100;i++)
        printf("\nhello\n");*/
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
	wpid = wait(0);
	printf("Child with pid %d died \n",wpid);
	wpid=wait(0);
	printf("child with pid %d died \n",wpid);
	printf("\ni am parent\n");
}
}
}
