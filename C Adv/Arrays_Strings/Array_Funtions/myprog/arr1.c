#include<stdio.h>

void func(int *x, int num)
{
     printf("sizeof(x)=%d\n", sizeof(x)); // Q: what is output?
     x++; // Q: is it valid?
}


int main()
{
int arr[100]={0};
func(arr,100);
return 0;
}
