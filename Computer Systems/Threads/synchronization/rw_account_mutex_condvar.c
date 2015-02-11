/*
Producer Consumer problem where one thread deposits and amount in an account and the other thread withdraws from the same account. However the withdrwal should happen only when the account has more than 1000.
If you want conditional compilation of following printf statements 
	#ifdef DEBUG
	printf("deposit in account : %d\n", account);
	#endif
"-DDEBUG" flag is to be used at compile time as follows:

"gcc -DDEBUG rw_account_mutex_condvar.c -lpthread"
There is no need to use "#define DEBUG" statement in this file

*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

#define LOOPSZ 		20
#define ACCOUNTEMPTY	1000
#define WITHDRAWALLIMIT	1000

int 		account		= 0;
int		depositamount	= 100;
int		withdrawamount	= 100;
pthread_mutex_t	cmutex		= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t 	condvar		= PTHREAD_COND_INITIALIZER;

/*
deposits in the account once
*/

int deposit(int amount) 
{
	#ifdef DEBUG
	printf("Deposit thread : is trying to lock mutex\n");
	#endif
        pthread_mutex_lock(&cmutex);
	account = account+amount;
	if (account >= ACCOUNTEMPTY)
	{
		pthread_cond_signal(&condvar);
	}
	pthread_mutex_unlock(&cmutex);
	#ifdef DEBUG
	printf("Deposit thread : value in account : %d\n", account);
	#endif
	return 0;
}

/*
This function deposits an amount by calling the deposit function in a loop
*/

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
blocks the calling thread if the account is <= ACCOUNTEMPTY so that the thread does not waste the cpu time
*/

int withdraw(int amount) 
{
	int retval = 0;
	//you can't withdraw an amount bigger than WITHDRAWALLIMIT
	if (amount > WITHDRAWALLIMIT)
	{
		return retval;
	}
	
	#ifdef DEBUG
        printf("Withdraw thread : trying to lock mutex\n");
	#endif
        pthread_mutex_lock(&cmutex);

	/*
	Any one of the following statements "if ..." or "while ..." can be
	chosen in this program. Obviously the program has different meanings in
	these two cases.
	If we change the program to having multiple withdrawer threads,
	"while ..." is necessary, "if ..." won't work as pthread_cond_signal 
	may wakeup more than one withdrawer threads and the wthdrawal condition 
	in the second withdrawer thread may become false again
	*/
//	if (account < ACCOUNTEMPTY)
	while (account-amount < ACCOUNTEMPTY)
	{
		#ifdef DEBUG
		printf("withdraw thread : going to sleep\n");
		#endif
		pthread_cond_wait(&condvar, &cmutex);
	}
	account = account-amount;
	retval  = 1;

	#ifdef DEBUG
	printf("withdraw thread : the account value is : %d\n", account);
	#endif

	pthread_mutex_unlock(&cmutex);
	return retval;
}

/*
withdraws continuously in a loop
*/

void* withdrawer(void *arg) 
{
	int lindex = 0;
	int retval = 1;
	while(lindex < LOOPSZ)
	{
		while (retval)
		{
			retval = withdraw(withdrawamount);
		}
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
	rv1 = pthread_create(&tid2,&attr,(void *)withdrawer,NULL);
	if(rv1 != 0)
	{
		printf("\n Cannot create thread");
		exit(0);
	}
	rv1 = pthread_create(&tid1,&attr,(void *)depositor,NULL);
	if(rv1 != 0)
	{
		printf("\n Cannot create thread");
		exit(0);
	}
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return(0);
}
