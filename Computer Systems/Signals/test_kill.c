#include<signal.h>

void signal_handler()
  {
     printf("\nsignal handler called\n");
  }

main()
  {
    int pid;
    signal(SIGINT,signal_handler);
    pid=fork();
    
    if(pid==0)
      {
    //    signal(SIGINT,signal_handler);
        sleep(2);
      }
     else
       {
        kill(pid,SIGINT);//send signal to child
                          // kill(gepid(),SIGINT); //send signal to parent
         sleep(5);
         printf("Parent exiting\n");
       }
	 printf("The pid is %d and ppid is %d\n",getpid(),getppid());
         kill(getppid(),SIGINT);
   }

     

