
#include <iostream>

using namespace std;
class distance_meters;

class distance_feet
{
    private:
    int ft;
    int inch;

    public:
    void get_distance();
    void set_distance(int , int );
    distance_meters sum(distance_meters dm);
};

class distance_meters
{
    private:
    int mt;
    int cm;

    public:
    void get_distance();
    void set_distance(int , int );
//    friend class distance_feet;
    friend distance_meters distance_feet::sum(distance_meters dm);
};

void distance_meters::set_distance(int m, int c)
{
    mt = m;
    cm = c;
}

void distance_meters::get_distance( )
{

    cout<<"Meters ="<<mt<<endl;
    cout<<"centimeters ="<<cm<<endl;
}

void distance_feet::set_distance(int f, int i)
{
    ft = f;
    inch = i;
}

void distance_feet::get_distance( )
{

    cout<<"Feet ="<<ft<<endl;
    cout<<"inch ="<<inch<<endl;

}

distance_meters distance_feet::sum(distance_meters dm)
{

    distance_meters temp;

    temp.mt = dm.mt + (ft*12*2.54)/100;
    temp.cm = dm.cm + (inch*2.54);

    return temp;
}


int main()
{
    distance_meters dm;
    distance_feet df;

  
    df.set_distance(100,10);
    df.get_distance();


    dm.set_distance(10,20);
    dm.get_distance();

    dm = df.sum(dm);


    cout<<"After addition.............."<<endl;
    
    dm.get_distance();
    return 0;
}
