
#include <iostream>
using namespace std;

struct E 
{
  const char* message;
  E(const char* arg) : message(arg) {}
};

void my_unexpected() 
{
  cout << "Call to my_unexpected" << endl;
  throw E("Exception thrown from my_unexpected");
//  throw("Exception thrown from my_unexpected"); ---- terminates even
                                                // handler is there
}

void f() throw(E)
{
  cout << "In function f(), throw const char* object" << endl;
  throw("Exception, type const char*, thrown from f()");
}

int main() 
{

  set_unexpected(my_unexpected);
  try {
    f();
  }

  catch (E& e) 
  {
    cout << "Exception in main(): " << e.message << endl;
  }

  catch (char *s) 
  {
    cout << "Exception in main(): " << s << endl;
  }
  return 0;
}


