#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *next;
    int data;

    node();

    node(int x)
    {
        data = x;
        next = NULL;
    }
};
void print(node *p)
{
    while (p != NULL)
    {
        cout << p->data <<" ";
        p = p->next;
    }
}

node *reverse(node *head, int k)
{
    int c = 0, d = 0;
    node *count = head;
    while (c < k)
    {
        count = count->next;
        c++;
    }
    node *current = head, *next, *prev = count;

    while (d < k)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
        d++;
    }

    return prev;
}

int main()
{
    node *arr[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = new node(i);
    }
    for (int i = 0; i < 4; i++)
    {
        arr[i]->next = arr[i + 1];
    }
    node *fred = reverse(arr[0], 3);
    print(fred);
}
