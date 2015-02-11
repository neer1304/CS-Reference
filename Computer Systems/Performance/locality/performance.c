/*
The following program demonstrates how exploiting space locality can improve the performance of a program.
function1() and function2() both are trying to do the same thing but the logic is slightly different.
function1() exploits space locality better than function2() and so the performance of function1() is better than function2() 
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

//#define MAX_INDEX 3 
//#define LOOP_SIZE  1
#define MAX_INDEX 0xfff
#define LOOP_SIZE 0xf

char darray[MAX_INDEX][MAX_INDEX] = {0};

void * function1() 
{
	int i = 0;
	int j = 0;
	for (i = 0; i < MAX_INDEX; i++)
	{
		for (j = 0; j < MAX_INDEX; j++)
		{
			darray[i][j] = 2*darray[i][j];
//			printf("function 1 %u\n", &darray[i][j]);
		}
	}
	return ((void *) NULL);
}

void * function2() 
{
	int i = 0;
	int j = 0;
	for (i = 0; i < MAX_INDEX; i++)
	{
		for (j = 0; j < MAX_INDEX; j++)
		{
			darray[j][i] = 2*darray[j][i];
//			printf("function 2 %u\n", &darray[j][i]);
		}
	}
	return ((void *) NULL);
}

void * option1(void * thr_p) {
	int i = 0;
	while (i++ < LOOP_SIZE)
	{
		function1();
	}
	return ((void *) NULL);
}

void * option2(void * thr_p) {
	int i = 0;
	while (i++ < LOOP_SIZE)
	{
		function2();
	}
	return ((void *) NULL);
}



int main()
{
	struct timeval starttime;
	struct timeval endtime;

	gettimeofday(&starttime, NULL);
	option1(NULL);
	gettimeofday(&endtime, NULL);

	printf("start time %u : %u\n", starttime.tv_sec, starttime.tv_usec);
	printf("end time   %u : %u\n", endtime.tv_sec, endtime.tv_usec);


	gettimeofday(&starttime, NULL);
	option2(NULL);
	gettimeofday(&endtime, NULL);

	printf("start time %u : %u\n", starttime.tv_sec, starttime.tv_usec);
	printf("end time   %u : %u\n", endtime.tv_sec, endtime.tv_usec);

	return 0;
}
