
#include <iostream>
using namespace std;
#include <cstdlib> // abort function prototype

void customNewHandler()
{
  cerr << "customNewHandler was called";
  abort();
}

int main()
{
 // using set_new_handler to handle failed memory allocation
  double *ptr[ 50 ];
  set_new_handler( customNewHandler );
// allocate memory for ptr[ i ]; customNewHandler will be called on failed memory allocation
  for ( int i = 0; i < 150; i++ ) 
  {
      ptr[ i ] = new double[ 5000000 ];
      cout << "Allocated 5000000 doubles in ptr[ " << i << " ]\n";
  } // end for
return 0;

}

