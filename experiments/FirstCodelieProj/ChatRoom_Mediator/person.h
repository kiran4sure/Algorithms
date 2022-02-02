#pragma once

#include<bits/stdc++.h>
#include<string>

using namespace std;

class ChatRoom;

class Person
{
    std::vector<string> chatLog;
    std::string m_name;
    ChatRoom *room = nullptr;
public:
    Person(string name);
    Person(const Person &p) = default;
    Person(Person &&p) = default;
//    :m_name(name)
//    {
//        
//    }
    
    void receive(const string &origin, const string &message);
    void say(const string &message) const;
    void pm(const string &to, const string &message) const;
    string getName() const;
    void setChatRoom(ChatRoom *r);
    
  friend bool operator==(const Person& lhs, const Person& rhs)
  {
    return lhs.m_name == rhs.m_name;
  }

  friend bool operator!=(const Person& lhs, const Person& rhs)
  {
    return !(lhs == rhs);
  }
};
