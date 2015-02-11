#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


void *parent ();
int cpid, ppid, num = 0;

main ()
{
  int i, status;
  ppid = getpid ();		/*parent's id. */
//  signal (SIGINT, parent);
  if ((cpid = fork ()) != 0)
    {
 
      signal (SIGINT, parent);
      wait (&status);		/*wait for the child to terminate */
      printf ("parent exit %d %d\n", WEXITSTATUS (status), num);
    }
 else
 { 
  	sleep(1);				/*child */
  	printf ("in child\n");
  	for (i = 0; i < 10; i++)
    	{
      	kill (ppid, SIGINT);
      	sleep (1);
    	}
  	exit (20);
 }
}

void *parent (int signo)
{
  printf ("in parent signal\n");
  num++;
}
