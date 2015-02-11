
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    vector<int> A, B;
  
    vector<int>::iterator i1;

    A.push_back(70);
    A.push_back(20);
    A.push_back(50);
    A.push_back(30);
    A.push_back(60);
    A.push_back(10);
    A.push_back(80);


    sort(A.begin(), A.end(), greater<int>());
    
       for (i1 = A.begin(); i1 != A.end(); i1++)
       {
           cout<<*i1<<"\t";
       }
       cout<<endl;

    sort(A.begin(), A.end(), less<int>());
       for (i1 = A.begin(); i1 != A.end(); i1++)
       {
           cout<<*i1<<"\t";
       }
       cout<<endl;

   return 0;

}
