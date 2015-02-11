#include<stdio.h>
#include<unistd.h>

int main ()
{
  printf("this is parent before fork\n");
  if (0 == fork ())
  {
  	printf("this is child\n");
  }
  else
  {
	printf("this is parent after fork\n");
  }
  printf("am I parent or child?\n");
  return 0;
}
