#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
   int data;
   ListNode *next;
   ListNode(){};

   ListNode(int x)
   {
      data = x;
      next = 0;
   };
   ListNode(int n, ListNode *add)
   {
      data = n;
      next = add;
   }

   ListNode *create(int A[], int size)

   {
      ListNode *head = new ListNode(A[0]);
      ListNode *current = NULL;
      for (int i = size - 1; i >= 0; i--)
      {
         ListNode *x = new ListNode(A[i], current);
         current = x;
      }
      head = current;
      return head;
   }
};
class Solution
{
public:
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
   {

      ListNode *A = headA, *B = headB;
      while (A != B)
      {
         A = !A ? headB : A->next;

         B = !B ? headA : B->next;
      }
      return A;
   }
};
int main()
{
   int N1, N2;
   cout << "Enter no. of elementof first List - ";
   cin >> N1;
   cout << "Enter no. of elementof first List - ";
   cin >> N2;

   int A[N1], B[N2];
   for (int i = 0; i < N1; i++)
   {
      cin >> A[i];
   }
   for (int i = 0; i < N2; i++)
   {
      cin >> B[i];
   }

   class ListNode ob1, ob2;

   ListNode *head1 = ob1.create(A, N1);
   ListNode *head2 = ob2.create(B, N2);

   class Solution object;
   ListNode *result = (object.getIntersectionNode(head1, head2));

   cout << result->data;
}