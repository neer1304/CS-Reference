#include<unistd.h>
#include<sys/types.h>
#include<sys/resource.h>

main()
  {
    pid_t pid;
    int which = PRIO_PROCESS;
    int priority = -10;
    int ret,ret1;

    pid = getpid();
    ret = getpriority(which,pid);
    printf("\nthe return priority from process: %d is: %d\n" ,pid,ret);

    sleep(3);    
    ret1 = setpriority(which,pid,priority);
    sleep(3);
    printf("\nthe return priority from process: %d is: %d\n" ,pid,ret1);
    sleep(3);
    ret = getpriority(which,pid);
    printf("\nthe return priority from process: %d is: %d\n" ,pid,ret);
  }


