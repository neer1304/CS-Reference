
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<vector<int> > vI2Matrix;
    vector<int> A, B;
  
    vector<vector<int> >::iterator i2;
    vector<int>::iterator i1;

    A.push_back(10);
    A.push_back(20);
    A.push_back(30);
    B.push_back(100);
    B.push_back(200);
    B.push_back(300);

    vI2Matrix.push_back(A);
    vI2Matrix.push_back(B);
    
    cout<<endl<<"Display Using Iterator"<<endl;
    
    for (i2 = vI2Matrix.begin(); i2 != vI2Matrix.end(); i2++)
    {
       for (i1 = (*i2).begin(); i1 != (*i2).end(); i1++)
       {
           cout<<*i1<<"\t";
       }
       cout<<endl;
    }

   return 0;

}
