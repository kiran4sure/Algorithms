#ifndef STATE_RINGING_H
#define STATE_RINGING_H

#include "states.h" // Base class: states

class state_ringing : public states
{
public:
    state_ringing();
    ~state_ringing();

public:
    virtual
void dial(state_handler* st);
    virtual
void hang_up(state_handler* st);
    virtual
void pickup(state_handler* st);
    virtual
void redial(state_handler* st);
};

#endif // STATE_RINGING_H
