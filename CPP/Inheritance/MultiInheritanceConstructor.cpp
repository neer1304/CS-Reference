#include<iostream>
#include<string>
using namespace std;

// Inheritance and access specifier

class A1
{
    public:
	A1() { cout<<"A1()"<<endl; }
	~A1() { cout<<"~A1()"<<endl; }
};

class A2
{
    public:
	A2() { cout<<"A2()"<<endl; }
	~A2() { cout<<"~A2()"<<endl; }
};

class B : public A1, public A2
{
    public:
	B() { cout<<"B()"<<endl; }
	~B() { cout<<"~B()"<<endl; }
};

int main()
{
    B *b1 = new B;

    delete b1;
}
