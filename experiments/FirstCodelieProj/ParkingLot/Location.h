#pragma once
#include <iostream>
#include<string>
#include<map>

using namespace std;

class location{
protected:
    int x;
    int y;
    int z;
    std::string type;
    bool occupied;


    location(int x=0, int y=0, int z=0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->occupied = false;
        this->type = "";
    }
    
public:    
    void set_occupied()
    {
        this->occupied = true;
    }
    
    void release_occupied()
    {
        this->occupied = false;
    }
    
    bool isOccupied()
    {
        return this->occupied;
    }
    
    virtual location *get()=0;
};


// class genertor : public location
// {
// public:
//     static location *get();
// }

class car: public location
{
public:
    car(int x=0, int y=0, int z=0)
    :location(x,y,z)
    {
        this->type = "car";
    }
    
    virtual location *get() override
    {
        return new car();
    }
};

class bike: public location
{
public:
    bike(int x=0, int y=0, int z=0)
    :location(x,y,z)
    {
        this->type = "bike";
    }

    
    virtual location *get() override
    {
        return new bike();
    }
};

class bus: public location
{
public:
    bus(int x=0, int y=0, int z=0)
    :location(x,y,z)
    {
        this->type = "bus";
    }
    
    virtual location *get() override
    {
        return new bus();
    }
};


class locationFactory
{
    map<string, location*> lst;
    
public:
    locationFactory()
    {
        lst.clear();
    }
    
    void add(string vech, location *loc)
    {
        lst.insert({vech, loc});
    }
    
    void del(string veh)
    {
        auto result = lst.find(veh);
        if(result != lst.end())
        {
            lst.erase(veh);
        }
    }
    
    location *get(string veh)
    {
        auto result = lst.find(veh);
        if(result != lst.end())
        {
            return (*result).second->get();
        }
        return nullptr;
    }
};

//int main()
//{
//    locationFactory lf;
//    
//    class location *bi = new bike();
//    class location *ca = new car();
//    class location *bu = new bus();
//
//    lf.add("bike",bi);
//    lf.add("car", ca);
//    lf.add("bus", bu);
//    
//    class location* bi1 = lf.get("bike");
//    class location* bi2 = lf.get("bike");
//    class location* ca1 = lf.get("car");
//    class location* bu1 = lf.get("bus");
//    
//    bi1->set_occupied();
//
//    cout << "bi1 occupied = " << bi1->isOccupied() << ", bi2 occupied = " << bi2->isOccupied() << endl;
//    return 0;
//}
