/*
Producer Consumer problem where one thread deposits an amount in an account and the other thread withdraws from the same account. However the withdrwal should happen only when the account has more than 1000.
*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

#define LOOPSZ 		100
#define ACCOUNTEMPTY	1000
#define WITHDRAWALLIMIT	1000
#define DEBUG           1   

int 		account        = 5000;
int		depositamount  = 100;
int		withdrawamount = 100;
pthread_mutex_t	cmutex         = PTHREAD_MUTEX_INITIALIZER;

/*
deposits in the account
*/
int deposit(int amount) 
{
	pthread_mutex_lock(&cmutex);
	account = account+amount;
	#ifdef DEBUG
	  printf("Deposit %d\n", account);
	#endif
	pthread_mutex_unlock(&cmutex);
	return 0;
}


void* depositor(void *arg)
{
	int lindex = 0;
	while(lindex < LOOPSZ) {
		deposit(depositamount);
		lindex++;
	}
	return NULL;
	
}

/*
withdraws from the account if the account has more than ACCOUNTEMPTY
does not allow withdrawal if the amount is bigger than the WITHDRAWALLIMIT
*/

int withdraw(int amount) 
{
	int retval = 0;
	//you can't withdraw an amount bigger than WITHDRAWALLIMIT
	if (amount > WITHDRAWALLIMIT)
	{
		return retval;
	}
	pthread_mutex_lock(&cmutex);
	if (account > ACCOUNTEMPTY)
	{
		account = account-amount;
		printf("Account after withdrawal %d \n ", account );
                retval  = 1;
	}
	pthread_mutex_unlock(&cmutex);
	return retval;
}

/*
withdraws continuously in a loop
*/

void* withdrawer(void *arg) 
{
	int lindex = 0;
	int retval = 0;
	while(lindex < LOOPSZ)
	{
		while (!retval)
		{
			retval = withdraw(withdrawamount);
		}
		retval =0;
                lindex++;
	}
	return NULL;
}
	
int main(void)
{
	pthread_t tid1,tid2;
	int rv1,rv2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	rv1 = pthread_create(&tid1,&attr,(void *)depositor,NULL);
	if(rv1 != 0)
	{
		printf("\n Cannot create thread");
		exit(0);
	}

	rv2 = pthread_create(&tid2,&attr,(void *)withdrawer,NULL);
	if(rv2 != 0)
	{
		printf("\n Cannot create thread");
		exit(0);
	}
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);


	return(0);
}
