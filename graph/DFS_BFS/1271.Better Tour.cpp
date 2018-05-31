#define _CRT_SECURE_NO_WARNINGS

/***from dust i have come, dust i will be***/

#include<algorithm>
#include<cctype>
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
#define pp pair<int,int>
#define N 50100

using namespace std;

bool vis[N];
int parent[N], dist[N];
vector<int> adj[N];

void bfs(int s,int t)
{
	memset(parent, 0, sizeof(parent));
	memset(vis, 0, sizeof(vis));
	memset(dist, 0, sizeof(dist));
	
	queue<int> q;
	
	q.push(s);
	parent[s] = -1;
	dist[s] = 0;

	int e;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		sort(adj[u].begin(), adj[u].end());
		for (int i=0;i<adj[u].size();i++)
		{
			e = adj[u][i];
			if (!vis[e])
				dist[e] = 1 + dist[u], parent[e] = u, q.push(e), vis[e] = 1;
		}

		vis[u] = 1;
	}

	/*for (int i = 1; i <= 5; i++)
		cout << parent[i] << " ";
	nl*/

	stack<int> ss;
	while (t != -1)
	{
		ss.push(t);
		t = parent[t];
	}

	while (1)
	{
		printf("%d", ss.top());
		ss.pop();

		if (ss.size())
			printf(" ");
		else
			break;
	}
}

int main()
{
	freopen("in2.txt","r",stdin);

	int i, j, k;
	int n, m, x;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < N; j++)
			adj[j].clear();

		printf("Case %d:\n", i);
		scanf("%d", &m);

		int *a = new int[m];
		for (j = 0; j < m; j++)
			scanf("%d", &a[j]);

		for (j = 1; j < m; j++)
		{
			adj[a[j]].push_back(a[j - 1]);
			adj[a[j - 1]].push_back(a[j]);
		}

		bfs(a[0], a[m - 1]);
		printf("\n");

		delete[] a;
	}
	
	return 0;
}
