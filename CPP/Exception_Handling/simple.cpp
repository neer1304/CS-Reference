#include <iostream>
#include <stdexcept>

using namespace std;
int main()
{
    cout <<" Start" << endl;

    try
    {
      cout <<" Inside Try block" << endl;

      throw 1; 

      cout <<"  This will not execute " << endl;

    }

    catch(int i)
    {
        cout << " Caught an Exception - value is " << i << endl;
    }

    catch(int i)
    {
        cout << " IInd Catch Caught an Exception - value is " << i << endl;
    }

    cout << "End" << endl;

    return 0;
}
