#include <ios>
#include<iostream>

using namespace std;

class base 
{
    int a;
public:
    base()
    :a{0}
    {}

    virtual void print()
    {
        cout << "this is from base class" << endl;
        cout << "a = " << a << endl;
    }

    virtual void update(int num)
    {
        a = num;
    }
};



class derived : public base
{
    int a;
public:

   void print() override
   {
       cout << "this is from derived " << endl;
       cout << "a = " << a << endl;
   } 

   void update(int num) override
   {
       a = num*10; 
   }

};

class dderived: public derived
{
    int a;
public:
    void print() override
    {
        cout << "this is from dderived " << endl;
        cout << "a = " << a << endl;
    }

    void update(int num) override
    {
        a = num*100;
    }
};


int main()
{

    base *b;
    b = new dderived();
    b->update(5);
    b->print();
    
    return 0;
}