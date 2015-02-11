/***********************************************************************
**
*
*  FILE NAME    : OperatorParentheis.cpp
*
*  DESCRIPTION  : Demonstrates Operator Overloading using (), [], ++ 
*                 operators
*
* ************************************************************************
**/
#include<iostream>
#include<stdlib.h>

using namespace std;

class Array
{
	int *x;
	int size;
public:
	Array() : x(0), size(0) {}
	Array(int sz) : size(sz)
	{
		x = new int[size];
		for(int i=0;i<size;++i)
			x[i] = rand()%size;
	}
	Array(Array& a) : size(a.size)
	{
		x = new int[size];
		for(int i=0;i<size;++i)		// deep copy
			x[i] = a[i];		
	}
	Array& operator=(Array &a)
	{
		if(&a==this)
			;				// do nothing
		else
		{
			if(size!=0) this->~Array();

			size = a.size;
			x = new int[size];
			for(int i=0;i<size;++i)		// deep copy
				x[i] = a[i];		
		}
		
		return *this;
	}
	~Array()
	{
		delete[] x;
		x = NULL;
		size = 0;
	}
	void show()
	{
		for(int i=0;i<size;++i)
			cout<<x[i]<<"\t";
		cout<<endl;
	}
	int& operator[](int index)
	{
		return x[index];
	}
	Array& operator++()		// prefix
	{
		for(int i=0;i<size;++i)
			++x[i];
		return *this;
	}
	Array& operator()(int size_)
	{
		this->~Array();

		size = size_;
		x = new int[size];
		for(int i=0;i<size;++i)
			x[i] = rand()%size;
		return *this;
	}
};

// operator ()

int main()
{
	Array a1(5);
		

        cout<<endl<<"Display array A1 :"<<endl;
	a1.show();

	++a1;

        cout<<endl<<"Display array A1 after preincrement :"<<endl;
	a1.show();

	a1(10);				// On-demand construction

        cout<<endl<<"Display array A1 after parenthesis operator :"<<endl;
	a1.show();

        return 0;
}
