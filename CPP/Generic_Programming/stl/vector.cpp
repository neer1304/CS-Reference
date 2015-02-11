
#include <iostream>
#include <vector>
using namespace std;

bool Search(const vector<int> & V, int  item);

int main ( )
{
     vector<int> numbers;
     int number;
     while (cin >> number)      // enter <control> D to stop the loop
     {
          if (Search(numbers, number))
          {
            cout << "Duplicate" << endl;
          }
          else
          {
             numbers.push_back(number);
          }
     }
     cout << "number of unique values: " << numbers.size( );
return 0;
}

bool Search(const vector<int> & V, int  item)
{
     int p = 0;
     while(p < V.size() )
     {
       if (item == V[p])  // or V.at(p)
          return true;
       else p++;
     }
     return false;
}
