/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, HaskeNode, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
#include "state_handler.h"

int main()
{
    state_handler *st = new state_handler();
    st->dial();
//    st.hangup();
    st->pickup();
    st->redial();
    st->hangup();
    st->dial();
    return 0;
}
