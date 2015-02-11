#include<stdio.h>
typedef struct s
{
  unsigned int a:1;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int d:4;
  unsigned int e:9;
}s;

int main()
{
  s v;
 unsigned int a;
 printf("Enter a no::");
 scanf("%u", &a);
 
v.a = a;

printf("the value of bit field data is %u\n", v.a);
return 0;
}
