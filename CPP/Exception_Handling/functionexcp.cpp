
#include <iostream>
#include <stdexcept>

using namespace std;

void f(int i)
{
   cout <<" Inside f, i is : " << i << endl;
   if (i)
      throw i;
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
    
    cout <<"End"<<endl;
    return 0;
}
