/*
A simple program having three threads
startroutine1 is the entry point function of the first thread created by the main thread
startroutine1 takes an input and computes the factorial for that input

startroutine2 is the entry point function of the second thread created by the main thread
startroutine2 takes an input and computes the power number for that

what are we demonstrating in this program:
1. why do we need separate stacks for separate threads? 

*/

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct powerstruct{
	int number;
	int power;
} powerstruct;

int factorial (int number)
{
	printf("Enter factorial input is : %d \n", number);
	sleep(1);
	int factorialval = 0;
	if (number == 0)
	{
		factorialval = 1;
	}
	else if (number > 0)
	{
		factorialval = number*factorial(number-1);
	}
	printf("Exit factorial output is: %d %d \n", number, factorialval);
	return factorialval;
}

int power(int number, int exp)
{
	printf("Enter power input is : %d  %d\n", number, exp);
	sleep(1);
	int powerval = 0;
	if (0 == number)
	{
		powerval = 0; //not required
	}
	else
	{
		if (0 == exp)
		{
			powerval = 1;
		}
		else if (exp > 0)
		{
			powerval = number*power(number, exp-1);
		}
	}
	printf("Exit power output is: %d %d \n", number, powerval);
	return powerval;
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
startroutine2 takes an input and computes the power number for that
*/

void * startroutine2(void * thr_p)
{
	powerstruct * pNumber = thr_p;
	int powervalue;
	powervalue = power(pNumber->number, pNumber->power);
	printf("computed power value %d\n", powervalue);
	return (NULL);
}


/*
main creates two threads and waits for them to exit
one of the threads is passed the address of a local variable defined in main whereas the other one is given a NULL parameter
*/

int main()
{
	int          retval;
	int          t1input = 0;
	powerstruct  t2input = {0, 0};

	int * pthreadoutput;

	pthread_t tidOne;
	pthread_t tidTwo;
	pthread_attr_t atrr;
	pthread_attr_init(&atrr); // initialize attr with default attributes

	printf("please enter the number for factorial computation\n");
	scanf("%d", &t1input);

	printf("please enter the number for power computation\n");
	scanf("%d", &t2input.number);

	printf("please enter the exponent for power computation\n");
	scanf("%d", &t2input.power);

	//thread to compute power
	retval = pthread_create(&tidTwo, &atrr, startroutine2, (void*)&t2input);
	if (0 != retval)
	{
		printf("thread creation failed\n");
		return (-1);
	}

	//thread to compute factorial
	retval = pthread_create(&tidOne, &atrr, startroutine1, (void*)&t1input);
	//retval = pthread_create(&tidOne, &atrr, startroutine1, NULL);
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
