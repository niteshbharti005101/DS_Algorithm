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
        cout << p->data << " ";
        p = p->next;
    }
}
// R E C U R S I V E L Y

int getN(node *head, int n)
{
    if (head == NULL)
        return -1;

    if (n == 0)
        return head->data;

    return getN(head->next, n - 1);
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

    print(arr[0]);

    cout << getN(arr[0], 3) << endl;
}
