#include<iostream>
using namespace std;

int f1()
{
	cout<<"Inside int f1()"<<endl;

	int x = 10;
	return x;
}

double f1()
{
	cout<<"Inside double f1()"<<endl;

	double x = 10.5;
	return x;
}

int main()
{
	// Error
	int x = f1();

	double y = f1();

	cout<<x<<endl;
	cout<<y<<endl;
        
        return 0;
}

