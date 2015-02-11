
#include <iostream>
#include <exception>
using namespace std;
void termfunction()
{
   cout << "I'll be back." << endl;
   abort();
}

int main( )
{
   terminate_handler oldHand = set_terminate(termfunction);
   // Throwing an unhandled exception would also terminate the program
   throw bad_alloc();

   // The program could also be explicitely terminated with:
   // terminate( );
  return 0;
}

