//
// Created by Kirankumar Srikanta on 16/10/20.
//
#include<iostream>

using namespace std;

class base
{
public:
    virtual void print()
    {
        cout << "i am in base" << endl;
    }
};

class derived: public base{
public:
    void print() override
    {
        cout << "i am in derived" << endl;
    }
};

int main()
{
    base *d = new derived();
    d->print();
    derived dd;
    dd.print();
    return 0;
}
