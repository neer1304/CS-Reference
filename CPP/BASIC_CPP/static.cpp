
#include <iostream>
using namespace std;

class A
{
   //static int count;
   int x ;
   int y;
  public:
   static int count;
   A() 
   {
     count++;
     cout<<"\nConstructing Object number : " << count <<"\n";
   }
  void display() 
  {

  }
  static void displaystatic()
  {
      cout <<"Display Static function"<<endl;
  }

};

enum color {red = 4, blue, yellow, orange};

const int size = 10;
 
int A::count = 10;

int main()
{

  A a, b , c;
 
  a.display();
  b.display();
  c.display();

  a.displaystatic();

  int x = A::count;

  cout<<" \nNumber of objects : " << x;
  cout<<" \nNumber of objects using object a : " << a.count;

  color background = yellow;

  cout <<"\nColor is :" << background <<"\n";
}
