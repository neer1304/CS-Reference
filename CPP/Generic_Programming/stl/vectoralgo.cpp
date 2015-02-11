
#include <iostream.h>
#include <vector.h>
#include <algorithm>

using namespace std;

int main ()
{
     vector<int> V;
     int number;
     while (cin >> number)      // enter <control> D to stop the loop
     {
          if (find(V.begin(), V.end(), number) != V.end())
          {
            cout << "Duplicate" << endl;
          }
          else
          {
             V.push_back(number);
          }
     }
     cout << endl << "Number of unique values: " << V.size( );

     cout << endl << "Display vector contents:\t";

     vector<int>::iterator i;

     for (i = V.begin(); i != V.end(); i++)
     {
        cout<<*i<<"\t";
     }
     
     cout<<endl;

     sort(V.begin(), V.end());

     cout << endl << "Display vector After Sorting:\t";

     for (i = V.begin(); i != V.end(); i++)
     {
        cout<<*i<<"\t";
     }
     
     return 0;

}
