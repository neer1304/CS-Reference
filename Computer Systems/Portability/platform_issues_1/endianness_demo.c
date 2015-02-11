#include<stdio.h>
#include<netinet/in.h>

void main()
{
  unsigned char *ptr;
  unsigned char  arry[4];
  unsigned int  *pint;
  unsigned int   val1;
  unsigned int   val2;
  unsigned int   i;

  val1 = 0x12345670;
  val2 = 0x89abcdef;

  pint = (int *)arry;
  *pint = val1;

  ptr = (char *)&val1;
  printf("size of pointer is  %x bytes\n",sizeof(ptr));
  printf("Value of val1 is  %x\n",val1);
  printf("Value of val2 is  %x\n",val2);

  printf("Value of Ptr is %x : %u\n",*ptr, ptr);
  for(i=1;i<4;i++)
  {
    ptr++;
    printf("Value of Ptr is %x : %u\n",*ptr, ptr);
  }
  val2=htonl(*pint);
  ptr = (char *)&val2;
  i = 0;
  printf("Values are %x : %u : %u : %x\n",*ptr, ptr, &arry[i], arry[i]);
  for(i=1;i<4;i++)
  {
    ptr++;
    printf("Values are %x : %u : %u : %x\n",*ptr, ptr, &arry[i], arry[i]);
  }
}
