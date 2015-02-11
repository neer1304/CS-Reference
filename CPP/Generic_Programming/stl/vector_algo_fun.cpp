
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib>

using namespace std;

void set(int& val);
void display(int val);

int main ()
{
     vector<int> V(5);

     for_each(V.begin(), V.end(), set);

     cout<<endl;

     for_each(V.begin(), V.end(), display);
     
     cout<<endl;

     sort(V.begin(), V.end());

     for_each(V.begin(), V.end(), display);
     
     cout<<endl;

     return 0;

}

void set(int& val)
{
   val = rand();
}

void display(int val)
{
  cout<<val<<"\t";
}
