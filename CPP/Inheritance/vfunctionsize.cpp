/***********************************************************************
**
*
*  FILE NAME    : vfunctionsize.cpp
*
*  DESCRIPTION  : Demonstrates Size of virtual function
*
*
* *****************************
**/
#include <iostream>

using namespace std;

class point
{
   int x, y;

 public:
   
    point(int, int);
    ~point();
};

class pointvf
{
   int x, y;

 public:
   
    pointvf(int, int);
    virtual ~pointvf();
};

int main()
{

  printf("\nSize of object without VF %d", sizeof(point));
  printf("\nSize of object with VF %d", sizeof(pointvf));

  return 0;
}
