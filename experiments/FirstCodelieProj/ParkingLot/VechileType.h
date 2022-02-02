#pragma once
#include<set>
#include<string>

class VechileType
{
public:
    virtual std::set<std::string> vechileTypes() = 0;
};