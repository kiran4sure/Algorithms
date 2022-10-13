#include "idle.h"

idle::idle()
{
}

idle::~idle()
{
}

void idle::dial(state_handler* st)
{
    std::cout << "First have to pickup the phone" << std::endl;
}
void idle::hang_up(state_handler* st)
{
    std::cout <<"phone is already in idle" << std::endl;
}
void idle::pickup(state_handler* st)
{
    std::cout <<"picked up the phone" << std::endl;
}
void idle::redial(state_handler* st)
{
    std::cout <<"cannot redial or dial, first pick up the phone" << std::endl;
}
