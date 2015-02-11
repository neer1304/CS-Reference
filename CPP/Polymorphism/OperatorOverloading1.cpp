#include<iostream>
using namespace std;

class Array
{
	int *x;
	int size;
public:
	Array()  { x=0; size=0;}
	Array(int sz) 
	{       size=sz;
		x = new int[size];
		for(int i=0;i<size;++i)
			x[i] = i;
	}
	Array(Array& a) 
	{       size=a.size;
		x = new int[size];
		for(int i=0;i<size;++i)		// deep copy
			x[i] = a.x[i];		
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
				x[i] = a.x[i];		
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
	void negate()
	{
		for(int i=0;i<size;++i)
			x[i] = -x[i];
	}

	int getValue(int index)
	{
		return *(x + index);
	}

	void operator-()
	{
		for(int i=0;i<size;++i)
			x[i] = -x[i];
	}

	int& operator[] (int index)
	{
		return *(x + index);
	}
};

int main()
{
	Array a1(5),a2(4);
        cout<<endl<<"Displaying array A1 "<<endl;
	a1.show();
        cout<<endl<<"Displaying array A2"<<endl;
	a2.show();
	-a1; // a1.operator-();
	a2=a1;
        
        cout<<endl<<"Displaying array A2 after assignment "<<endl;
	a2.show();

	int x = a1[2];
   
        cout<<endl<<"Displaying result of overloaded [] operator x = A1[2] "<<endl;
	cout << x;

	a1[2] = 200;
        cout<<endl<<"Displaying result of overloaded [] operator A1[2] = 200 :"<<endl;
	for (int i = 0; i < 5; i++)
		cout << a1[i] << endl;

        return 0;
}
