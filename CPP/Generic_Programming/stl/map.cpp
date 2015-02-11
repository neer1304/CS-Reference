#include <iostream>
#include <map>
#include <string>
using namespace std;

int main ()
{
     map<string, int> phoneMap;

/*     phoneMap["Anil"] = 88888;
     phoneMap["Vikas"] = 44444;
     phoneMap["Raj"] = 66666;
     phoneMap["Lara"] = 55555;
     phoneMap["Sanjay"] = 77777;
     phoneMap["Charlie"] = 33333;
     phoneMap["Anil"] = 22222;
*/   
     phoneMap.insert(pair<string, int> ("Anil", 888888));
     phoneMap.insert(pair<string, int> ("Vikas", 44444));
     phoneMap.insert(pair<string, int> ("Raj", 66666));
     phoneMap.insert(pair<string, int> ("Lara", 55555));
     phoneMap.insert(pair<string, int> ("Sanjay", 77777));
     phoneMap.insert(pair<string, int> ("Charlie", 33333));
     phoneMap.insert(pair<string, int> ("Anil", 11111));
     phoneMap.insert(pair<string, int> ("Anil", 66666));
     phoneMap.insert(pair<string, int> ("Charlie", 66666));

     cout<<endl;

     cout<<"Enter the name of person to search: ";
     string name;
     cin >> name;
 

     if (phoneMap.find(name) != phoneMap.end())
        cout<<endl<<"Phone number for "<<name <<" is "<< phoneMap[name];
     else
        cout<<endl<<"Phone number for "<<name <<" not found ";
   
     cout<<"No of elements of Name " <<name <<" are " << phoneMap.count("Anil");

     cout<<endl;

     return 0; 
}
