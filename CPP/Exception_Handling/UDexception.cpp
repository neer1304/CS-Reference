
#include <iostream>
#include <stdexcept>
using namespace std;

class int_divide_by_zero : public runtime_error
{
  public:
    int_divide_by_zero(const string &int_error_string):
        runtime_error(int_error_string){};
};

class float_divide_by_zero : public runtime_error
{
  public:
    float_divide_by_zero(const string &float_error_string):
        runtime_error(float_error_string){};
};

int divide_int()
{
   cout <<"Enter two int values:" << endl;
   int num, den;

   cin>>num>>den;

   if (den == 0)
      throw int_divide_by_zero("int divide by zero error");
   int res = num/den;

   cout <<"Division result "<<res;
   return res;
}

int divide_float()
{
   cout <<"Enter two float values:" << endl;
   float num, den;

   cin>>num>>den;

   if (den == 0)
      throw float_divide_by_zero("float divide by zero error");
   float res = num/den;

   cout <<"Division result "<<res;
   return res;
}

int main()
{
    try
    {
      divide_int();
      divide_float();
    }

    catch(int_divide_by_zero &int_excep)
    {
        cout << int_excep.what() << endl;
    }

    catch(float_divide_by_zero &float_excep)
    {
        cout << float_excep.what() << endl;
    }

    catch(...)
    {
        cout << "in global catch" << endl;
    }
    return 0;
}
