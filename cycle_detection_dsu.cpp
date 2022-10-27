#include <iostream>
#include <list>
using namespace std;

class Graph
{
	list<pair<int, int>> l;
	int v;
public:
	Graph(int v)
	{
		this->v = v;
	}

	void addEdge(int x, int y)
	{
		l.push_back(make_pair(x, y));
	}

	int findSet(int i, int parent[])
	{
		if (parent[i] == -1)
		{
			return i;
		}
		return findSet(parent[i], parent);
	}


	void unionSet(int i, int j, int parent[])
	{
		int s1 = findSet(i, parent);
		int s2 = findSet(j, parent);

		if (s1 != s2)
		{
			parent[s2] = s1;
		}
	}


	bool detect_cycle()
	{
		int *parent = new int[v];

		for (int i = 0; i < v; i++)
		{
			parent[i] = -1;
		}


		for (auto edge : l)
		{
			int i = edge.first;
			int j = edge.second;

			int s1 = findSet(i, parent);
			int s2 = findSet(j, parent);

			if (s1 != s2)
			{
				unionSet(i, j, parent);
			}
			else
			{
				cout << "Cycle at " << i << " " << j << "\n";
				return true;
			}
		}

		return false;
	}
};


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);


	cout << g.detect_cycle() << "\n";
}