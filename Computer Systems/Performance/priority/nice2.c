#include<stdio.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<errno.h>

main(int argc, char*argv[])
{
	int priority,ret;

	if ((argv[1]==NULL)&&(argv[2]==NULL)) 
	{
		printf("Please enter the nice value\n");
		exit(0);
	}
	priority=getpriority(PRIO_PROCESS,0);
	printf("My priority  before doing nice is %d\n",priority);
	errno=0;
	ret=nice(atoi(argv[1]));
	
	if(-1==ret)
	{
			printf("Nice Unsuccessful-errno=%d\n",errno);

		
	}

	priority=getpriority(PRIO_PROCESS,0);
	printf("My priority after nice before sleeping is %d\n",priority);
	sleep(1);
        ret =nice(atoi(argv[2]));
	priority=getpriority(PRIO_PROCESS,0);
	printf("My priority after nice after sleeping is %d\n",priority);
	
}
