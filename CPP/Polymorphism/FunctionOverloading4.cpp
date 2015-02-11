#include<iostream>
using namespace std;

inline int area(int x=0,int y=0) //area of a rectangle 2 with dimension
{
    // by default if no values are specified, then return 0

    if(x!=0 && y==0)
	return x * x;

    return x * y;
}

int main()
{
   cout<<area(100,200)<<endl;	
   cout<<area(34)<<endl;		
   
   return 0;
}
