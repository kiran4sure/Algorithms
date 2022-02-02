#include "person.h"
#include "chatRoom.h"



    void Person::receive(const string &origin, const string &message)
    {
        string s{ origin + ": \"" + message + "\"" };
        cout << "[" << m_name << "'s chat session] " << s << "\n";
        chatLog.emplace_back(s);
    }
    
    void Person::say(const string &message) const
    {
        room->broadcast(getName(), message);
    }
    
    void Person::pm(const string &to, const string &message) const
    {
        room->message(getName(), to, message);
    }
    
    string Person::getName() const
    {
        return this->m_name;
    }
    
    void Person::setChatRoom(ChatRoom *r)
    {
        this->room = r;
    }
    
    Person::Person(string name)
    :m_name(name)
    {
        
    }