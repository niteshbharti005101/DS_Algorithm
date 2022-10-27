#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = 0;
    };
    node(int n, node *add)
    {
        data = n;
        next = add;
    }
};
void print(node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

node *merge(node *first, node *second) 
{
    node *NewHead, *last;

    if (first->data < second->data)
    {
        last = NewHead = first;
        first = first->next;
        last->next = 0;
    }
    else
    {
        last = NewHead = second;
        second = second->next;
        last->next = 0;
    }

    while (first && second)
    {

        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = 0;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = 0;
        }
    }
    if (first)
    {
        last->next = first;
    }
    else if (second)
    {
        last->next = second;
    }

    return NewHead;
}

node *sortList(node *head)
{
    // Base Case if the list has 0 or 1 element it means it is already sorted
    if (!head || !head->next)
        return head;
    node *slow = head;
    node *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Divide the list into two parts (one start with head and other with fast)
    fast = slow->next;
    slow->next = NULL;
    // Merge these List
    return merge(sortList(head), sortList(fast));
}

int main()
{
    node *head1 = new node(5, 0);

    node *head2 = new node(0, head1);

    node *head3 = new node(9, head2);

    node *head4 = new node(1, head3);

    node *hed = sortList(head4);

    print(hed);
}