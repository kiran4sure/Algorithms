#include <cstdlib>
#include<iostream>
#include <type_traits>

using namespace std;

struct  ll
{
    int data;
    ll *next;
    ll(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

ll *head = nullptr;

// void sort(ll *lst, int len)
// {

//     srt(lst, start, mid, end)
// }

// 1->2->3->4->5->6;

// 1->2->6->4->5->3->null;

void swap(ll *lst, ll *first, ll *second)
{
    ll *head = lst;
    ll *firstp, *secondp;
    firstp = secondp = head;

    if(first == head)
    {
        firstp = head;
    }
    else
    {
    
        while(firstp->next != first)
        {
            firstp = firstp->next;
        }
    }

   while(secondp->next != second)
    {
        secondp = secondp->next;
    }

    ll *temp;
    ll *temp2;
    temp = first->next;
    temp2 = second->next;

    if(firstp !=head)
    {
        firstp->next = second;
    }

    second->next = temp;

    secondp->next = first;
    first->next = temp2;

    head = second;
}



void append(int data)
{
    ll *node = new ll(data);
    if(head == nullptr)
    {
        head = node;
        return;
    }
    ll *temp = head;
    while(temp->next != nullptr)
        temp = temp->next;

    temp->next = node;
}

void print()
{
    ll *temp = head;
    while(temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main()

{
    for(int i=1; i<10; i++)
    {
        append(i);
    }

    print();



}








