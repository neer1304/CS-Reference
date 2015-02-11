#include<sys/resource.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

main()
  {

   int which=PRIO_PROCESS;
   pid_t pid;
   int ret;

   pid =getpid();

   printf("\nthe Pid of a process is %d\n",pid);
   sleep(5);
   ret=getpriority(which,pid);
   printf("\nThe nice value of a process is: %d \n",ret);

}
