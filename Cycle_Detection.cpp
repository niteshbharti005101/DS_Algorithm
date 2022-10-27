#include <bits/stdc++.h>
#include "BFS_gfg.cpp"
using namespace std;

bool DFS_rec(vector<int> Adj[], int source, int parent, vector<int> visited)
{
   visited[source] = 1;

   for (int x : Adj[source])
   {
      if (visited[x] == false)
      {
         if (DFS_rec(Adj, x, source, visited))
            return true;
      }

      else if (x != parent)     // to check if the visted is its parent or not;
         return true;
   }

   return false;
}

bool check_cycle(vector<int> Adj[], int n)
{
   vector<int> visited(n, 0);

   for (int i = 0; i < n; i++)
   {
      if (visited[i] == false)
      {
         if (DFS_rec(Adj, i, -1, visited))
            return true;
      }

   }
      return false;
   }

   int main()
   {
      int v = 5;
      vector<int> Adj[v];

      add(Adj, 0, 1);
      add(Adj, 1, 2);
      add(Adj, 1, 3);
      add(Adj, 3, 2);
      add(Adj, 2, 4);

      cout << check_cycle(Adj, v);
   }