#include <bits/stdc++.h>
using namespace std;

int ceck(vector<int> A)
{
   int sum = 0;

   for (int x : A)
      sum += x;

   int l_sum = A[0];

   for (int i = 1; i < A.size(); i++)
   {
      if (l_sum == sum )
         return l_sum;

      l_sum += A[i];
      sum -= A[i-1];
   }
   return -1;
}

int main()
{
   vector<int> v = {3, 4, 8, -9, 20, 6};

   cout << ceck(v);
}