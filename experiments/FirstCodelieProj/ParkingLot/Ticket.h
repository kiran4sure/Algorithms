#pragma once
#include<ctime>
#include<string>
#include "Location.h"


class Ticket
{
    std::size_t id;
    std::string vechileNumber;
    std::time_t entry_time;
    std::time_t exit_time;
    std::string type;
    location place;
    std::size_t entryGate;
    std::size_t exitGate;
    
public:
    Ticket();
    
    bool operator==(const Ticket &rhs)
    {
        return ((this->id == rhs.id) && (this->vechileNumber == rhs.vechileNumber));
    }
    
    Ticket *checkIn(std::string vechileNumber, std::string type);
    std::size_t checkOut(Ticket *ticket);
    
};