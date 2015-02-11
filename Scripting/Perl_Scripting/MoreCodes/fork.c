/***************************************************************************
*	FILENAME : fork.c
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of fork call
*	Invoke the Executable as a.out
****************************************************************************/

#include<sys/types.h>
#include<stdio.h>

int global =10; /*A variable which will be modified by the parent/child*/

main()
{
	int var = 12 ;/*Local variable to be used bt the parent & child*/
	pid_t pid;/*Stores the return value of fork*/

	printf("Before fork\n");
	if ((pid = fork())<0)
	{
		printf("Error in Forking \n");
		exit(1);
	}
	else if (pid == 0) /*Child Executing */
	{
		global++;var++;
		printf("Newly created child with Id =%d, My Parent's Pid =%d\n",
				getpid(),getppid());
	}
	else /*Parent Executing*/
	{
		printf("MY Child's PID =%d,My Id =%d\n",pid,getpid());
		printf("MY Parent's Id  =%d,My Id =%d\n",getppid(),getpid());
	}
	/*The following code will be executed both by  parent & child*/
	printf("My Process Id  =%d , val of global  =%d , val of local =%d\n",
		getpid(),global,var);
	exit(0);
	//C++ Comment1
	//C++ Comment2
	/*Another C Comment*/

}
	

