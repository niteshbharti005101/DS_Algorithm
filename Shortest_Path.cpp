#include <bits/stdc++.h>
#include "BFS_gfg.cpp"
using namespace std;

void shot(vector<int> Adj[], int S, int siz)
{
   bool visited[siz];
   for (int i = 0; i < siz; i++)
   {
      visited[i] = false;
   }

   queue<int> q;
   q.push(S);
   
   int count = -1;

   while (!q.empty())
   {
      int sis = q.size();
      count++;

      for (int i = 0; i < sis; i++)
      {
         int u = q.front();
         q.pop();
         visited[S] = 1;

         cout << count << " ";

         for (int x : Adj[u])
         {
            if (visited[x] == 0)
            {
               visited[x] = 1;

               q.push(x);
            }
         }
      }
   }
}

int main()
{
   int v = 4;
   vector<int> Adj[v];

   add(Adj, 0, 1);
   add(Adj, 0, 2);
   add(Adj, 1, 2);
   add(Adj, 1, 3);
   add(Adj, 2, 3);

   shot(Adj, 0, v);

   return 0;
}