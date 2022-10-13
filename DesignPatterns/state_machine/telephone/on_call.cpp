#include "on_call.h"

on_call::on_call()
{
}

on_call::~on_call()
{
}

void on_call::dial(state_handler* st)
{
    std::cout <<"cannot dial while on call" << std::endl;
}
void on_call::hang_up(state_handler* st)
{
    std::cout <<"Ended call" << std::endl;
//    st->set_state(new idle());
}
void on_call::pickup(state_handler* st)
{
    std::cout << "alreday on call"<< std::endl;
}
void on_call::redial(state_handler* st)
{
    std::cout <<"only one call allowed at a time" << std::endl;
}
