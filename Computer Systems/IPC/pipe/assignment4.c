#include<stdio.h>
main()
  {
      int pid,fd[2];
      int retval;
      char msg1[]  = "good morning1";
       pipe(fd);
       pid=fork();

        if(pid == 0)
           {		exit(0);
              /*       close(fd[1]);
                    sleep(5);
                     printf("Child terminates\n");*/
          }
       else if(pid>0)
          {
            // close(fd[1]);
	     printf("Parent\n");
             retval=read(fd[0],msg1,14);
             printf("\nValue returned:%d\n",retval);
        }

     }

