
#include <iostream>
using namespace std;
class A
{
   public:
     int a, b;
     A(){ }
     A(int i, int j) {a = i; b = j;}
     void display()
     {
        cout<<"\nI am in A\n";
     }
};

int main()
{
   A obj(10, 20);
   A ojha(40, 420);

   int A::*ptr ;

   ptr = &A::a;

   cout<<endl<<"Printing member  a through pointer obj "<<obj.*ptr;
   cout<<endl<<"Printing member  a through pointer ojha "<<ojha.*ptr;

   void (A::*f_ptr)() = &A::display;

   (obj.*f_ptr)();

   ptr = &A::b;

   cout<<endl<<"Printing member  b through pointer "<<obj.*ptr;

}
