
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main ()
{
     map<string, string> strMap;

     strMap["Sunday"] = "0";
     strMap["Monday"] = "1";
     strMap["Tuesday"] = "2";
     strMap["Wednesday"] = "3";
     strMap["Thursday"] = "4";
     strMap["Friday"] = "5";
     strMap.insert(pair<string, string>("Saturday", "6"));
     
     cout<<endl;

     cout<<"Display the details: ";

     map<string, string>::iterator p;

     cout<<endl;

     for (p = strMap.begin(); p != strMap.end(); p++)
     {
         cout<<"English:"<<p->first;
         cout<<"\t#:"<<p->second;
         cout<<endl;
     }

     cout<<endl;

     return 0; 
}
