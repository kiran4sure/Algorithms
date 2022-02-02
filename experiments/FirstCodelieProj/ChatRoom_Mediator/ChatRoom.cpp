#include "person.h"
#include "chatRoom.h"

void ChatRoom::join(Person *p)
{
//    this->members.insert(p);
    this->members.push_back(p);
    string join_msg = p->getName() + " joins the chat";
    p->setChatRoom(this);
    broadcast("ChatRoom", join_msg);
}

void ChatRoom::broadcast(const string &name, const string &message)
{
    for(auto p: this->members)
    {
        if(p->getName() != name)
            p->receive(name, message);
    }
}


void ChatRoom::message(const string &from, const string &to, const string &message)
{
//    std::set<Person*>::iterator t;
//    auto target = lower_bound(begin(members), end(members), [&](const Person* p) { return p->getName() < to; });
    auto target = find_if(begin(members), end(members), [&](const Person* p) { return p->getName() == to; });
//    if((*target)->getName() == to)
//        (*target)->receive(from, to);
//    auto iterator = this->members.find(to);
    if(target != this->members.end())
        (*target)->receive(from, message);

// 9/40 ==> covid rate
}