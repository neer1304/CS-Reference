/*
This program demonstrates how endianness impacts C programs
It also shows when a program ceases to be portable due to endianness

The portability issue crops up when a data type is bigger than a byte and 
the machine is byte addressable (say, a 32 bit integer stored as 4 bytes).
In our program, if we split a 32-bit integer in 4 bytes and process these 
bytes individually assuming certain addresses for LSBs and MSBs then 
the program ceases to be portable across platforms.
*/

#include<stdio.h>

void endiannessProblemOne()
{
  int            index   = 0;
  unsigned char  * pChar = NULL;
  unsigned int   * pInt  = NULL;
  unsigned char  intArray[4];

  pInt  = (int *)intArray;
  *pInt = 0x0000ffff;
  printf("value and the address of pInt is %x : %u\n",*pInt, pInt);

  /*
  If you run the program on two different machines; a big endian(e.g., SPARC) 
  and a little endian(e.g., Intel) the program will print different values

  Little Endian Machine : 
  two lower address bytes will have the value 0xff
  two higher address bytes will have the value 0x00

  Big Endian Machine : It will be the opposite of Little Endian Machine
  two higher address bytes will have the value 0xff
  two lower address bytes will have the value 0x00
  */

  for(index=0;index<4;index++)
  {
    printf("value and the address of the integer byte by byte is : %u : %x\n", &intArray[index], intArray[index]);
  }

  /*
  Following conditional statement(if statement) is not portable across 
  platforms , i.e., the result would be different on two different machines; 
  a big endian(e.g., SPARC) and a little endian(e.g., Intel)
  Please run it on different platforms to see the difference
  */

  *pInt = 0x00000fff;
  pChar = (char *)pInt;
  for(index=0;index<=3;index++)
  {
    if (0 != *pChar)
    {
      printf("Value and the address of the byte no %d of the integer %x : %u\n",index, *pChar, pChar);
    }
    pChar++;
  }
}



int main()
{
  endiannessProblemOne();
}
