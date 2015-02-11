#include<time.h>
#include<sys/time.h>

void timediff(struct timeval *first,struct timeval *last,struct timeval *res)
 {
   if(last -> tv_usec > first -> tv_usec)
    {
      res -> tv_usec = 1000000 + first -> tv_usec - last -> tv_usec;
      res -> tv_sec = first -> tv_sec - last -> tv_sec - 1;
    }
   else
    {
      res -> tv_usec = first -> tv_usec - last -> tv_usec;
      res -> tv_sec = first -> tv_sec - last -> tv_sec ; 
    }
 }

main()
 {
   int i;
   struct timeval now,later,res;
   
    gettimeofday(&now,NULL);
    printf("\ntime is %d %d \n",now.tv_sec ,now.tv_usec);

    for(i=1;i<10000;i++)
      { 
        printf("\n%d",i);
     }

    gettimeofday(&later,NULL);
    printf("\ntime is %d %d \n",later.tv_sec,later.tv_usec);
    
    timediff(&later,&now,&res);
    printf("\ndifference is %d %d \n",res.tv_sec ,res.tv_usec);
 }
