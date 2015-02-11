#include<iostream>

using namespace std;

template<typename X>
void bubble(X *array, int array_size)
{  
   X temp_var;
    int i, j;
    for ( i = 0; i < array_size; i++)
        { for(j = 1; j <(array_size-i); j++)
          {   if (array[j] < array[j - 1])
             {      temp_var = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = temp_var;
             }
           }
         }
}

int main()
{
   int iarray[7] = {10, 8, 9, 5, 6, 2, 4};
   double darray[7] = {4.3, 3.88, 10.9, 6.5, 7.6, 2.2, 3.4};

   cout<<"\nUnsorted Integer array is:"<<endl;
   for (int i=0; i<7; i++)
   {
      cout<<iarray[i]<<" ";
   }
   cout<<endl;
   bubble(iarray, 7);

   cout<<"\nSorted Integer Array is:"<<endl;
   for (int i=0; i<7; i++)
   {
      cout<<iarray[i]<<" ";
   }
   cout<<endl;

   cout<<"\nUnsorted double array is:"<<endl;
   for (int i=0; i<7; i++)
   {
      cout<<darray[i]<<" ";
   }
   cout<<endl;
   bubble(darray, 7);

   cout<<"\nSorted double Array is:"<<endl;
   for (int i=0; i<7; i++)
   {
      cout<<darray[i]<<" ";
   }
   cout<<endl;

   return 0;
}
