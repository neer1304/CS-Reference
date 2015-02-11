#include<iostream>
#include<string>
using namespace std;

// Inheritance and access specifier

class A
{
};

class B : public A
{
};

int main()
{
    A a1;
    B b1;

    // Objects on the Stack
    a1 = b1;		// up-casting allowed

    //b1 = a1;		// down-casting disallowed

    // Objects on the Heap
    A *a2 = new A;
    B *b2 = new B;

    a2 = b2;		// up-casting allowed

    //b2 = a2;		// down-casting disallowed
}
