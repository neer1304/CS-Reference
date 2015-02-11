#include<iostream>
using namespace std;

inline int add(int x,int y)
{
    return x + y;
}

inline double add(double x,double y)
{
    return x + y;
}

inline char* add(char* x,char* y)
{
    char *temp = (char*) malloc(strlen(x) + strlen(y) + 1);
    strcpy(temp,x);
    strcat(temp,y);

    return temp;
}

int main()
{
    cout<<endl<<"Calling add (int parms) : "<<endl;
    cout<<add(100,200)<<endl;	

    cout<<"Calling add (string parms) : "<<endl;
    cout<<add("Hello"," World!")<<endl;	

    cout<<"Calling add (double parms) : "<<endl;
    cout<<add(34.45,56.7)<<endl;
    
    return 0;
}
