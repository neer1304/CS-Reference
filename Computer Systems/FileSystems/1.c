#include <stdio.h>

void quiz(int arg)
{
 if(arg >= 1)
 {
  quiz(arg % 2);
  quiz(arg % 2);
 }
 printf("%d\n", arg);
}

int main()
{
 quiz(5);
 return 0;
}

