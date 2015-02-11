#include<pthread.h>
#include<stdio.h>
#define NUM_THREAD 5
void *printme(void *th)
{
	int *p;
	p=(int*)th;
	printf("I am Thread %d\n",*p);
	pthread_exit(NULL);
}
main()
{
	pthread_t threads[NUM_THREAD];
	int t,rc;
	for(t=0;t<NUM_THREAD;t++)
	{
		printf("Creating Thread\n");
		rc=pthread_create(&threads[t],NULL,printme,(void*)&t);
		if(rc) printf("Printf Error Creating Thread");
	}
	pthread_exit(NULL);
	//exit(1);
}



















