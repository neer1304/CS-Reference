/*
A simple program having three threads
startroutine1 is the entry point function of the first thread created by the main thread
startroutine1 takes an input and computes the factorial for that input

startroutine2 is the entry point function of the second thread created by the main thread
startroutine2 takes an input and computs the fibonacci number for that

what are we demonstrating in this program:
1. why do we need separate stacks for separate threads? 

*/

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int factorial (int number)
{
	printf("Enter factorial input is : %d \n", number);
	int factorialval = 0;
	if (number == 0){
		factorialval = 1;
	}
	else{
		factorialval = number*factorial(number-1);
	}
	printf("Exit factorial output is: %d %d \n", number, factorialval);
	return factorialval;
}

int fibonacci(int number)
{
	printf("Enter fibonacci input is : %d \n", number);
	int fibval = 0;
	if (0 == number)
	{
		fibval = 0;
	}
	if (1 == number)
	{
		fibval = 1;
	}
	if (number > 1)
	{
		fibval = fibonacci(number-1) + fibonacci(number-2);
	}
	printf("Exit fibonacci output is: %d %d \n", number, fibval);
	return fibval;
}


/*
startroutine1 takes an input and computes the factorial for that input
*/

void * startroutine1(void * thr_p) 
{
	int mnumber = thr_p ? *((int *) thr_p) : 0;
	int factorialval;
	factorialval = factorial(mnumber);
	printf("factorial value is: %d\n", factorialval);
	return (NULL);
}

/*
startroutine2 takes an input and computs the fibonacci number for that
*/

void * startroutine2(void * thr_p)
{
	int number = thr_p ? *((int *) thr_p) : 0;
	int fibvalue;
	fibvalue = fibonacci(number);
	printf("computed fibonacci value %d\n", fibvalue);
	return (NULL);
}


/*
main creates two threads and waits for them to exit
one of the threads is passed the address of a local variable defined in main whereas the other one is given a NULL parameter
*/

int main()
{
	int retval;
	int t1input = 0;
	int t2input = 0;

	int * pthreadoutput;
	pthread_t tidOne;
	pthread_t tidTwo;
	pthread_attr_t atrr;
	pthread_attr_init(&atrr); // initialize attr with default attributes
//	pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);
	printf("please enter the number for factorial computation\n");
	scanf("%d", &t1input);

	printf("please enter the number for fibonacci computation\n");
	scanf("%d", &t2input);

	//thread to compute fibonacci
	retval = pthread_create(&tidTwo, &atrr, startroutine2, (void*)&t2input);
	if (0 != retval)
	{
		printf("thread creation failed\n");
		return (-1);
	}

	//thread to compute factorial
	retval = pthread_create(&tidOne, &atrr, startroutine1, (void*)&t1input);
	if (0 != retval)
	{
		printf("thread creation failed\n");
		return (-1);
	}

	retval = pthread_join(tidOne, (void**)&pthreadoutput);
	if (0 != retval)
	{
		printf("thread join failed\n");
		return (-1);
	}
	retval = pthread_join(tidTwo, (void**)&pthreadoutput);
	if (0 != retval)
	{
		printf("thread join failed\n");
		return (-1);
	}
	return 0;
}
