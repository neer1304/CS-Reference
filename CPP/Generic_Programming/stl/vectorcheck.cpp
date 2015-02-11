
#include <iostream.h>
#include <vector.h>
using namespace std;

int main ()
{
     vector<int> v1, v2;
     
     v1.push_back(10);
     v1.push_back(30);

     v2.push_back(20);
     v2.push_back(40);
     //v2.push_back(60);

     if (v1==v2)
     {
         cout<<"vectors are equal";
     }
     else
     {
         cout<<"vectors are not equal";
     }

     v1.swap(v2);

     cout<<endl;
     for (int i =0; i < v1.size() ; i++)
     {
        cout <<"V1="<<v1[i]<<"   ";
        cout <<"V2="<<v2[i]<<"   ";
     }   
     return 0;
}
