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
#define N 505
#define inf 100000000
#define pp pair<int,int>

using namespace std;

struct edge
{
	int u, v, w;

	//edge() {}
	edge(int a, int b, int c)
	{
		u = a; v = b; w = c;
	}
};

struct edge2
{
	int v, w;

	edge2() {}
	edge2(int a, int b)
	{
		v = a; w = b;
	}
};

class DisjointSetUnion
{
	int n;
	int *p, *r;

public:
	DisjointSetUnion(int x)
	{
		n = x;

		p = new int[n + 1];
		r = new int[n + 1];

		for (int i = 0; i <= n; i++)
			p[i] = i,r[i]=1;
	}

	void Union(int x, int y)
	{
		int a = Find(x);
		int b = Find(y);

		if (r[a]>r[b])
		{
			p[b] = a;
			r[a] += r[b];
		}

		else
		{
			p[a] = b;
			r[b] += r[a];
		}
	}

	int Find(int a)
	{
		if (p[a] == a)
			return a;

		return p[a] = Find(p[a]);
	}

	void fr()
	{
		delete[] p;
		delete[] r;
	}

};

bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

vector<edge2> V[N];
bool vis[N];
int dist[N];

void dfs(int s, int x)
{
	dist[s] = x;

	for (int i = 0; i < V[s].size(); i++)
	{
		if (!vis[V[s][i].v])
		{
			vis[V[s][i].v] = 1;
			//cout << s << " " << V[s][i].v << endl;
			dfs(V[s][i].v, max(V[s][i].w, x));
		}
	}
}

int main()
{
	//freopen("in2.txt", "r", stdin);

	int i, j, k;
	int n, m;
	int t,x;
	int u, v, w;
	
	cin >> t;

	k = 1;
	while (t--)
	{
		printf("Case %d:\n", k); k++;

		//clear everything
		for (i = 0; i < N; i++)
			V[i].clear();

		memset(vis, 0, sizeof(vis));
		memset(dist, inf, sizeof(dist));

		scanf("%d%d", &n, &m);

		DisjointSetUnion dsu(n);
		vector<edge> e;

		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			e.push_back(edge(u, v, w));
		}

		sort(e.begin(), e.end(), cmp);

		for (i = 0; i < m; i++)
		{
			if (dsu.Find(e[i].u) != dsu.Find(e[i].v))
			{
				dsu.Union(e[i].u, e[i].v);
				V[e[i].u].push_back(edge2(e[i].v,e[i].w));
				V[e[i].v].push_back(edge2(e[i].u, e[i].w));
			}

			//cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
		}

		dsu.fr();

		scanf("%d", &x);

		vis[x] = 1;
		dfs(x, 0);

		for (i = 0; i < n; i++)
		{
			if (vis[i])
				printf("%d\n", dist[i]);
			else
				printf("Impossible\n");
		}
	}


	return 0;
}
