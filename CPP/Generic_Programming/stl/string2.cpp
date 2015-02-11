
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S1("12345");
  string S2("ABCDE");

  bool b1 = 5;

  cout <<"Bool1 = "<<b1<<endl;
  cout <<"S1 = "<<S1<<endl;
  cout <<"S2 = "<<S2<<endl;

  cout <<"Insert S2 inside S1 "<<endl;

  S1.insert(3, S2);
  cout <<"S1 = "<<S1<<endl;


  cout <<"Removing Chars from S1 "<<endl;

  S1.erase(4, 4);
  cout <<"S1 = "<<S1<<endl;

  cout <<"Replace Chars from S1 "<<endl;

  S1.replace(2,3 , "HELLO");
  cout <<"S1 = "<<S1<<endl;


  int len = S1.length();

  for (int i=0; i<len;++i)
  {
     cout<<S1.at(i);
  }

  cout<<endl;

  return 0;
}
