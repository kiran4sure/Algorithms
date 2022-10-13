#include "state_handler.h"
#include "state_ringing.h"
//class states;
state_handler::state_handler()
{
    this->state = new state_ringing();
}

state_handler::~state_handler()
{
}

void state_handler::set_state(states *s)
{
    this->state = s;
}

void state_handler::pickup()
{
    this->state->pickup(this);
}

void state_handler::dial()
{
    this->state->dial(this);
}

void state_handler::hangup()
{
    this->state->hang_up(this);
}

void state_handler::redial()
{
    this->state->redial(this);
}