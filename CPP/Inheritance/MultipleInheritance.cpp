#include<iostream>
#include<string>
using namespace std;

class A1
{
    int x[100];
};

class A2 : public A1
{
    int y;
};

class A3 : public A1
{
    int z;
};

class B : public A2, public A3
{
};

int main()
{
    B *b1 = new B;

    cout<<sizeof(A1)<<endl;
    cout<<sizeof(A2)<<endl;
    cout<<sizeof(A3)<<endl;
    cout<<sizeof(B)<<endl;

    delete b1;
    return 0;
}
