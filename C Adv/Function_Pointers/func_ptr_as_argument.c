#include<stdio.h>
int max(int a, int b)
{
  return a>b?a:b;
}

int compare(int a, int b, int (*fp)(int, int))
{
  int result = fp(a,b);
  return result;
}

int main()
{ int result;

 result = compare(10, 20, max);
  
 printf("%d\n", result);
 return 0;
}
