#ifndef ON_CALL_H
#define ON_CALL_H

#include "states.h" // Base class: states

class on_call : public states
{
public:
    on_call();
    virtual ~on_call();

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

#endif // ON_CALL_H
