#include<signal.h>

void signal_handler()
  {
     printf("\nchild received signal\n");
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
         //kill(getpid(),SIGINT);
         sleep(5);
         printf("Parent exiting\n");
       }
         kill(getpid(),SIGINT);
   }

     

