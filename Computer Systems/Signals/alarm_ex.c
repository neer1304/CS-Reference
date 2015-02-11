
#include<stdio.h>
#include<signal.h>

char user[40]; /* buffer to read user name */

/* Alarm signal Handler */

void catch_alarm(int sig_num)
{
	printf("\nOperation timed out.Exiting\n");
	exit(0);
}

/*	Ctrl-c handler	*/
void sig_handler(int sig_num)
{
	printf("Ctrl-c occured\n");
}
main()
{
	/* set a signal Alarm for handling signals */
	signal(SIGALRM,catch_alarm);
	
	/* Prompt the user for input */
	printf("\nenter the user name:\n");

        alarm(5); /*start 5 seconds alarm */
	scanf("%s",user); /* wait for user input */
//	alarm(0);

	printf("%s\n",user);

}



	


