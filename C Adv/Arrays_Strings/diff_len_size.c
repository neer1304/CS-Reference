#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  char str1[80] = "PRISM";
  char str2[] = "PRISM";
  char *str3 = "PRISM";

  printf("sizeof(str1)=%d\n", sizeof(str1));
  printf("sizeof(str2)=%d\n", sizeof(str2));
  printf("sizeof(str3)=%d\n", sizeof(str3));

  printf("strlen(str1)=%d\n", strlen(str1));
  printf("strlen(str2)=%d\n", strlen(str2));
  printf("strlen(str3)=%d\n", strlen(str3));
  return 0;
}
