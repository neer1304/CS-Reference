#include<stdio.h>

int main()

{
  void *p;

  int d=6;

  p=&d;

printf("%d",sizeof(*p));
return 0;

}
