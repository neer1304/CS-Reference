
#include <iostream>
#include <list>
using namespace std;

int main ( )
{
     list<int> L;

     L.push_back(7);
     L.push_back(12);
     L.push_back(5);
     L.push_front(11);
     L.push_back(17);
     L.push_back(10);

     list<int>::iterator i;

     cout<<endl;

     cout<<"Display the List\t";

     for (i = L.begin(); i != L.end(); i++)
     {
         cout<<*i<<"\t";
     }
 
     L.sort();

     cout<<endl;

     cout<<"Display the Sorted List\t";

     for (i = L.begin(); i != L.end(); i++)
     {
         cout<<*i<<"\t";
     }

     cout<<endl;

     return 0; 
}
