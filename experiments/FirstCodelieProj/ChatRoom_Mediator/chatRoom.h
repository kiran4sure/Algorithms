#pragma once
#include "person.h"

struct cmp{
  bool operator()(Person *t1, Person *t2) const
  {
      return t1->getName() < t2->getName();
  }  
};
class ChatRoom
{
//    std::set<Person*, cmp> members;
    std::vector<Person*> members;
public:
    void join(Person *p);
    void broadcast(const string &name, const string &message);
    void message(const string &from, const string &to, const string &message);
};