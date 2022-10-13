#ifndef STATE_HANDLER_H
#define STATE_HANDLER_H

#include "states.h"
//class states;
class state_handler
{
    states *state;
public:
    state_handler();
    ~state_handler();
    
    void set_state(states *s);
    
    void pickup();
    void dial();
    void hangup();
    void redial();

};

#endif // STATE_HANDLER_H
