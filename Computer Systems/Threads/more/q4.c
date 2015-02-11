#include<pthread.h>
#include<sys/types.h>
#include<stdio.h>
void * th_f(void *arg);
char *string = "string1";
int main(void)
{
	pthread_t ntid; 
	char *lptr;
	int status;
	status=pthread_create(&ntid,NULL,th_f,NULL);
	if (status != 0)
	{
		printf("Error in Creating Thread\n");
		exit(status);
	}
	pthread_join(ntid,(void**)&lptr);
	lptr++;
	printf("%s\n", lptr);
	pthread_exit(NULL);

}
void * th_f(void *arg)
{
	printf("New thread: ");
	string++;
	pthread_exit((void*)string);
	
}
