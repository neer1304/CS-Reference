/***********************************************************************
**
*
*  FILE NAME    : specialization.cpp
*
*  DESCRIPTION  : Demonstrates class templates along with classes with
*                 partial and full specialization
*
*  */
#include <iostream>

using namespace std;

template <class T1, class T2> 
class check
{
    T1 x;
    T2 y;

 public:
    
    void getdata ()
    {
       cout <<"\nIn getdata full specialization";
       cout << endl;
    }
};

template <class T1> 
class check<T1, int>
{
    T1  x;
    int y;

 public:
    
    void getdata ()
    {
       cout <<"\nIn getdata partial specialization";
       cout << endl;
    }
};

template <> 
class check<int, int>
{
    int x;
    int y;

 public:
    
    void getdata ()
    {
       cout <<"\nIn getdata no template param ";
       cout << endl;
    }
};

int main()
{

    check<char, char> C1;
    check<int, float> C2;
    check<int, int> C3;
  
    C1.getdata();
    C2.getdata();
    C3.getdata();

    return 0; 
}
