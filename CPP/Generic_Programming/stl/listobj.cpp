#include <iostream>
#include <list>
#include <string>
using namespace std;

class Person
{
  private:
   string name;
   int age;

  public:
    Person(string inName, int inAge)
    {
       name = inName;
       age = inAge;
    }
    string& getName()
    {
      return name;
    }
    int getAge()
    {
        return age;
    }
    bool operator==(const Person& p)
    {
        return (name == p.name);
    }
    bool operator < (const Person& p)
    {
        return (age == p.age);
    }
};


void populatePeople(list<Person>& peopleList)
{
  char c = 'y';
  string name;
  int age;

  while(c == 'y')
  {
    cout<<"\nEnter Name: ";
    cin>>name;

    cout<<"\nEnter age: ";
    cin>>age;

    Person p(name, age);

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
         cout<<(*i).getName()<<"\t"<<(*i).getAge();
         cout<<endl;
     }
 
     L.sort();

     cout<<endl;

     cout<<"Display the Sorted List\n";

     for (i = L.begin(); i != L.end(); i++)
     {
         cout<<(*i).getName()<<"\t"<<(*i).getAge();
         cout<<endl;
     }

     cout<<endl;

     return 0; 
}
