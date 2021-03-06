#define _CRT_SECURE_NO_WARNINGS

/***from dust i have come, dust i will be***/

#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n");
#define nl printf("\n");
#define N 100005
#define inf 100000000
#define pp pair<int,int>

using namespace std;

class graph
{
	int n, t;
	int **res, **capacity, *parent;
	bool *vis;

public:
	graph(int n)
	{
		this->n = n;

		t = 2 * n + 2;

		//residual capacity
		res = new int*[t];
		for (int i = 0; i < t; i++)
			res[i] = new int[t];


		//capacity
		capacity = new int*[t];
		for (int i = 0; i < t; i++)
			capacity[i] = new int[t];

		for (int i = 0; i < t; i++)
		{
			for (int j = 0; j < t; j++)
				capacity[i][j] = 0;
		}


		//parent
		parent = new int[t];


		//visited or not
		vis = new bool[t];
	}

	void addReg(int u,int w)
	{
		capacity[u][n + u] = w;
	}

	void addEdge(int u, int v, int w)
	{
		capacity[u+n][v] = w;
	}

	void supers(int u, int v)
	{
		capacity[u][v] = inf;
	}

	bool bfs()
	{
		for (int i = 0; i <t; i++)
			vis[i] = 0;

		queue<int> q;

		vis[0] = 1;
		q.push(0);
		parent[0] = -1;

		while (!q.empty())
		{
			int u = q.front();
			q.pop();

			for (int v = 0; v <t; v++)
			{
				if (!vis[v] && res[u][v] > 0)
				{
					parent[v] = u;
					vis[v] = 1;
					q.push(v);
				}
			}
		}

		return vis[t-1];
	}

	int fordFulkerson()
	{
		//initially residual capacity is equal to the actual capacity
		for (int i = 0; i <t; i++)
		{
			for (int j = 0; j <t; j++)
				res[i][j] = capacity[i][j];
		}

		int flow = 0;
		int minFlow;
		int u, v;

		//augmenting the path to s to t while it is possible
		while (bfs())
		{
			minFlow = inf;

			//determine the minimum residual capacity in the path
			v = t-1;
			while (1)
			{
				u = parent[v];
				minFlow = min(minFlow, res[u][v]);
				v = u;
				if (v == 0)
					break;
			}

			//update residual capacity
			v = t-1;
			while (1)
			{
				u = parent[v];
				res[u][v] -= minFlow;
				res[v][u] += minFlow;
				v = u;

				if (v == 0)
					break;
			}

			//update flow
			flow += minFlow;
		}

		return flow;
	}

	void fr()
	{
		for (int i = 0; i < t; i++)
		{
			delete[] res[i];
			delete[] capacity[i];
		}

		delete[] res; delete[] parent;
		delete[] vis; delete[] capacity;
	}
};

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	int b,d,t;
	int u, v, w;

	scanf("%d", &t);

	k = 1;
	while (t--)
	{
		scanf("%d", &n);

		graph g(n);

		for (i = 1; i <= n; i++)
		{
			scanf("%d", &w);
			g.addReg(i, w);
		}

		scanf("%d", &m);

		for (i = 0; i <m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			g.addEdge(u, v, w);
		}

		scanf("%d%d", &b, &d);
		
		for (i = 0; i < b; i++)
		{
			scanf("%d", &v);
			g.supers(0, v);
		}

		m = 2 * n + 1;
		for (i = 0; i < d; i++)
		{
			scanf("%d", &v);
			g.supers(v+n, m);
		}

		printf("Case %d: %d\n", k, g.fordFulkerson()); k++;
		
		g.fr();
	}

	return 0;
}
