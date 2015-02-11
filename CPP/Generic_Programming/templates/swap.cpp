
#include <iostream>

using namespace std;

template <class T> 
void Swap(T & first, T & second) {
     T temp = first;
     first = second;
     second = temp;
}

int main()
{
   int x = 10, y = 20;
   float a = 5.3, b = 7.8;


   cout<<"\n Before Swap: x = "<<x<<" and y = "<<y;
   swap(x, y);
   cout<<"\n After Swap: x = "<<x<<" and y = "<<y;

   cout<<"\n Before Swap: a = "<<a<<" and b = "<<b;
   swap(a, b);
   cout<<"\n After Swap: a = "<<a<<" and b = "<<b;

   cout<<"\n";

   return 0;
}
