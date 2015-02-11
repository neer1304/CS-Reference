#include<stdio.h>

void min(int a, int b)
{
   printf("%d\n",a<b?a:b);
}
void max(int a, int b)
{
   printf("%d\n",a>b?a:b);
}


int main()
{ int result;
  void (*fp)(int, int);

  fp = max; //fp=&max;
  fp(10,20);

 return 0;
}
