#include<stdio.h>

typedef void (*fp1) (int, int);

void min(int a, int b)
{
   printf("%d\n",a<b?a:b);
}

fp1 max(int a, int b)
{
   printf("%d\n",a>b?a:b);
   return min;
}

int main()
{ 
  
   fp1 (*fp_max)(int, int); //fun ptr to max
   
   void (*fp_min)(int, int); //fun ptr to min

  fp_max = &max; //fp=&max;
  fp_min =&min;
  
 //  fp_min = fp_max(10,20);  //calls max
    fp_max(10,20);
 
   fp_min(10,20);   //calls min

 return 0;
}
