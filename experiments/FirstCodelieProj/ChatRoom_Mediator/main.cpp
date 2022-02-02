#include <stdio.h>
#include <vector>
#include <string>
#include <set>

#include "chatRoom.h"
#include "person.h"

using namespace std;

int main(int argc, char **argv)
{
	ChatRoom family;
    
    Person Kiran("Kiran");
    Person Kishor{"Kishor"};
    Person Mom{"Mom"};
    Person Dad{"Dad"};
    Person Prapulla{"Prapulla"};
    Person Priya{"Priya"};
    Person Aarya{"Aarya"};
    
    family.join(&Dad);
    family.join(&Mom);
    family.join(&Kiran);
    family.join(&Kishor);
    family.join(&Priya);
    family.join(&Aarya);
    family.message("Kiran", "Aarya", "Hi...!, what are you doing");
    return 0;
//    family.join(&Mom);
}
