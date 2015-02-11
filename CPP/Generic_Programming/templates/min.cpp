
#include <iostream>
#include <string.h>

using namespace std;

template<class T>
T minimum(T a, T b)
{
  cout<<"\nCalls Generic Function: ";
  cout<<"\nA :"<<a;
  cout<<"\nB :"<<b;
  cout<<endl;
  return (a<b)?a:b;
}

char *minimum(char *a, char*b)
{
  cout<<"\nCall Not Generic Function: "<<endl;
  
  if (strcmp(a, b))
     return b;
  else
     return a;
}

int main()
{

  double a=6.7, b = 7.6;
  
  char s1[] = "Hello", s2[] = "Good";

  cout<<minimum(a,b)<<endl;
  cout<<minimum(s1,s2)<<endl;
}

