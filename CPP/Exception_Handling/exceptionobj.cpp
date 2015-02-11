#include <iostream>
#include <stdexcept>

using namespace std;
int main()
{
    int val;
    cout << " enter 1 - runtime_exception, 2 - simple exception" << endl;
    cin >> val;
    try
    {
      if(val == 1)
         throw runtime_error("error occured");// object of runtime_error 
      if(val == 2)
         throw exception();   // object of exception base class thrown
    }

/*    catch(exception& excep)
    {
        cout << "in excep class catch" << endl;
    }*/
    catch(runtime_error & rerror)
    {
        cout << "in runtime catch" << endl;
    }
    catch(exception& excep)
    {
        cout << "in excep class catch" << endl;
    }
    catch(...)
    {
        cout << "in global catch" << endl;
    }
    return 0;
}
