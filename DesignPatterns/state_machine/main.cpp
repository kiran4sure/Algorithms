/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, HaskeNode, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void print(Node *head)
{
    while(head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node *reverse(Node *head)
{
    if(head == NULL || head->next ==NULL)
        return head;
        
    Node *prev = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return prev;
}

Node *rev(Node *head, int chunk)
{
    if(head == NULL || chunk == 0)
        return head;
        
//    Node *first = head;
    Node *last = head;
    int cnt = chunk-1;
    while(cnt && last->next)
    {
        cnt--;
        last = last->next;
    }
    
    Node *t = rev(last->next, chunk);
    last->next = NULL;
    reverse(head);
    head->next = t;
    return last;
}

Node *rev_tail(Node *head, int count)
{
    if(head == NULL || count <= 1)
        return head;
    
    Node *last = head;
    int cnt = count-1;
    while(cnt && last->next)
    {
        last = last->next;
        cnt--;
    }
    Node *nxt = last->next;
    last->next =  NULL;
    reverse(head);
    head->next = rev_tail(nxt,count);
    return last;
}

Node *rev_alt(Node *head)
{
    if(!head || head->next == NULL)
        return head;
    
    Node *t = rev_alt(head->next->next);
    Node *last = head->next;
    head->next->next = head;
    head->next = t;
    return last;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    
    print(head);
//    head = reverse(head);
//    print(head);
    head = rev(head, 3);
    print(head);
//    head = rev_alt(head);
//    print(head);
    head = rev_tail(head, 3);
    print(head);

    return 0;
}
