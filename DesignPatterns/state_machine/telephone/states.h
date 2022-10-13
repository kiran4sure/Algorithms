#ifndef STATES_H
#define STATES_H
#include<iostream>
class state_handler;
//#include "state_handler.h"
using namespace std;

class states
{
public:
    states();
   virtual ~states();
    
//    virtual void pickup(state_handler *st);
//    virtual void dial(state_handler *st);
//    virtual void hang_up(state_handler *st);
//    virtual void redial(state_handler *st);
    
    virtual void pickup(state_handler *st)
    {
        cout << "exp" << endl;
    }
    virtual void dial(state_handler *st)
    {
        cout << "exp" << endl;
    }
    virtual void hang_up(state_handler *st)
    {
        cout << "exp" << endl;
    }
    virtual void redial(state_handler *st)
    {
        cout << "exp" << endl;
    }

};

    

#endif // STATES_H
