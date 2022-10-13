#include "state_ringing.h"

state_ringing::state_ringing()
{
}

state_ringing::~state_ringing()
{
}

void state_ringing::dial(state_handler* st)
{
    std::cout <<"cannot dial while ringing" << std::endl;
}
void state_ringing::hang_up(state_handler* st)
{
    std::cout <<"have to pickup to end call" << std::endl;
}
void state_ringing::pickup(state_handler* st)
{
    std::cout <<"picked up the call" << std::endl;
//    st->set_state(new on_call());
}
void state_ringing::redial(state_handler* st)
{
    std::cout <<"cannot redial while ringing" << std::endl;
}
