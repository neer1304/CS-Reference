#include<iostream>

using namespace std;

class A
{
public:
	void f1() { cout<<"A.f1()"<<endl; }
	void f2() { cout<<"A.f2()"<<endl; }
	void f3() { cout<<"A.f3()"<<endl; }

	A* operator->()
	{
		return this;
	}
};

// operator ->

void demo2(A &obj)
{
	obj->f1();
	obj->f2();
}

void demo(A &obj)
{
	obj->f1();		
	obj->f2();		// (*(obj.operator->())).f2();
	obj->f3();

	demo2(obj);
}

int main()
{
	A a1;	// = new A;

	demo(a1);
        
        return 0;
}


