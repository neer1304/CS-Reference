#include<iostream>
#include<string>
using namespace std;

// Inheritance and access specifier

class Employee 
{
    string name;
    string empId;
public:
    Employee() { }
    Employee(string name_,string empId_)
	: name(name_), empId(empId_) { }
    string getName() const { return name; } 
    string getEmpId() const { return empId; } 
};

class Manager : public Employee 
{
	double allowance;
public:
	Manager() { }
	Manager(string name_,string empId_,double allowance_)
		: Employee(name_,empId_), allowance(allowance_) { }
	double getAllowance() const { return allowance; }
};

int main()
{
    Employee *e1 = new Employee("Nicel","1002");
    Manager *m1 = new Manager("Sulabh","1023",5600);

    cout<<e1->getName()<<"\t"<<e1->getEmpId()<<endl;
    cout<<m1->getName()<<"\t"<<m1->getEmpId()<<"\t"
	<<m1->getAllowance()<<endl;

	delete e1;
	delete m1;
   return 0;
}
