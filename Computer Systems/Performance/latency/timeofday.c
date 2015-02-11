#include<time.h>
#include<sys/time.h>

main()
{
struct timeval t;
printf("\nthe time is %d\n",time(NULL));
gettimeofday(&t,NULL);
printf("\nthe time is %d %d \n",t.tv_sec,t.tv_usec);
}
