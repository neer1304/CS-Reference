
#include <iostream>
using namespace std;

int divide_func()
{
    int num, den;
    cin >> num >> den;
     if(den == 0)
        throw int();  // throw exception
    int res = num/den;
    cout << "division result = " << res << endl;
    return res;
}
int main()
{
    try
    {
        try
        {
            divide_func();
        }
        catch (float float_excep) // catch for float , int not caught!
        {
            cout << "caught divide_by_zero exception : inner block" << endl;
        }
    }
    catch (int int_excep) // int exception gets caught here !!
    {
            cout << "caught divide_by_zero exception : outer block" << endl;
    }
    return 0;
}
