
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Person
{
  private:
   int age;

  public:
    Person(int inAge)
    {
       age = inAge;
    }
    int getAge()
    {
        return age;
    }
    bool operator < (const Person& p)
    {
        return (age == p.age);
    }
};


void populatePeople(list<Person>& peopleList)
{
  char c = 'y';
  int age;

  while(c == 'y')
  {

    cout<<"\nEnter age: ";
    cin>>age;

    Person p(age);

    peopleList.push_back(p);

    cout<<"Enter y to add another";
    cin.get();
    c = cin.get();
    cin.get();

  }
}

int main ( )
{

     list<Person> L;
     list<Person>::iterator i;

     populatePeople(L);

     cout<<endl;

     cout<<"Display the List\n";

     for (i = L.begin(); i != L.end(); i++)
     {
         cout<< (*i).getAge();
         cout<<endl;
     }
 
     L.sort();

     cout<<endl;

     cout<<"Display the Sorted List\n";

     for (i = L.begin(); i != L.end(); i++)
     {
         cout<< (*i).getAge();
         cout<<endl;
     }

     cout<<endl;

     return 0; 
}
