
#include <iostream>
#include <stdexcept>

using namespace std;

int divide_func()
{
   int num, den;

   cout <<" Enter Numerator and Denominator " <<endl;
   cin >> num >> den;
   if (den == 0)
      throw int();
   int res = num/den;
   cout <<"Division result = "<<res<<endl;
   return res;
}
int main()
{
    cout << "Start" << endl;
    try
    {
      try
      {
        divide_func();
      }
      catch(int int_except)
      {
        cout << " Caught divide_by_zero exception: inner block " <<endl;
        throw;
      }
    }

    catch(int int_excp)
    {
        cout << " Caught divide_by_zero exception: outer block " <<endl;
    }
    
    cout <<"End"<<endl;
    return 0;
}
