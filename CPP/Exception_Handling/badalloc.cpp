
#include <iostream>
using namespace std;
using std::bad_alloc;

int main()
{
    double *ptr[50];
    // attempt to allocate memory
    try {
     // allocate memory for ptr[ i ]; new throws bad_alloc on failure
        for ( int i = 0; i < 50; i++ )
        {
             ptr[ i ] = new double[ 5000000 ];
             cout << "Allocated 5000000 doubles in ptr[ " << i << " ]\n";
           	 }
        } // end try
        // handle bad_alloc exception
        catch (bad_alloc &memoryAllocationException)
        {
            cout << "Exception occurred: " << memoryAllocationException.what() << endl;
        } // end catch
        return 0;
}

