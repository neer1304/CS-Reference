#include<stdio.h>
#include<errno.h>
#include<sys/resource.h>
#include<signal.h>

int retnice;

main()
  {
    int pid,retnice;
      
    retnice=nice(1);
    pid =fork();
    for(;;)
      {
        if(pid == 0)
           {
             
               printf("\nchild gets the CPU Priority %d\n",retnice);
               sleep(1);
           }
        else
          {  retnice =nice(-3); 
            printf("\nParent gets CPU Priority %d\n",retnice);
            sleep(1);
          }
      }
  }
 
