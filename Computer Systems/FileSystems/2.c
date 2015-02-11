#include<stdio.h>
void str_fun(void)
{
  static char *str = "PRISM";
  str_fun();
  if(*str == '\0')
  {
    return;
  }
  else
  {
   str++;
   printf("%c\n", *str);
  }
}

int main(void)
{
  str_fun();
  return 0;
} 
