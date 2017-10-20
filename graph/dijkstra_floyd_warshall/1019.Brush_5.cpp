/***from dust i have come, dust i will be***/

#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>

typedef long long int ll;

#define dbg printf("in\n");
#define nl printf("\n");
#define inf 100000000

using namespace std;

//-------------------------------------------------------------------
struct node
{
	int at, cost;
	node(int a, int c)
	{
		at = a;
		cost = c;
	}
};
//-------------------------------------------------------------------


//-------------------------------------------------------------------
struct edge
{
	int v, w;
	edge(int a, int b)
	{
		v = a;
		w = b;
	}
};
//-------------------------------------------------------------------

bool operator<(node a, node b)
{
	return a.cost>b.cost;
}

class Graph
{
	int *parent, nodes;
	int *dist;
	bool *vis; bool dir;
	vector<edge> *adj;
	priority_queue<node> pq;

public:
	Graph(int n, bool f)
	{
		nodes = n;
		parent = new int[n + 1];
		dist = new int[n + 1];
		vis = new bool[n + 1];
		adj = new vector<edge>[n + 1];
		dir = f;
	}

	void addEdge(int u, int v, int w)
	{
		adj[u].push_back(edge(v, w));

		if (!dir)
			adj[v].push_back(edge(u, w));
	}

	void dijkstra(int s)
	{
		for (int i = 1; i <= nodes; i++)
			dist[i] = inf, vis[i] = 0, parent[i] = -1;

		pq.push(node(s, 0));
		dist[s] = 0;

		while (!pq.empty())
		{
			node u = pq.top();
			pq.pop();

			if (vis[u.at])
				continue;

			for (int i=0;i<adj[u.at].size();i++)
			{
				edge e = adj[u.at][i];
				if (!vis[e.v] && dist[e.v]>dist[u.at] + e.w)
				{
					dist[e.v] = dist[u.at] + e.w;
					pq.push(node(e.v, dist[e.v]));

					parent[e.v] = u.at;
				}
			}

			vis[u.at] = 1;
		}
	}

	void print()
	{
		if (dist[nodes] >= inf)
			printf("Impossible\n");

		else
			printf("%d\n", dist[nodes]);
	}

	~Graph()
	{
		delete[] parent;
		delete[] dist;
		delete[] vis;
		delete[] adj;
	}
};

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m,t;
	int u, v, w;

	scanf("%d", &t);

	j = 1;
	while (t--)
	{
		scanf("%d%d", &n,&m);

		Graph g(n, 0);

		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			g.addEdge(u, v, w);
		}

		g.dijkstra(1);

		printf("Case %d: ", j); j++;
		g.print();

	}

	return 0;
}
