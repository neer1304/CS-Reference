#include<iostream>
using namespace std;

inline int area(int x=0,int y=0) //area of a rectangle with 2 dimensions
{
    // by default if no value are specified, then return 0

    return x * y;
}

inline int area(int x)	// of a square requires only one dimension
{
    return x * x;
}

int main()
{
   /* calls first area function */

   cout<<area(100,200)<<endl;	

   /* ambiguous call, uncomment and see compilation errors */

   // cout<<area(34)<<endl;

   return 0;
}

