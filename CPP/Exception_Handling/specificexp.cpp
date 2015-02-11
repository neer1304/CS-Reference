
#include <iostream>
#include <stdexcept>

using namespace std;

void f(int i) throw(int, char, double)
//void f(int i) throw()
{
   double d = 7.9;
   cout <<" Inside f, i is : " << i << endl;
   if (i)
      throw i;
   else
      throw d;
}
int main()
{
    cout << "Start" << endl;
    try
    {
      cout << " Inside try block " <<endl;
      f(0);
      f(1);
      f(3);
    }

    catch(int i)
    {
        cout << "Caught an exception: value is " << i << endl;
    }
    
    catch(double d)
    {
        cout << "Caught an exception: double value is " << d << endl;
    }

    cout <<"End"<<endl;
    return 0;
}
