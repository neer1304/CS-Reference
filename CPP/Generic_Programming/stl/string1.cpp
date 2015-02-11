
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str1("Alpha");
  string str2("Beta");
  string str3("Gamma");
  string str4;

  str4 = str1;

  cout <<"String1 = "<<str1<<endl;
  cout <<"String4 = "<<str4<<endl;

  str4 = str1+" to "+ str2;

  cout <<"String1 = "<<str1<<endl;
  cout <<"String2 = "<<str2<<endl;
  cout <<"String4 = "<<str4<<endl;

  if (str3 > str1)
  {
    cout<<"str3 > str1"<<endl;
  }
  else
  {
    cout<<"str3 > str1"<<endl;
  }
  

  if (str3 == (str1 + str2))
  {
    cout<<"str3 = str1 + str2"<<endl;
  }
  else
  {
    cout<<"str3 is not = str1 + str2"<<endl;
  }

  string str5 = "My String";
  cout<<"Str5 = "<<str5<<endl;

  string str6;
  cout<<"Enter String 6:";
  cin>>str6;
  cout<<"Str6 = "<<str6<<endl;

  return 0;
}
