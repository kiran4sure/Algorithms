#ifndef IDLE_H
#define IDLE_H

#include "states.h" // Base class: states

class idle : public states
{
public:
    idle();
    virtual ~idle();

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

#endif // IDLE_H
